#include <bits/stdc++.h> 
using namespace std; 
  
// We declare the vector of factors for storing the 
vector<int> factors; 
  
// function to find out the factors of a number 
void findFactors(int n) 
{ 
    // we loop until the i reaches the sqrt(n) 
    for (int i = 1; i * i <= n; i++) { 
  
        // we check if i is a factor of n 
        if (n % i == 0) { 
  
            // if both the factors are same 
            // only push one factor 
            if ((n / i) == i) { 
                factors.push_back(i); 
            } 
            else { 
  
                // factor1 is pushed 
                factors.push_back(n / i); 
  
                // factor2 is pushed 
                factors.push_back(i); 
            } 
        } 
    } 
} 
  
int findProduct(int n) 
{ 
    // initialise the product with -1 
    int product = -1; 
    int si = factors.size(); 
  
    for (int i = 0; i < si; i++) 
        for (int j = 0; j < si; j++) 
            for (int k = 0; k < si; k++) { 
  
                // we find the sum of factors 
                // and store it in s 
                int s = factors[i] + factors[j] + factors[k]; 
  
                // we check whether the fourth 
                // factor exists or not 
                if (binary_search(factors.begin(), factors.end(), n - s)) { 
                    // product of factors 
                    int p = factors[i] * factors[j] * factors[k] * (n - s); 
  
                    // we check whether we have a better 
                    // p now if yes update 
                    if (p > product) 
                        product = p; 
                } 
            } 
  
    return product; 
} 
  
// Driver code 
int main() 
{ 
    int n = 10; 
  
    // intializes the vectors with the divisors of n 
    findFactors(n); 
  
    // sorts the factors vector 
    sort(factors.begin(), factors.end()); 
  
    // prints out the maximised product. 
    cout << findProduct(n); 
    return 0; 
} 
