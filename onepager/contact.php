<!DOCTYPE html>
<html lang="nl">
    <head>
        <!-- Info for the browser -->
        <meta charset="utf-8">
        <!--Let browser know website is optimized for mobile-->
        <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
        <!-- Import Google Icon Font -->
        <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
        <!-- Import Google font -->
        <link href="https://fonts.googleapis.com/css?family=Montserrat:900|Work+Sans:300" rel="stylesheet">
        <!-- Compiled and minified CSS -->
        <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css">
        <!-- My CSS -->
        <link rel="stylesheet" type="text/css" href="css/style.css">

        <!-- Website Title -->
        <title>Title</title>
        <!-- Icon -->
        <link rel="icon" href="images/Favicon.ico">
    </head>

    <body>
        <!-- navbar -->
        <?php
        include_once 'includes/navbar.html';
        ?>

        <!-- content -->
        <main>
            <!-- Spacer segment -->
            <div class="row small_spacer blue1background"></div>
                        
            <!-- Contact -->
            <div class="row z-depth-1 homebar blue1background">
                <div class="row col s12 m10 l6 offset-m1 offset-l3 z-depth-2 white">
                    <div class="row">
                        <div class="col s12 m6">
                            <h2 class="black-text bold hide-on-small-only">CONTACT</h2>
                            <h3 class="black-text center bold hide-on-med-and-up">CONTACT</h3><!-- mobile -->
                            <h4 class="black-text hide-on-small-only">Ik hoor graag van je</h4>
                            <h6 class="black-text center hide-on-med-and-up">Ik hoor graag van je</h6><!-- mobile -->
                            <br>
                            <div class="center">
                                <a href="https://www.facebook.com/roel.versteeg" rel="noopener noreferrer" target="_blank"><img class="socialicons" src="images/logos/icon_facebook.svg"></a>
                                <a href="https://www.youtube.com/user/roel0099" rel="noopener noreferrer" target="_blank"><img class="socialicons" src="images/logos/icon_youtube.svg"></a>
                                <a href="https://www.instagram.com/roelversteeg/" rel="noopener noreferrer" target="_blank"><img class="socialicons" src="images/logos/icon_instagram.svg"></a>
                                <a href="https://twitter.com/Roel_Versteeg" rel="noopener noreferrer" target="_blank"><img class="socialicons" src="images/logos/icon_twitter.svg"></a>
                                <a href="https://www.linkedin.com/in/roel-v-a66773124/" rel="noopener noreferrer" target="_blank"><img class="socialicons" src="images/logos/icon_linkedin.svg"></a>
                                <a href="https://github.com/Rovexx" rel="noopener noreferrer" target="_blank"><img class="socialicons" src="images/logos/icon_github.svg"></a>
                            </div>
                        </div>
                        <div class="col s12 m6 center">
                            <br><br><br><br><br><br>
                            <a class="waves-effect waves-light btn-large blue3background" href="images/bestanden/CV_Roel_Versteeg.pdf" download>Download CV</a>
                            <br><br>
                            <a class="col s12 blue2 bold" href="mailto:________@hotmail.com" >________@hotmail.com</a>
                        </div>
                    </div>
                </div>
            </div>

            <!-- Spacer segment -->
            <div class="row small_spacer blue2background"></div>
        </main>

        <!-- footer -->
        <?php
        include_once 'includes/footer.html';
        ?>

        <!-- Jquery and verify it has not been tampered with -->
        <script src="https://code.jquery.com/jquery-3.3.1.min.js"
            integrity="sha256-FgpCb/KJQlLNfOu91ta32o/NMZxltwRo8QtmkMRdAu8="
            crossorigin="anonymous">
        </script>
        <!-- Compiled and minified JavaScript -->
        <script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/js/materialize.min.js"></script>
        <!-- script for waypoints -->
        <script type="text/javascript" src="js/jquery.waypoints.min.js"></script>
        <!-- scripts -->
        <script type="text/javascript" src="js/scripts.js"></script>
    </body>
</html>