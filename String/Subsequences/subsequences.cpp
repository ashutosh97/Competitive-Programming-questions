//find all the sub sequences of a string
#include <iostream>
using namespace std;
char output[100] = "";

void printSubSeq(char str[], int be, int idx)
{
    if (str[be] == '\0')
    {
        output[idx] = '\0';
        cout << output << endl;
        return;
    }

    printSubSeq(str, be + 1, idx);
    output[idx] = str[be];
    printSubSeq(str, be + 1, idx + 1);
}


int main() {
    char str[100];
    cin >> str;


    printSubSeq(str, 0, 0);
}
