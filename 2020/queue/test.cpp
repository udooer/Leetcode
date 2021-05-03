#include<queue>
#include<vector>
#include<list>
#include<algorithm>
#include<iostream>
using namespace std;
void printArray(vector<int>::iterator it, int length){
	for(int i=0;i<length;i++,it++){
		cout<<*it<<" ";
	}
	cout<<'\n';
}
int main(){
	vector<int> q;
	q.push_back(1);
	q.push_back(-2);
	q.push_back(3);
	q.push_back(-9);
	q.push_back(5);
	printArray(q.begin(), 5);
	q.erase(q.begin()+1);
	printArray(q.begin(), 4);
	return 0;
}
