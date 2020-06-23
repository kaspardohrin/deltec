let notes = [
    `<div class="notes-section"><button class="note" onclick="destroy(this)"><img src="./images/delete.svg" title="Verwijder"></button><li class="list-inline-item" style="top: 0;">Userstories:<br>-Als gebruiker wil ik notities aanmaken in de UI, zodat ik makkelijk terug kan zien wat ik de vorige keer heb gemaakt<br><sub><i>9:45 17-5-2020</i></sub></li></div>`,
    `<div class="notes-section"><button class="note" onclick="destroy(this)"><img src="./images/delete.svg" title="Verwijder"></button><li class="list-inline-item" style="top: 0;">Hoofdstuk 14 - pagina 97: Goed doorlezen<br><sub><i>11:02 17-5-2020</i></sub></li></div>`,
]

let date = `${new Date().getHours()}:${new Date().getMinutes()} ${new Date().getDate()}-${new Date().getMonth()}-${new Date().getFullYear()}`

let section = `<div class="notes-section"></div>`

for (const item of notes) {
    $('.all-notes').append(item)
}

$(document).ready( () => {
    $('#notes-button').on('click', function () {
        const value = $('#notes-form')[0].value.replace('\n', '<br>')

        if (!value) return

        $('#notes-form').val('')

        const note = `<div class="notes-section"><button class="note" onclick="destroy(this)"><img src="./images/delete.svg" title="Verwijder"></button><li class="list-inline-item" style="top: 0;">${value}<br><sub><i>${date}</i></sub></li></div>`

        $('.all-notes').prepend(note)
        notes.push(note)
    })
})

function destroy(note) {
    $(note).parent().remove()
}