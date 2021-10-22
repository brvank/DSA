#include<iostream>
//#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;

//******************* test for dynamic matrix creation
int main(){
	
	int **matrix;
	int r,c;
	cout<<"Enter the rows and columns : ";
	cin>>r>>c;
	
	matrix = new int*[r];
	
	for(int i=0;i<r;i++){
		*(matrix + i) = new int[c];
		//alternative way
		//matrix[i] = new int[c];
		for(int j=0;j<c;j++){
			*(*(matrix + i) + j) = j;
			//alternative way
			//matrix[i][j] = j;
		} 
	}
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<*(*(matrix + i) +j)<<" ";
			//alternative way
			//matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}

//******************* test for template
//template<typename T>
//class myTemplateClass{
//	private:
//		T name;
//	public:
//		myTemplateClass(T name){
//			this->name = name;
//		}
//		
//		T getName(){
//			return this->name;
//		}
//		
//		void setName(T name){
//			this->name = name;
//		}
//};
//
//int main(){
//	myTemplateClass<int> newClass(23);
//	myTemplateClass<string> newClass2("ankit");
//	cout<<newClass.getName()<<" "<<newClass2.getName();
//	
//	return 0;
//}

//******************* test for lower_bound and upper_bound
//int main(){
//	
//	int arr[] = {1,7,3,5,6,0,7,20,26};
//	
//	for(int i=0;i<9;i++){
//		cout<<*(arr+i)<<"\t"<<arr+i<<"\n";
//	}
//	
//	cout<<"\n***************\n";
//	
//	int val = 5;
//	int * lower, * upper;
//	//lower_bound gives the value not less than val in the specified range(sorted or not)
//	lower = lower_bound(arr,arr+8,val);
//	//upper_bound gives the value greater than val in the specified range(sorted or not)
//	upper = upper_bound(arr,arr+8,val);
//	cout<<*(lower)<<"\t"<<lower<<"\n"<<*(upper)<<"\t"<<upper;
//	
//	return 0;
//}

/******************* test for nodes
struct Node{
	int data;
	Node * next;
	Node * prev;
};

int main(){
	
	Node * n1 = new Node;
	Node * n2 = new Node;
	Node * n3 = new Node;
	
	n1->data = 10;
	n2->data = 20;
	n3->data = 30;
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;
	n1->prev = NULL;
	n2->prev = n1;
	n3->prev = n2;
	
	cout<<"n1 --->";
	cout<<n1<<endl;
	cout<<"n2 --->";
	cout<<n2<<endl;
	cout<<"n3 --->";
	cout<<n3<<endl;
	
	cout<<"************************\n";
	
	cout<<"n1 next --->";
	cout<<n1->next<<endl;
	cout<<"n2 next --->";
	cout<<n2->next<<endl;
	cout<<"n3 next --->";
	cout<<n3->next<<endl;
	
	cout<<"************************\n";
	
	cout<<"n1 prev --->";
	cout<<n1->prev<<endl;
	cout<<"n2 prev --->";
	cout<<n2->prev<<endl;
	cout<<"n3 prev --->";
	cout<<n3->prev<<endl;
	
	
	cout<<"************************\n";
	
	n2->next = NULL;
	
	cout<<"n1 --->";
	cout<<n1<<endl;
	cout<<"n2 --->";
	cout<<n2<<endl;
	cout<<"n3 --->";
	cout<<n3<<endl;
	
	cout<<"************************\n";
	
	cout<<"n1 next --->";
	cout<<n1->next<<endl;
	cout<<"n2 next --->";
	cout<<n2->next<<endl;
	cout<<"n3 next --->";
	cout<<n3->next<<endl;
	
	
	return 0;
}
*/

/************************* test for multidimensional arrays
int main(){
	int a = (float) 2.3f;
	int b = 20.0f;
	int arr[][4][2] = {1,3,2,2,3,4,2,5};
	cout<<typeid(arr).name();
	cout<<a%b;
	
	return 0;
}
*/
