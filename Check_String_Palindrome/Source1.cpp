#include<iostream>
#include<string>

bool checkStringPallindrome(string inputString);

bool checkStringPallindrome(string inputString) {
	//if (inputString.length() % 2 == 1) {
		for (int i = 0; i < inputString.length()/2; i++) {
			if (inputString.at[i] != inputString.at[inputString.length() - 1 - i]) {
				return false;
			}
		}
	//}
	//else {

	//}
		return true;
}
int main(){

	string input = "";
	std::getline(std::cin, input);
	std::cout<<checkStringPallindrome(input);

	system("pause");
	return 1;
}