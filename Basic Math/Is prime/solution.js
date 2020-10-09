function isPrime(n) {
    if(n<2) return false
    let prime = true
    for (let i = 2; i*i<= n; i++) {
        if( n%i == 0) {
            prime = false
            break
        }
    }

    return prime
}
