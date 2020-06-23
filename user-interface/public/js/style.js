let lastopened = ''

window.addEventListener("resize", function() {
    if ($('#navbar-controls-active')[0] || $('#navbar-notes-active')[0] || $('#navbar-options-active')[0] ) {
        scale_iframe()
        put_button_left()
    } else {
        default_iframe()
        put_button_right()
    }
}, false)

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

        scale_iframe()

        lastopened = 'controls'
        put_button_left()
    } else {
        $('.navbar-brand.controls').attr('id', 'navbar-controls')

        $('.side-panel-controls').css("display", "none")
        $('.side-panel-options').css("display", "none")
        $('.side-panel-notes').css("display", "none")

        $('button.open').css("display", "block")

        default_iframe()
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

        scale_iframe()

        lastopened = 'options'
        put_button_left()
    } else {
        $('.navbar-brand.options').attr('id', 'navbar-options')

        $('.side-panel-options').css("display", "none")
        $('.side-panel-controls').css("display", "none")
        $('.side-panel-notes').css("display", "none")

        $('button.open').css("display", "block")

        default_iframe()
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

        scale_iframe()

        lastopened = 'notes'
        put_button_left()
    } else {
        $('.navbar-brand.notes').attr('id', 'navbar-notes')

        $('.side-panel-notes').css("display", "none")
        $('.side-panel-options').css("display", "none")
        $('.side-panel-controls').css("display", "none")

        $('button.open').css("display", "block")

        default_iframe()
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

    default_iframe()
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

    scale_iframe()
    put_button_left()
 })
})

function put_button_left() {
    if (window.matchMedia("(orientation: portrait)").matches && window.innerWidth < 679) {
        $('button.raise-hand').css("left", "calc(55vw - 120px)")

    } else if (window.matchMedia("(orientation: landscape)").matches && window.innerHeight < 679) {
        $('button.raise-hand').css("left", "calc(55vw - 110px)")

    } else {
        $('button.raise-hand').css("left", "calc((100vw - 350px - 3vw) / 2 - 75px)") 
    }
}

function put_button_right() {
    if (window.matchMedia("(orientation: portrait)").matches && window.innerWidth < 679) {
        $('button.raise-hand').css("left", "calc(50vw - 55px)")

    } else if (window.matchMedia("(orientation: landscape)").matches && window.innerHeight < 679) {
        $('button.raise-hand').css("left", "calc(50vw - 55px)")

    } else {
        $('button.raise-hand').css("left", "calc(50vw - 75px)")
    }
}

function default_iframe() {
    if (window.matchMedia("(orientation: portrait)").matches && window.innerWidth < 679) {
        $('iframe').css("grid-column-end", "6")

    } else if (window.matchMedia("(orientation: landscape)").matches && window.innerHeight < 679) {
        $('iframe').css("grid-column-end", "6")

    } else {
        $('iframe').css("grid-column-end", "6")
    }
}

function scale_iframe() {
    if (window.matchMedia("(orientation: portrait)").matches && window.innerWidth < 679) {
        $('iframe').css("grid-column-end", "6")

    } else if (window.matchMedia("(orientation: landscape)").matches && window.innerHeight < 679) {
        $('iframe').css("grid-column-end", "6")

    } else {
        $('iframe').css("grid-column-end", "4")
    }
}