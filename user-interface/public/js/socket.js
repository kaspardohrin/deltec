const url = 'ws://86.88.80.96:1337';
let connection;

// Set up a new websocket with an ESP32
// websocketSetup();

function websocketSetup() {
    connection = new WebSocket(url);
    connection.onopen = function(evt) { onOpen(evt) };
    connection.onmessage = function(evt) { onMessage(evt) };
    connection.onerror = function(evt) { onError(evt) };
    connection.onclose = function(evt) { onClose(evt) };
}
// Called when a WebSocket connection is established with the server
function onOpen(evt) {
    console.log(evt)
}

function onMessage(evt) {
    console.log(evt.data)
}
// Called when a WebSocket error occurs
function onError(evt) {
    console.log("ERROR: " + evt.data);
}
// Called when the WebSocket connection is closed
function onClose(evt) {
    // Log disconnection state
    console.log("Disconnected");
    // Try to reconnect after a few seconds
    setTimeout(function() { websocketSetup(url) }, 2000);
}

function send(action) {
    // connection.send(action)
}