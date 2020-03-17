<!DOCTYPE html>
<html lang="nl">
<!-- import head -->
<?php
include_once 'includes/head.html'
?>

<body>
    <!-- navbar -->
    <?php
    include_once 'includes/navbar.html';
    ?>

    <!-- content -->
    <main>
        <!-- Picture -->
        <div class="image_large">
            <img class="responsive-img" alt="" src="images/banner.jpg">
        </div>

        <!-- Welkom -->
        <div class="row">
            <div class="col s12 m10 l8 offset-m1 offset-l2">
                <div class="col s12 m3 l5 center-align">
                    <!-- Picture -->
                    <img class="responsive-img" style="max-height: 400px;" alt="" src="images/logos/Deltec_UHD_transparant.png">
                </div>
                <div class="col s12 m9 l7">
                    <!-- Text -->
                    <h4>Deltec robot</h4>
                    <br>
                    <p>Lorem ipsum you know the drill.
                    </p>
                    <br>
                    <p>Bla bla bla bla
                    </p>
                </div>
            </div>
        </div>

        <!-- Mogelijkheden -->
        <div class="row z-depth-1 homebar blue1background">
            <div class="col s10 offset-s1 center-align">
                <h2>Mogelijkheden</h2>
            </div>
            <div class="col s10 offset-s1 center-align">
                <div class="row grey lighten-4">
                    <div class="col s12 m3 z-depth-1 infobox">
                        <h5>Communiceer</h5>
                        <img class="responsive-img" src="images/Mill_Type2_CNC.svg">
                        <h6>Tweewegs communicatie met beeld en geluid</h6>
                    </div>
                    <div class="col s12 m3 z-depth-1 infobox">
                        <h5>Bestuur</h5>
                        <img class="responsive-img" src="images/Mill_Type2_Graveren.svg">
                        <h6>Controleer de robot via de app</h6>
                    </div>
                    <div class="col s12 m3 z-depth-1 infobox">
                        <h5>Deel</h5>
                        <img class="responsive-img" src="images/Mill_Type2_Laser.svg">
                        <h6>Deel gemakkelijk je scherm en je werk</h6>
                    </div>
                    <div class="col s12 m3 z-depth-1 infobox">
                        <h5>Emotie</h5>
                        <img class="responsive-img" src="images/PCB.svg">
                        <h6>Projecteer jouw emoties op de robot</h6>
                    </div>
                </div>
            </div>
        </div>
        <!-- Historie info -->
        <div class="row z-depth-1 homebar valign-wrapper">
            <div class="col s8 offset-s2 ">
                <div class="col s8">
                    <h5>Tiel</h5>
                    <h6 class="grey-text text-darken-3">
                        Hier kan een stukje over bijvoobeeld de historie staan van dit project.<br><br>
                        Lorem Ipsum is simply dummy text of the printing and typesetting industry. 
                        Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, 
                        when an unknown printer took a galley of type and scrambled it to make a type specimen book. 
                        It has survived not only five centuries, but also the leap into electronic typesetting, 
                        remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, 
                        and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.
                    </h6>
                </div>
                <div class="col s4 center-align">
                    <!-- Picture -->
                    <img class="responsive-img" style="max-height: 300px;" alt="" src="images/logos/Deltec_UHD_transparant.png">
                </div>
            </div>
        </div>
        <!-- Info -->
        <div class="row z-depth-1 homebar blue2background">
            <div class="col s10 offset-s1 center-align">
                <h2>TITEL</h2>
            </div>
            <div class="col s10 offset-s1 center-align">
                <div class="row grey lighten-4">
                    <div class="col s4 z-depth-1 infobox center-align">
                        <h5>Info titel</h5>
                        <img class="responsive-img circle" style="max-height: 300px;" src="images/logos/Deltec_alt_UHD_transparant.png">
                        <h6>Uitleg wat dit is in 1 zin</h6>
                    </div>
                    <div class="col s4 z-depth-1 infobox">
                        <h5>Info titel</h5>
                        <img class="responsive-img circle" style="max-height: 300px;" src="images/logos/Deltec_alt_UHD_transparant.png">
                        <h6>Uitleg wat dit is in 1 zin</h6>
                    </div>
                    <div class="col s4 z-depth-1 infobox">
                        <h5>Info titel</h5>
                        <img class="responsive-img circle" style="max-height: 300px;" src="images/logos/Deltec_alt_UHD_transparant.png">
                        <h6>Uitleg wat dit is in 1 zin</h6>
                    </div>
                </div>
                <div class="row grey lighten-4">
                    <div class="col s4 z-depth-1 infobox">
                        <h5>Info titel</h5>
                        <img class="responsive-img circle" style="max-height: 300px;" src="images/logos/Deltec_alt_UHD_transparant.png">
                        <h6>Uitleg wat dit is in 1 zin</h6>
                    </div>
                    <div class="col s4 z-depth-1 infobox">
                        <h5>Info titel</h5>
                        <img class="responsive-img circle" style="max-height: 300px;" src="images/logos/Deltec_alt_UHD_transparant.png">
                        <h6>Uitleg wat dit is in 1 zin</h6>
                    </div>
                    <div class="col s4 z-depth-1 infobox">
                        <h5>Info titel</h5>
                        <img class="responsive-img circle" style="max-height: 300px;" src="images/logos/Deltec_alt_UHD_transparant.png">
                        <h6>Uitleg wat dit is in 1 zin</h6>
                    </div>
                </div>
            </div>
        </div>
        <!-- Spacer segment -->
        <div class="row small_spacer blue1background"></div>
    </main>

    <!-- footer -->
    <?php
    include_once 'includes/footer.html';
    ?>

    <!-- Jquery via CDN and verify it has not been tampered with -->
    <script src="https://code.jquery.com/jquery-3.4.1.min.js" integrity="sha256-CSXorXvZcTkaix6Yvo6HppcZGetbYMGWSFlBw8HfCJo=" crossorigin="anonymous"></script>
    <!-- Compiled and minified JavaScript -->
    <script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/js/materialize.min.js"></script>
    <!-- scripts -->
    <script type="text/javascript" src="js/scripts.js"></script>
</body>
</html>