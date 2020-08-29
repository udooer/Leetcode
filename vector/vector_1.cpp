#include<vector>
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	vector<vector<int>> v;
	v.clear();
	v.push_back({5});
	v.push_back({100});
	v.push_back({1000});
	printf("v[0]:%p", v[0].begin());
	printf("\ncapacity of v[0]:%d", v[0].capacity());
	printf("\nv[1]:%p", v[1].begin());
	printf("\nv[2]:%p", v[2].begin());
	vector<int>::iterator ptr = v[0].begin();
	vector<int>::iterator temp;
	int count = 0;
	for(int i=0;i<100;i++){
		v[0].push_back(i);
		temp = v[0].begin();
		if(temp!=ptr){
			count++;
			ptr = temp;
		}
	}
	printf("\nAfter assign more numbers:");
	printf("\nv[0]:%p", v[0].begin());
	printf("\ncapacity of v[0]:%d", v[0].capacity());
	printf("\nv[1]:%p", v.begin());
	printf("\nv[1]:%p", v[1].begin());
	printf("\nv[2]:%p", v[2].begin());
	cout<<"\ncounts of changes:"<<count;
	return 0;
}