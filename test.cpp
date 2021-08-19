#include<iostream>
//#include<typeinfo>

using namespace std;

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

//int main(){
//	
//	int a = (float) 2.3f;
//	int b = 20.0f;
//	int arr[][4][2] = {1,3,2,2,3,4,2,5};
//	cout<<typeid(arr).name();
//	cout<<a%b;
//	
//	return 0;
//}
