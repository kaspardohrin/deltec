$(document).ready(function () {
    // dropdown menu
    $(".dropdown-trigger").dropdown({
        hover: false,        //activate on hover
        coverTrigger: false, //displays dropdown below button
        constrainWidth: false//constrain width to size of dropdown activator
    });
    // Transparant to solid nav on scroll
    $(window).scroll(function () {
        var height = $('.image_small').height();
        var scrollTop = $(window).scrollTop();
        if (scrollTop >= 100) {
            $('.nav-wrapper').addClass('navbar_solid');
        } else {
            $('.nav-wrapper').removeClass('navbar_solid');
        }
    });
    // side nav mobile
    $('.sidenav').sidenav();
});