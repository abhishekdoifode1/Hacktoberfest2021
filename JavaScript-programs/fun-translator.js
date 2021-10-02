//program to translate english to yoda language using fun translation API.
//The API only allows 5 requests per hour

let url = "https://api.funtranslations.com/translate/yoda.json?text=";

function translateText(text) {
  fetch(url+text)
  .then(response => response.json())
  .then(data => console.log(data.contents.translated))
  .catch(err => console.log(`Error occured : ${err}`));
}

translateText("Hi how are you");
