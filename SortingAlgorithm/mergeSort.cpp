#include<iostream>

using namespace std;

void printArray(int arr[], int n){
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

void merge(int arr[], int start, int mid, int end){
	int k = end-start+1;
	int i = 0, l = start, m = mid+1, n = end;
	int temp[end-start+1];
	while(l<=mid & m<=end){
		if(arr[l]<arr[m]){
			temp[i++] = arr[l++];
		}else{
			temp[i++] = arr[m++];
		}
	}
	
	while(l<=mid){
		temp[i++] = arr[l++];
	}
	
	while(m<=end){
		temp[i++] = arr[m++];
	}
	
	for(i=0;i<k;i++){
		arr[start+i] = temp[i];
	}
}

void mergeSort(int arr[], int start, int end){
	if(start<end){
		int mid = (start + end)/2;
		
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}

int main(){
	
	int arr[] = {3,2,5,-89,-56,3,1,6,36,22,64,1,7};
	
	printArray(arr, 11);
	mergeSort(arr, 0, 10);
	printArray(arr, 11);
	
	return 0;
}
