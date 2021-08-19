// Doubly Ended Queue implementation in C++

#include<iostream>

using namespace std;

struct Node{
	int data;
	Node * next;
	Node * prev;
};

class Dequeue{
	private:
		Node * front;
		Node * back;
		Node * temp;
		int count;
		
	public:
		Dequeue(){
			count = 0;
			front = NULL;
			back = NULL;
		}
		
		void pushFront(int data){
			if(front==NULL){
				temp = new Node;
				temp->data = data;
				temp->next = NULL;
				front = temp;
				back = temp;
				count++;
			}else{
				temp = new Node;
				temp->data = data;
				temp->next = front;
				temp->prev = NULL;
				front->prev = temp;
				front = temp;
				count++;
			}
		}
		
		void pushBack(int data){
			if(back==NULL){
				temp = new Node;
				temp->data = data;
				temp->next = NULL;
				front = temp;
				back = temp;
				count++;
			}else{
				temp = new Node;
				temp->data = data;
				temp->next = NULL;
				temp->prev = back;
				back->next = temp;
				back = temp;
				count++;
			}
		}
		
		void popFront(){
			if(front == NULL){
				cout<<"Warning: Queue is empty!\n";
			}else{
				temp = front->next;
				temp->prev = NULL;
				front->next = NULL;
				delete front;
				front = temp;
				count--;
			}
		}
		
		void popBack(){
			if(front == NULL){
				cout<<"Warning: Queue is empty!\n";
			}else{
				temp = back->prev;
				temp->next = NULL;
				back->prev = NULL;
				delete back;
				back = temp;
				count--;
			}
		}
		
		int getFront(){
			if(front == NULL){
				cout<<"Warning: Queue is empty!\n";
			}else{
				return front->data;
			}
			return -1;
		}
		
		int getBack(){
			if(back == NULL){
				cout<<"Warning: Queue is empty!\n";
			}else{
				return back->data;
			}
			return -1;
		}
		
		void print(){
			temp = front;
			while(temp != NULL){
				cout<<temp->data<<"\t";
				temp = temp->next;
			}
			cout<<"\n";
		}
		
		void printReverse(){
			temp = back;
			while(temp != NULL){
				cout<<temp->data<<"\t";
				temp = temp->prev;
			}
			cout<<"\n";
		}
		
		int getSize(){
			return count;
		}
		
		~Dequeue(){
			count = 0;
			while(front != NULL){
				temp = front->next;
				delete front;
				front = temp;
			}
		}
		
};


int main(){
	
	Dequeue dq;
	cout<<dq.getFront()<<endl;
	dq.pushFront(23);
	dq.pushFront(21);
	dq.pushBack(224);
	dq.pushBack(34);
	dq.pushFront(3);
	dq.popBack();
	dq.pushBack(222);
	cout<<dq.getSize()<<endl;
	dq.pushFront(72);
	//dq.popFront();
	cout<<"\nfront ---> ";
	cout<<dq.getFront();
	cout<<"\nback ---> ";
	cout<<dq.getBack();
	cout<<endl;
	cout<<dq.getSize();
	cout<<endl;
	dq.print();
	dq.printReverse();
	
	
	
	return 0;
}
