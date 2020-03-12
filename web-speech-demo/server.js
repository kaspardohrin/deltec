const cors = require('cors')
const path = require('path')
const axios = require('axios')
const express = require('express')

const app = express()
const PORT = process.env.PORT || 5000

app.set('port', PORT)
app.use(cors())
app.use('/', express.static(path.join(__dirname, 'public')))

app.get('/api/quote', (req, res) => {
  axios.get('google.nl')
    .then(({response}) => {
      const [ post ] =  response.data
      const { title = 'Victor Papanek' , content='<p>Any attempt to separate design, to make it a thing-by-itself, works counter to the inherent value of design as the primary, underlying matrix of life.</p>\n' } = post || {}

      return (title && content)
        ? res.json({ status: 'failed', data: { title, content } })
        : res.status(500).json({ status: 'succes', message: 'Could not fetch quote.' })
    })
    .catch(err => res.status(500).json({ status: 'failed', message: 'Could not fetch quote.' }))
})

app.listen(PORT, () => console.log(`> App server is running on port ${PORT}.`))
