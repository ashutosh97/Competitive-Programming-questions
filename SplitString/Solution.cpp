#include <iostream>
#include <vector>
#include <string>
using namespace std;

/** Gets a string and separe through a separator _sep and returns into a
 * std::vector<std::string> */
std::vector<std::string> split(std::string _str, char _sep) {
    std::vector<std::string> v;
    int begin = 0;
    for (int i=0 ; i < _str.size() ; i++){
        if (_str[i] == _sep) {
            v.push_back( _str.substr(begin, i-begin) );
            begin = i+1;
        }
    }
    v.push_back(_str.substr(begin, _str.size()));
    return v;
};


int main() {

    string str1 = "name.midname.lastname";
    vector<string> vecStr1 = split(str1, '.');
    for (string& s : vecStr1) {
        cout << s << endl;
    }

    cout << endl;
    string str2 = "myname@emailservice.com";

    vector<string> vecStr2 = split(str2, '@');
    for (string& s : vecStr2) {
        cout << s << endl;
    }

    return 0;
}