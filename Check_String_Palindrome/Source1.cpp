#include<iostream>
#include<string>

using namespace std;

bool checkStringPallindrome(string inputString);

bool checkStringPallindrome(string inputString) {
	for (int i = 0; i < (inputString.length() / 2); i++) {
		if (inputString.at(i) != inputString.at(inputString.length() - 1 - i)) {
			return false;
		}
	}
	return true;
}
int main() {

	string input;
	getline(cin, input);
	if (checkStringPallindrome(input)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	system("pause");
	return 1;
}