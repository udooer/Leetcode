#include<iostream>
int binarySearch(int *ptr, int left, int right, int target){
	if(right>=left){	
		int mid = (left+right)/2;
		if(*(ptr+mid)==target)
			return mid;
		else if(*(ptr+mid)>target){
			return binarySearch(ptr, left, mid-1, target);
		}
		else
			return binarySearch(ptr, mid+1, right, target);
	}
	return -1;
}