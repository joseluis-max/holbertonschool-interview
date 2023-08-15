#!/usr/bin/node
const request = require('request');
const req = require('sync-request');
const url = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`;

request(url, (err, res, body) => {
  if (!err) {
    body = JSON.parse(body);
    body.characters.forEach(url => {
      let result = req('GET', url);
      result = JSON.parse(result.getBody('utf8'));
      console.log(result.name);
    });
  } else {
    console.log(err);
  }
});
