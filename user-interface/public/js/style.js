let lastopened = ''

$(document).ready( () => {
 $('.navbar-brand.controls').on('click', function () {

    if ($('#navbar-controls')[0]) {
        $('.navbar-brand.controls').attr('id', 'navbar-controls-active')
        $('.navbar-brand.options').attr('id', 'navbar-options')
        $('.navbar-brand.notes').attr('id', 'navbar-notes')

        $('.side-panel-controls').css("display", "block")
        $('.side-panel-options').css("display", "none")
        $('.side-panel-notes').css("display", "none")

        $('button.open').css("display", "none")

        $('iframe').css("grid-column-end", "4")

        lastopened = 'controls'
    } else {
        $('.navbar-brand.controls').attr('id', 'navbar-controls')

        $('.side-panel-controls').css("display", "none")
        $('.side-panel-options').css("display", "none")
        $('.side-panel-notes').css("display", "none")

        $('button.open').css("display", "block")

        $('iframe').css("grid-column-end", "6")
    }
 })

 $('.navbar-brand.options').on('click', function () {

    if ($('#navbar-options')[0]) {
        $('.navbar-brand.options').attr('id', 'navbar-options-active')
        $('.navbar-brand.controls').attr('id', 'navbar-controls')
        $('.navbar-brand.notes').attr('id', 'navbar-notes')

        $('.side-panel-options').css("display", "block")
        $('.side-panel-controls').css("display", "none")
        $('.side-panel-notes').css("display", "none")

        $('button.open').css("display", "none")

        $('iframe').css("grid-column-end", "4")

        lastopened = 'options'
    } else {
        $('.navbar-brand.options').attr('id', 'navbar-options')

        $('.side-panel-options').css("display", "none")
        $('.side-panel-controls').css("display", "none")
        $('.side-panel-notes').css("display", "none")

        $('button.open').css("display", "block")

        $('iframe').css("grid-column-end", "6")
    }
 })

$('.navbar-brand.notes').on('click', function () {

    if ($('#navbar-notes')[0]) {
        $('.navbar-brand.notes').attr('id', 'navbar-notes-active')
        $('.navbar-brand.option').attr('id', 'navbar-controls')
        $('.navbar-brand.controls').attr('id', 'navbar-controls')

        $('.side-panel-notes').css("display", "block")
        $('.side-panel-options').css("display", "none")
        $('.side-panel-controls').css("display", "none")

        $('button.open').css("display", "none")

        $('iframe').css("grid-column-end", "4")

        lastopened = 'notes'
    } else {
        $('.navbar-brand.notes').attr('id', 'navbar-notes')

        $('.side-panel-notes').css("display", "none")
        $('.side-panel-options').css("display", "none")
        $('.side-panel-controls').css("display", "none")

        $('button.open').css("display", "block")

        $('iframe').css("grid-column-end", "6")
    }
 })

 $('button.close').on('click', function () {
    $('.side-panel-notes').css("display", "none")
    $('.side-panel-options').css("display", "none")
    $('.side-panel-controls').css("display", "none")

    $('button.open').css("display", "block")

    $('iframe').css("grid-column-end", "6")
 })

 $('button.open').on('click', function () {
    if (lastopened === 'controls') {
        $('.side-panel-controls').css("display", "block")
    }
    else if (lastopened === 'options') {
        $('.side-panel-options').css("display", "block")
    }
    else if (lastopened === 'notes') {
        $('.side-panel-notes').css("display", "block")
    } else {
        $('.side-panel-options').css("display", "block")
    }

    $('button.open').css("display", "none")

    $('iframe').css("grid-column-end", "4")
 })
})