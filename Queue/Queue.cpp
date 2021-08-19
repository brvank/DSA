// Queue implementation in C++.

#include<iostream>

using namespace std;

struct Node{
	int data;
	Node * next;
};

class Queue{
	private:
		Node * front;
		Node * back;
		Node * temp;
		int count;
		
	public:
		Queue(){
			front = NULL;
			back = NULL;
			count = 0;
		}
		
		void push(int data){
			if(front == NULL){
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
				back->next = temp;
				back = temp;
				count++;
			}
		}
		
		void pop(){
			if(front == NULL){
				cout<<"Warning: Queue is empty!\n";
			}else{
				temp = front->next;
				delete front;
				front = temp;
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
		
		void print(){
			temp = front;
			while(temp != NULL){
				cout<<temp->data<<"\t";
				temp = temp->next;
			}
			cout<<"\n";
		}
		
		int getSize(){
			return count;
		}
		
		~Queue(){
			count = 0;
			while(front != NULL){
				temp = front->next;
				delete front;
				front = temp;
			}
		}
		
};

int main(){
	Queue q;
	cout<<q.getFront();
	q.pop();
	q.push(23);
	q.push(24);
	q.push(25);
	q.push(26);
	q.push(27);
	q.push(28);
	q.push(29);
	q.push(30);
	q.print();
	cout<<q.getFront()<<endl;
	q.pop();
	cout<<q.getFront()<<endl;
	q.pop();
	cout<<q.getFront()<<endl;
	q.pop();
	cout<<q.getFront()<<endl;
	q.pop();
	cout<<q.getFront()<<endl;
	cout<<q.getSize()<<endl;
	return 0;
}
