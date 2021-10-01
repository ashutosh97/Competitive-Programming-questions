// Name: Bhupendra Chauhan
//Email: chauhanbhupendra145@gmail.com
/*This is a program for Printing Power Set.
 * Number of Elements are taken as input from User.
*/

#include<iostream>
#include <math.h> 
using namespace std;


//Program For Power Set
void PowerSet(char set[],int set_size){
	int num=pow(set_size,2);       //Calculate the Number Of Element in Power Set
	for(int i=0;i<num;i++){
		for(int j=0;j<set_size;j++){
			if(i & 1<<j)
				std::cout<<set[j]<<" ";           //Printing Power Set
		}
		std::cout<<"\n";
	}
}


//Driver Function
int main(int argc, char const *argv[])
{
	char set[100];
	int set_size;     //Number Of Elements
	flag:
	std::cout<<"Enter the Number Of Elements(<100)\n";
	std::cin>>set_size;
	if(set_size<100 && set_size>0){               
		for(int i=0;i<set_size;i++){         //Input Of Elements Of Set
			std::cin>>set[i];
		}
		PowerSet(set,set_size);
	}
	else{
		std::cout<<"Number Of Elements should be less than 100 and greater than 0\n";
		goto flag;
	}
	return 0;	
}