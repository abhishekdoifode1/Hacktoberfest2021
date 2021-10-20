const request = require('request')

const geocode = (address, callback) => {
    const url = 'https://api.mapbox.com/geocoding/v5/mapbox.places/' + encodeURIComponent(address) + '.json?access_token=pk.eyJ1IjoibWFsaW5kdTk3IiwiYSI6ImNraGRpd3BmYTA3b2oyeW9mZnI0dnpkZTkifQ.56EtgfScycbivluGOc3Rwg&limit=1'

    request({ url, json: true}, (error, { body }) => {
        if(error) {
            callback('Unable to connect location sevices!', undefined)
        } else if (body.features.length == 0) {
            callback('Unable to find location. Find another search!', undefined)
        } else {
            callback(undefined, {
                latitude: body.features[0].center[1],
                longitude: body.features[0].center[0],
                location: body.features[0].place_name
            })
        }
    })
}

module.exports = geocode