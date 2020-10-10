#include<iostream>
#include<string>

using namespace std;

//This is a function that returns a boolean value, after checking the string.
bool checkStringPallindrome(string inputString);

bool checkStringPallindrome(string inputString) {
	for (int i = 0; i < (inputString.length() / 2); i++) {
		if (inputString.at(i) != inputString.at(inputString.length() - 1 - i)) {
			return false;
		}
	}
	return true;
}
void main() {

	clrscr(); //this inbuild function clears the screen
	string input; //the string to check whether its palindrome or not
	getline(cin, input); 
	if (checkStringPallindrome(input)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	getch();
}
