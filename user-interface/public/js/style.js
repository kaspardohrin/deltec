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
        put_button_left()
    } else {
        $('.navbar-brand.controls').attr('id', 'navbar-controls')

        $('.side-panel-controls').css("display", "none")
        $('.side-panel-options').css("display", "none")
        $('.side-panel-notes').css("display", "none")

        $('button.open').css("display", "block")

        $('iframe').css("grid-column-end", "6")
        put_button_right()
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
        put_button_left()
    } else {
        $('.navbar-brand.options').attr('id', 'navbar-options')

        $('.side-panel-options').css("display", "none")
        $('.side-panel-controls').css("display", "none")
        $('.side-panel-notes').css("display", "none")

        $('button.open').css("display", "block")

        $('iframe').css("grid-column-end", "6")
        put_button_right()
    }
 })

$('.navbar-brand.notes').on('click', function () {

    if ($('#navbar-notes')[0]) {
        $('.navbar-brand.notes').attr('id', 'navbar-notes-active')
        $('.navbar-brand.options').attr('id', 'navbar-options')
        $('.navbar-brand.controls').attr('id', 'navbar-controls')

        $('.side-panel-notes').css("display", "block")
        $('.side-panel-options').css("display", "none")
        $('.side-panel-controls').css("display", "none")

        $('button.open').css("display", "none")

        $('iframe').css("grid-column-end", "4")

        lastopened = 'notes'
        put_button_left()
    } else {
        $('.navbar-brand.notes').attr('id', 'navbar-notes')

        $('.side-panel-notes').css("display", "none")
        $('.side-panel-options').css("display", "none")
        $('.side-panel-controls').css("display", "none")

        $('button.open').css("display", "block")

        $('iframe').css("grid-column-end", "6")
        put_button_right()
    }
 })

 $('button.close').on('click', function () {
    $('.navbar-brand.notes').attr('id', 'navbar-notes')
    $('.navbar-brand.options').attr('id', 'navbar-options')
    $('.navbar-brand.controls').attr('id', 'navbar-controls')

    $('.side-panel-notes').css("display", "none")
    $('.side-panel-options').css("display", "none")
    $('.side-panel-controls').css("display", "none")

    $('button.open').css("display", "block")

    $('iframe').css("grid-column-end", "6")
    put_button_right()
 })

 $('button.open').on('click', function () {
    if (lastopened === 'controls') {
        $('.navbar-brand.controls').attr('id', 'navbar-controls-active')
        $('.side-panel-controls').css("display", "block")
    }
    else if (lastopened === 'options') {
        $('.navbar-brand.options').attr('id', 'navbar-options-active')
        $('.side-panel-options').css("display", "block")
    }
    else if (lastopened === 'notes') {
        $('.navbar-brand.notes').attr('id', 'navbar-notes-active')
        $('.side-panel-notes').css("display", "block")
    } else {
        $('.navbar-brand.options').attr('id', 'navbar-options-active')
        $('.side-panel-options').css("display", "block")
    }

    $('button.open').css("display", "none")

    $('iframe').css("grid-column-end", "4")
    put_button_left()
 })
})

function put_button_left() {
    if (window.matchMedia("(orientation: portrait)").matches) {
        $('button.raise-hand').css("left", "calc(100vw - 45vw + ((45vw - 130px) / 2))")

    } else if (window.matchMedia("(orientation: landscape)").matches && window.innerHeight < 679) {
        $('button.raise-hand').css("left", "calc(50vw + 65px - 40vw - 5vh)")
        console.log(`scale`)

    } else {
        $('button.raise-hand').css("left", "calc(50vw - 75px - (350px+3vw)/2)") 
    }
}

function put_button_right() {
    if (window.matchMedia("(orientation: portrait)").matches) {
        $('button.raise-hand').css("left", "calc(50vw - 65px)")

    } else if (window.matchMedia("(orientation: landscape)").matches && window.innerHeight < 679) {
        $('button.raise-hand').css("left", "calc(50vw - 65px)")

    } else {
        $('button.raise-hand').css("left", "calc(50vw - 75px)")
    }
}