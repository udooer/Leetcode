#include<iostream>
using namespace std;
int partition(int *ptr, int low, int high){
	int flag=low;
	for(int i=low;i<high;i++){
		if(ptr[i]<ptr[high]){
			swap(ptr[flag], ptr[i]);
			flag++;
		}
	}
	swap(ptr[flag], ptr[high]);
	return flag;
}
void quickSort(int *ptr, int low, int high){
	if(high<=low){
		return;
	}
	int pos = partition(ptr, low, high);
	quickSort(ptr, low, pos-1);
	quickSort(ptr, pos+1, high);
}
void printArray(int *arr, int size){
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main() {

    int array[6] = { 5, 3, 1, 2, 6, 4 };
    std::cout << "original:\n";
    printArray(array, 6);

    quickSort(array, 0, 6);

    std::cout << "sorted:\n";
    printArray(array, 6);
    return 0;
}