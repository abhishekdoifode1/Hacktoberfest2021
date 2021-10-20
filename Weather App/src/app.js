const path = require('path')
const express = require('express')
const hbs = require('hbs')
const geocode = require('./utils/geocode')
const forecast = require('./utils/forecast')

// console.log(__dirname)
// console.log(__filename)
// console.log(path.join(__dirname, '../public'))

const app = express()

const port = process.env.PORT || 3000
    // port will be equal to environment variable port

// Define paths for Express config
const publicDirectoryPath = path.join(__dirname, '../public')
const viewsPath = path.join(__dirname, '../templates/views')
const partialsPath = path.join(__dirname, '../templates/partials')

// Setup handlebars engine and views location
app.set('view engine', 'hbs')
app.set('views', viewsPath)
hbs.registerPartials(partialsPath)

// Setup static directory to serve
app.use(express.static(publicDirectoryPath))

app.get('', (req, res) => {
    res.render('index', {
        title: 'Weather',
        name: 'Malindu Sasanga'
    })
})

app.get('/about', (req, res) => {
    res.render('about', {
        title: 'About me',
        name: 'Malindu Sasanga'
    })
})

app.get('/help', (req, res) => {
    res.render('help', {
        helpText: 'Hey I am here to help you!',
        title: 'Help',
        name: 'Malindu Sasanga'

    })
})

// app.get('', (req, res) => { // funciton does what want to be done when somewone visits the site
//     res.send('<h1>Weather</h1>')
// }) 

// app.get('/help', (req, res) => {
//     res.send([{
//         name: 'Andrew',
//         age: 23
//     }, {
//         name: 'Sarah',
//         age: 23
//     }])
// })

// app.get('/about', (req, res) => {
//     res.send('<h1>Welcome to About page!</h1>')
// })

app.get('/weather', (req, res) => {
    if (!req.query.address) {
        return res.send({
            error: 'You must provide a location'
        })
    }

    geocode(req.query.address, (error, { latitude, longitude, location } = {}) => {
            if (error) {
                return res.send({ error })
            }

            forecast(latitude, longitude, (error, forecastData) => {
                if (error) {
                    return res.send({ error })
                }

                res.send({
                    forecast: forecastData,
                    location,
                    address: req.query.address
                })
            })
        })
        // res.send({
        //     weather: {
        //         forecast: 'Rainy',
        //         location: 'Colombo',
        //         address: req.query.address
        //     }
        // })
})

app.get('/products', (req, res) => {
    if (!req.query.search) {
        return res.send({
            error: 'You must provide a search terms'
        })
    }
    console.log(req.query.search)
    res.send({
        prodcts: []
    })
})

app.get('/help/*', (req, res) => {
    res.render('404', {
        title: '404',
        name: 'Malindu Sasanga',
        errorMessage: 'Help aticle not found!'
    })
})

app.get('*', (req, res) => {
    res.render('404', {
        title: '404',
        name: 'Malindu Sasanga',
        errorMessage: 'Page not found'
    })
})

app.listen(port, () => {
    console.log('Server is up on port ' + port)
})