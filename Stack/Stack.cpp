// Stack implementation in C++.

#include<iostream>

using namespace std;

struct Node{
	int data;
	Node * next;
};

class Stack{
	private:
		int count;
		Node * top;
		Node * temp;
		
	public:
		Stack(){
			top = NULL;
			count = 0;
		}
		
		void push(int data){
			if(top == NULL){
				top = new Node;
				top->data = data;
				top->next = NULL;
				count++;
			}else{
				temp = new Node;
				temp->data = data;
				temp->next = top;
				top = temp;
				count++;
			}
		}
		
		void pop(){
			if(top == NULL){
				cout<<"Warning: Stack is empty!\n";
			}else{
				temp = top->next;
				delete top;
				top = temp;
				count--;
			}
		}
		
		int getTop(){
			if(top == NULL){
				cout<<"Warning: Stack is empty!\n";
			}else{
				return top->data;
			}
			return -1;
		}
		
		void print(){
			temp = top;
			while(temp != NULL){
				cout<<temp->data<<"\t";
				temp = temp->next;
			}
			cout<<"\n";
		}
		
		int getSize(){
			return count;
		}
		
		~Stack(){
			while(top != NULL){
				temp = top->next;
				delete top;
				top = temp;
			}
		}
};


int main(){
	Stack st;
	st.push(23);
	st.push(24);
	st.push(25);
	st.push(26);
	st.push(27);
	st.push(28);
	st.push(29);
	st.push(30);
	st.push(31);
	st.push(32);
	st.push(34);
	st.print();
	cout<<st.getTop()<<endl;
	st.pop();
	st.pop();
	cout<<st.getTop()<<endl;
	cout<<st.getTop()<<endl;
	cout<<st.getSize()<<endl;
	return 0;
}
