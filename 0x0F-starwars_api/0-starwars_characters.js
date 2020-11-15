#!/usr/bin/node
const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];
request(url, function (err, res, body) {
  if (err) console.log(err);
  else if (res.statusCode === 200) {
    const characters = JSON.parse(body).characters;
    for (let i = 0; i < characters.length; i++) {
      request(characters[i], function (error, resp, body2) {
        if (error) console.log(error);
        console.log(JSON.parse(body2).name);
      });
    }
  }
});
