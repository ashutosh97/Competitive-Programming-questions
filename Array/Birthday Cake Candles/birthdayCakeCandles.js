// This is the link  https://www.hackerrank.com/challenges/birthday-cake-candles/problem to the challenge

// Complete the birthdayCakeCandles function below.
function birthdayCakeCandles(ar) {
    let maxnumber = ar[0];
    let count = 0;
    for (let i = 0; i < ar.length; i++) {
        if (ar[i] > maxnumber) {
            maxnumber = ar[i];
            count = 0;
            count++;
        } else if (ar[i] == maxnumber) {
            count++;
        }
    }
    return count
}
