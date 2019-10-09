#include <bits/stdc++.h>
using namespace std;

void generate(int n, int opening, int closing, string combination, vector<string>& result) {
    int size = combination.size();
    if(size == n && closing == opening) {
        result.push_back(combination);
        return;
    }
    
    if((closing < opening) && (size > 0)) {
        combination.push_back(')');
        generate(n, opening, closing+1, combination, result);
        combination.pop_back();
    }
    
    if(size < n-1) {
        combination.push_back('(');
        generate(n, opening+1, closing, combination, result);
        combination.pop_back();    
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string combination;
    generate(2*n, 0, 0, combination, result);
    return result;
}

int main() {

    int n;
    vector<string> result;

    scanf("%d", &n);

    result = generateParenthesis(n);
    
    for(int i=0; i<result.size(); i++) {
        printf("%s\n", result[i].c_str());
    }

    return 0;   
}