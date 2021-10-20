const request = require('request')

const forecast = (location, callback) => {
    const url = 'http://api.weatherstack.com/current?access_key=28fbc2383faf6e7f5ef1f201c994ed83&query=' + encodeURIComponent(location) + '?language=si'

    request({ url, json: true }, (error, { body }) => {
        if (error) {
            callback('Unable to connect location sevices!', undefined)
        } else if (body.error) {
            callback('Unable to find location. Find another search!', undefined)
        } else {
            callback(undefined, 'It is currently ' + body.current.temperature +
                    ' degress out. There is a ' + body.currently.precipProbability + '% chance of rain.')
                // {
                // latitude: response.body.features[0].center[0],
                // longitude: response.body.features[0].center[1],
                // location: response.body.features[0].place_name

            // location: response.body.location.name,
            // tempterature: response.body.current.temperature
            // })
        }
    })
}

module.exports = forecast