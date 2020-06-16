$(document).ready( () => {
 $('.navbar-brand.controls').on('click', function () {

    if ($('#navbar-controls')[0]) {
        $('.navbar-brand.options').attr('id', 'navbar-options')
        $('.navbar-brand.controls').attr('id', 'navbar-controls-active')
        $('.side-panel').css("display", "block")
        $('iframe').css("grid-column-end", "4")
    } else {
        $('.navbar-brand.controls').attr('id', 'navbar-controls')
        $('.side-panel').css("display", "none")
        $('iframe').css("grid-column-end", "6")
    }
 })

 $('.navbar-brand.options').on('click', function () {

    if ($('#navbar-options')[0]) {
        $('.navbar-brand.controls').attr('id', 'navbar-controls')
        $('.navbar-brand.options').attr('id', 'navbar-options-active')
        $('.side-panel').css("display", "block")
        $('iframe').css("grid-column-end", "4")
    } else {
        $('.navbar-brand.options').attr('id', 'navbar-options')
        $('.side-panel').css("display", "none")
        $('iframe').css("grid-column-end", "6")
    }
 })
})