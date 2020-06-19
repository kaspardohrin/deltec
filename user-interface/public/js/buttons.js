const morph = {
    'RGB Ledjes': 'RGB',
    '7 Segment Modules': 'SEVEN',
    '8x8 Matrix': 'EIGHT',
    'Rupsbanden': 'RUPS',
    'Wielen': 'WIELEN',
    'Geen': 'NONE',
    'Telefoon': 'PHONE',
}

const title = {
    'RGB': 'Ogen',
    'SEVEN': 'Ogen',
    'EIGHT': 'Ogen',
    'RUPS': 'Bewegen',
    'WIELEN': 'Bewegen',
    'NONE': 'Bewegen',
    'PHONE': 'Camera',
}

let settings = new Array(
    morph['Telefoon'],
)

for (const item of settings) {
    let section = `<div class="control-section" id="${title[item].toLowerCase()}"><h6>${title[item]}</h6></div>`

    $('.side-panel-controls').append(section)

    for (const key in controls[item]) {
        // let button = `<li class="list-inline-item" id="${key}"><abbr title="${key.abbr}"><button id="control" onclick="send(${key})"><img src="./images/${key}.png" alt="${key.alt}"></button></abbr></li>`

        let button = `<li class="list-inline-item ${item.toLowerCase()}" id="${key}"><abbr title="${controls[item][key]['alt']}"><button class="control ${item.toLowerCase()}" id="${key}" onclick="send('${key}')"><img src="./images/look-normal.png" alt="${controls[item][key]['abbr']}"></button></abbr></li>`

        $(`#${title[item].toLowerCase()}`).append(button)
    }
}