#include<iostream>
using namespace std;
int main(){
	short a = 24; //00001100
	short c;
	cout<<sizeof(a)<<"\n";
	c = ~a; //11110011
	cout<<c;
	return 0; 
}