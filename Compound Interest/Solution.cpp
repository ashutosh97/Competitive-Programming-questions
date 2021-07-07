#include <iostream> 
#include <iomanip> 
#include <cmath>  
using namespace std; 

int main() 
{
	double amount; 
	double p = 1000.0; 
	double r = .05;  

	cout <<" Year: " << setw(21) <<" Deposit amount"<<endl; 
	cout << fixed << setprecision(2);


	for (int n =1; n <=10;n++)  
	{ 
		int a = p * pow(1.0 + r, n); 
		cout<< setw(4) << n << setw(21) << a <<endl;

	}


	system("pause");
	return 0;
} 
