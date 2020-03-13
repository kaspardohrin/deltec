#include <WiFi.h>
#include <TM1637Display.h>
#include <ESP32Servo.h>
#include <WebSocketsServer.h>

// TM1637 7 Segment Module connection pins
#define SEGMENT_1_DIN 15
#define SEGMENT_2_DIN 4
#define SEGMENT_CLK 5
// Servo pin
#define SERVO_PIN 18
// Relay pins
#define LEFT_MOTOR_RELAY_PIN 19
#define RIGHT_MOTOR_RELAY_PIN 21

// const char* ssid = "Wifi name";
// const char* password = "Pass here";
const char* ssid = "Arvex_Fiber_2G";          // Wifi name
const char* password = "Kluitenruif@25";      // Wifi password
const uint16_t port = 1338;                   // Ip port
// Static ip
IPAddress local_IP(192, 168, 1, 207);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(1, 1, 1, 1);   //optional
IPAddress secondaryDNS(1, 0, 0, 1); //optional

// Variables for main code
bool idleEyes = true;                         // Should the eyes have changing random animations
bool idleTail = true;                         // Should the tail have changing random animations

uint16_t intervalBlink = 4000;                // Time between blinks
uint16_t intervalIdleEyes = 5000;             // Time between idle movement eyes
uint16_t intervalIdleTail = 6000;             // Time between idle movement tail
uint16_t intervalMovement = 5000;             // Duration of move

unsigned long previousMillisBlink = 0;        // Time last blink was done
unsigned long previousMillisIdleEyes = 0;     // Time last idle move was done
unsigned long previousMillisIdleTail = 0;     // Time last idle move was done
unsigned long previousMillisMovement = 0;     // Time last idle move was done

unsigned long currentMillis = 0;              // Current time

uint8_t nextIdleMovementEyes = 0;             // Next idle movement to do
uint8_t nextIdleMovementTail = 0;             // Next idle movement to do

enum Direction { IDLE, FORWARD, LEFT, RIGHT, UNDEF};
bool driving = false;                         // Should the robot move (value changed when recieving command via websocket)
int moveDirection = IDLE;                     // Current move direction of the robot
int moveDirectionPrevious = UNDEF;            // Previous move direction. Used for checking if the state should change, prevents unnecessary movement on motors

WebSocketsServer webSocket = WebSocketsServer(port);

// Called when receiving any WebSocket message
void onWebSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
  // Figure out the type of WebSocket event
  switch(type) {
 
    // Client has disconnected
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", num);
      break;
 
    // New client has connected
    case WStype_CONNECTED:
      {
        IPAddress ip = webSocket.remoteIP(num);
        Serial.printf("[%u] Connection from ", num);
        Serial.println(ip.toString());
      }
      Serial.println("Websocket open");
      break;
 
    // Echo text message back to client
    case WStype_TEXT:
      // Serial.printf("[%u] Text: %s\n", num, payload);
      handleRecieved((const char*)payload);
      // Send recieved back for debugging
      webSocket.sendTXT(num, payload);
      break;
 
    // For everything else: do nothing
    case WStype_BIN:
    case WStype_ERROR:
    case WStype_FRAGMENT_TEXT_START:
    case WStype_FRAGMENT_BIN_START:
    case WStype_FRAGMENT:
    case WStype_FRAGMENT_FIN:
    default:
      break;
  }
}