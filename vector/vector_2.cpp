#include<vector>
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	vector<int> v;
	cout<<sizeof(v)<<'\n';
	for(int i=0;i<1000;i++)
		v.push_back(i);
	cout<<sizeof(v)<<'\n';
	printf("v.data(): %p", v.data());
	printf("v.begin(): %p", v.begin());
	return 0;
}