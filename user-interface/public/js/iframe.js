$(document).ready(() => {
    $('iframe').css('display', 'none')
})

async function iframe() {
    callFrame = window.DailyIframe.createFrame({
        showFullscreenButton: true,
        showLeaveButton: true,
    })

    await callFrame.join({ url: 'https://deltec.daily.co/ello' })

    // $('.loading').remove()
    $('iframe').css({
        'display': 'block',
        'position': 'relative',
        'border': '1px solid black',
        'width': '100%',
        'height': '100%',
        'top': 0,
        'bottom': 0,
        'left': 0,
        'right': 0,
    })
}