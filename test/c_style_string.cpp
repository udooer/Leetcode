#include<iostream>
#include<string>
using namespace std;
int main(){
	char s[]{"string"};
	string str = s; 
	cout<<"sizeof(s): "<<sizeof(s)<<'\n';
	cout<<"sizeof(string): "<<sizeof(str)<<'\n';
	cout<<"sizeof(str.c_str()): "<<sizeof(str.c_str())<<'\n';
	cout<<"sizeof(str.c_str()): "<<sizeof(str.c_str())<<'\n';
	return 0;
}