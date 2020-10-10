function printDuplicates(inputText){
  var frequenceCountMap = {};
  var inputs = inputText.split(' ');
  for(var ii = 0, len = inputs.length; ii < len; ii++){
    var word = inputs[ii];
    if(frequenceCountMap[word]){
      frequenceCountMap[word] += 1;
    }else{
      frequenceCountMap[word] = 1;
    }
  }

  for(var key in frequenceCountMap){
    if(frequenceCountMap[key] > 1){
      console.log(key);
    }
  }
}

var inputVal = "Work hard and play hard and have fun at work.";

printDuplicates(inputVal);