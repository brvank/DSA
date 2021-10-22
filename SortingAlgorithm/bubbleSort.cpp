#include<iostream>

using namespace std;

void printArray(int arr[], int n){
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

void bubbleSort(int arr[], int n){
	
	for(int i=0;i<n-1;i++){
		int sorted = 1;
		for(int j=0;j<n-i-1;j++){
			if(arr[j] > arr[j+1]){
				//still not sorted
				sorted = 0;
				arr[j] = arr[j] + arr[j+1];
				arr[j+1] = arr[j] - arr[j+1];
				arr[j] = arr[j] - arr[j+1];
			}
		}
		if(sorted){
			//if sorted break i.e., if the value of sorted is not changed then there are no swaps and hence array is sorted now
			break;
		}
	}
}

int main(){
	
	int arr[] = {3,2,5,-89,-56,3,1,6,36,22,64,1,7};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	printArray(arr, n);
	bubbleSort(arr, n);
	printArray(arr, n);
	
	return 0;
}
