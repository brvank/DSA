// Circular Linked List implementation in C++.

#include<iostream>

using namespace std;

struct Node{
	int data;
	Node* next;
};

class CircularLinkedList{
	private:
		Node* head;
		Node* tail;
		Node* temp1;
		Node* temp2;
		int count;
		
	public:
		CircularLinkedList(){
			head = NULL;
			tail = NULL;
			count = 0;
		}
		
		void addFront(int data){
			if(head == NULL){
				temp1 = new Node;
				temp1->data = data;
				temp1->next = temp1;
				head = temp1;
				tail = temp1;
				count++;
			}else{
				temp1 = new Node;
				temp1->data = data;
				temp1->next = head;
				head = temp1;
				tail->next = head;
				count++;
			}
		}
		
		void addAt(int data, int index){
			if(index==0){
				addFront(data);
			}else if(index>count){
				cout<<"Warning: Index out of bound!\tNot added " << data<<" at index "<<index<<" .\n";
			}else{
				temp1 = head;
				for(int i=1;i<index;i++){
					temp1 = temp1->next;
				}
				temp2= new Node;
				temp2->data = data;
				temp2->next = temp1->next;
				temp1->next = temp2;
				count++;
			}
		}
		
		void addLast(int data){
			if(tail == NULL){
				cout<<"Warning: List is empty!\n";
			}else{
				temp2 = new Node;
				temp2->data = data;
				temp2->next = head;
				tail = temp2;
				count++;
			}
		}
		
		int getFront(){
			if(head == NULL){
				cout<<"Warning: List is empty!\n";
			}else{
				return head->data;
			}
		}
		
		int getFrom(int index){
			if(head == NULL){
				cout<<"Warning: List is empty!\n";
			}else if(index >= count){
				cout<<"Warning: Index out of bound!\tNo node at index "<<index<< "\n";
			}else{
				temp1 = head;
				for(int i=0;i<index;i++){
					temp1 = temp1->next;
				}
				return temp1->data;
			}
			return -1;
		}
		
		int getLast(){
			if(tail == NULL){
				cout<<"Warning: List is empty!\n";
			}else{
				return tail->data;
			}
			return -1;
		}
		
		void deleteFront(){
			if(head == NULL){
				cout<<"Warning: List is empty!\n";
			}else{
				temp1 = head;
				head = head->next;
				delete temp1;
				count--;
			}
		}
		
		void deleteFrom(int index){
			if(head == NULL){
				cout<<"Warning: List is empty!\n";
			}else if(index >= count){
				cout<<"Warning: Index out of bound!\tNo node at index "<<index<< "\n";
			}else if(index == 0){
				deleteFront();
			}else if(index == count-1){
				deleteLast();
			}else{
				temp1 = head;
				for(int i=1;i<index;i++){
					temp1 = temp1->next;
				}
				temp2 = temp1->next;
				temp1->next = temp2->next;
				delete temp2;
				count--;
			}
		}
		
		void deleteLast(){
			if(head == NULL){
				printf("Warning: List is empty!\n");
			}else if(count == 1){
				deleteFront();
			}else{
				temp1 = head;
				temp2 = temp1;
				while(temp1->next!=head){
					temp2 = temp1;
					temp1 = temp1->next;
				}
				temp2->next=head;
				tail = temp2;
				delete temp1;
				count--;
			}
		}
		
		void printList(){
			if(head == NULL){
				cout<<"Warning: List is empty!\n";
			}else{
				cout<<head->data<<" ";
				temp1 = head->next;
				while(temp1!=head){
					cout<<temp1->data<<" ";
					temp1 = temp1->next;
				}
				cout<<"\n";
			}
		}
		
		int getSize(){
			return count;
		}
		
		~CircularLinkedList(){
			count = 0;
			if(head != NULL){
				temp1 = head->next;
				while(temp1!=head){
					temp2 = temp1->next;
					delete temp1;
					temp1 = temp2;
				}
				delete head ;
			}
		}
};


int main(){
	CircularLinkedList cll;
	for(int j= 10 ;j<23;j++){
		cll.addFront(j);
	}
	cout<<cll.getFront()<<"\n";
	cll.deleteFront();
	cout<<cll.getFront()<<"\n";
	cll.addLast(100);
	cout<<cll.getFrom(10)<<"\n";
	cll.getFrom(23);
	cll.deleteFrom(6);
	cll.addAt(23,6);
	cll.deleteLast();
	cll.printList();
	cout<<cll.getLast()<<"\n";
	cout<<cll.getSize();
	return 0;
}
