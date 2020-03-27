$(document).ready(function() {
    document.getElementsByTagName('iframe')[0].setAttribute("style", "display: none;")
})

function iframe() {
    document.getElementsByTagName('iframe')[0].setAttribute("style", "position: static; border: 1px solid black; background-color: white; height: 100%; width: 100%;")
}