
function processWord(encryptedWord){
    let splitedText = (encryptedWord.toLowerCase()).split("");
    let cenit = ["c", "e", "n", "i", "t"];
    var polar = ["p", "o", "l", "a", "r"];
    var encryptWordArray = [];
    splitedText.map(function(i) {
      if (cenit.indexOf(i) > -1) {
        i = polar[cenit.indexOf(i)];
        encryptWordArray.push(i);
      } else if (polar.indexOf(i) > -1) {
        i = cenit[polar.indexOf(i)];
        encryptWordArray.push(i);
      } else {
        encryptWordArray.push(i);
      }
    });
    return encryptWordArray.join("").toUpperCase();
}

console.log(processWord("COMPUTER"));