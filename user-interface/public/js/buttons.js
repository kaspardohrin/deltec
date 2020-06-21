const morph = {
    'RGB Ledjes': 'RGB',
    '7-Segment Modules': 'SEVEN',
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

let getUrlParameter = (sParam) => {
    let sPageURL = window.location.search.substring(1),
        sURLletiables = sPageURL.split('&'),
        sParameterName,
        i

    for (i = 0; i < sURLletiables.length; i++) {
        sParameterName = sURLletiables[i].split('=')

        if (sParameterName[0] === sParam) {
            return sParameterName[1] === undefined ? true : decodeURIComponent(sParameterName[1])
        }
    }
}

const parse = (string) => {
    if (string) return string.replace('+', ' ')
}

let settings = new Array(
    morph['Telefoon'],
    morph[parse(getUrlParameter('eyes'))],
    morph[parse(getUrlParameter('wheels'))],
)

for (const item of settings) {
    let section = `<div class="control-section" id="${title[item].toLowerCase()}"><h6>${title[item]}</h6></div>`

    $('.side-panel-controls').append(section)

    for (const key in controls[item]) {
        let button = `<li class="list-inline-item ${item.toLowerCase()}" id="${key}"><abbr title="${controls[item][key]['abbr']}"><button class="control ${item.toLowerCase()}" id="${key}" onclick="send('${key}')" type="checkbox"><img src="./images/${key}.svg" alt="${controls[item][key]['alt']}"></button></abbr></li>`

        $(`#${title[item].toLowerCase()}`).append(button)
    }
}

