#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;
void sort(int *, int);
void printArray(int *, int);
int main(){
	srand(time(NULL));
	int len = 10;
	int *a = new int[len];
	for(int i=0;i<len;i++){
		*(a+i)=rand()%100;
	}
	printArray(a, len);
	sort(a, len);
	printArray(a, len);
	return 0;
}
void sort(int *a, int len){
	int now;
	int j;
	for(int i=1;i<len;i++){
		now=*(a+i);
		for(j=i-1;j>=0;j--){
			if(*(a+j)<=now)
				break;
			else
				*(a+j+1) = *(a+j);
		}
		*(a+j+1) = now;
	}
	return;
}
void printArray(int *a, int len){
	for(int i=0;i<len;i++){
		cout<<*(a+i)<<" ";
	}
	cout<<"\n";
	return;
}