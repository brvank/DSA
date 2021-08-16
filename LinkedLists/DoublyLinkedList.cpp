// Doubly Linked List implementation in C++.

#include<iostream>

using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
};

class DoublyLinkedList{
	private:
		Node* head;
		Node* tail;
		Node* temp1;
		Node* temp2;
		int count;
	
	public:
		DoublyLinkedList(){
			head = tail = NULL;
			count = 0;
		}
		
		void addFront(int data){
			if(head == NULL){
				head = new Node;
				head->data=data;
				head->right = NULL;
				head->left = NULL;
				tail = head;
				count++;
			}else{
				temp1=new Node;
				temp1->data = data;
				temp1->left = NULL;
				temp1->right = head;
				head->left = temp1;
				head = temp1;
				count++;
			}
		}
		
		void addFromFrontAt(int data, int index){
			if(index == 0){
				addFront(data);
			}else if(index == count-1){
				printf("but here\n");
				addLast(data);
			}else if(index>= count){
				printf("Warning: Index out of bound!\tNot added %d at index %d(From Front)!\n",data,index);
			}else{
				printf("here\n");
				temp1 = head;
				for(int i=1;i<index;i++){
					temp1 = temp1->right;
				}
				temp2 = new Node;
				temp2->data = data;
				temp2->right = temp1->right;
				temp2->right->left = temp2;
				temp1->right = temp2;
				temp2->left = temp1;
				count++;
			}
		}
		
		void addFromLastAt(int data, int index){
			if(index == 0){
				addFront(data);
			}else if(index == count-1){
				addLast(data);
			}else if(index>= count){
				printf("Warning: Index out of bound!\tNot added %d at index %d(From Front)!\n",data,index);
			}else{
				temp2 = tail;
				for(int i=count-1;i>index;i++){
					temp2 = temp2->left;
				}
				temp1 = new Node;
				temp1->data = data;
				temp1->left = temp2->left;
				temp1->left->right = temp1;
				temp1->right = temp2;
				temp2->left = temp1;
				count++;
			}
		}
		
		void addLast(int data){
			if(tail == NULL){
				addFront(data);
			}else{
				temp2 = new Node;
				temp2->data = data;
				temp2->left = tail;
				temp2->right = NULL;
				tail->right = temp2;
				tail = temp2;
				count++;
			}
		}
		
		int getFront(){
			if(head == NULL){
				printf("Warning: List is empty!\n");
			}else{
				return head->data;
			}
			return -1;
		}
		
		int getFromFront(int index){
			if(index == 0){
				getFront();
			}else if(index == count-1){
				getLast();
			}else if(index>= count){
				printf("Warning: Index out of bound!\tNo node at index %d.\n",index);
			}else{
				temp1 = head;
				for(int i=0;i<index;i++){
					temp1 = temp1->right;
				}
				return temp1->data;
			}
			return -1;
		}
		
		int getFromLast(int index){
			if(index == 0){
				getFront();
			}else if(index == count-1){
				getLast();
			}else if(index>= count){
				printf("Warning: Index out of bound!\tNo node at index %d.\n",index);
			}else{
				temp2 = tail;
				for(int i=count-1;i>index;i--){
					temp2 = temp2->left;
				}
				return temp2->data;
			}
			return -1;
		}
		
		int getLast(){
			if(tail == NULL){
				printf("Warning: List is empty!\n");
			}else{
				return tail->data;
			}
			return -1;
		}
		
		void deleteFront(){
			if(head == NULL){
				printf("Warning: List is empty!\n");
			}else{
				if(head == tail){
					temp1 = head;
					head = temp1->right;
					tail = temp1->left;
					delete temp1;
					count--;
				}else{
					temp1 = head;
					head = head->right;
					head->left = NULL;
					delete temp1;
					count--;
				}
			}
		}
		
		void deleteFromFront(int index){
			if(head == NULL){
				printf("Warning: List is empty!\n");
			}else if(index == 0){
				deleteFront();
			}else if(index == count-1){
				deleteLast();
			}else if(index >= count){
				printf("Warning: Index out of bound!\tNo node at index %d.\n",index);
			}else{
				temp1 = head;
				for(int i=1;i<index;i++){
					temp1 = temp1->right;
				}
				Node* temp3;
				temp3 = temp1->right;
				temp1->right = temp3->right;
				temp2 = temp1->right;
				temp2->left = temp1;
				delete temp3;
				count--;
			}
		}
		
		void deleteFromLast(int index){
			if(head == NULL){
				printf("Warning: List is empty!\n");
			}else if(index == 0){
				deleteFront();
			}else if(index == count-1){
				deleteLast();
			}else if(index >= count){
				printf("Warning: Index out of bound!\tNo node at index %d.\n",index);
			}else{
				temp2 = tail;
				for(int i=count-1;i>index+1;i--){
					temp2 = temp2->left;
				}
				Node* temp3;
				temp3 = temp2->left;
				temp2->left = temp3->left;
				temp1 = temp2->left;
				temp1->right = temp2;
				delete temp3;
				count--;
			}
		}
		
		void deleteLast(){
			if(tail == NULL){
				printf("Warning: List is empty!\n");
			}else{
				if(tail == head){
					temp2 = tail;
					tail = temp2->left;
					head = temp2->right;
					delete temp2;
					count--;
				}else{
					temp2 = tail;
					tail = tail->left;
					tail->right = NULL;
					delete temp2;
					count--;
				}
			}
		}
		
		void printList(){
			if(head == NULL){
				printf("Warning: List is empty!\n");
			}else{
				temp1 = head;
				while(temp1!=NULL){
					printf("%d ",temp1->data);
					temp1 = temp1->right;
				}
			}
		}
		
		void printReverse(){
			if(tail == NULL){
				printf("Warning: List is empty!\n");
			}else{
				temp2 = tail;
				while(temp2!=NULL){
					printf("%d ",temp2->data);
					temp2 = temp2->left;
				}
			}
		}
		
		int getSize(){
			return count;
		}
		
		~DoublyLinkedList(){
			while(head!=NULL){
				temp1 = head->right;
				delete head;
				head = temp1;
			}
		}
};



int main(){
	DoublyLinkedList dll;
	dll.deleteFront();
	dll.addFront(23);
	dll.addFront(15);
	dll.addFront(45);
	dll.addLast(22);
	dll.addFront(67);
	dll.addFront(77);
	dll.printList();
	printf("\n");
	dll.deleteFromLast(4);
	dll.printList();
	printf("\n");
	cout<<dll.getSize();
	dll.deleteFront();
	cout<<dll.getSize();
	dll.deleteFront();
	cout<<dll.getSize();
	dll.deleteFront();
	cout<<dll.getSize();
	dll.deleteFront();
	cout<<dll.getSize();
	dll.deleteLast();
	cout<<dll.getSize();
	dll.deleteFront();
	cout<<dll.getSize();
	dll.deleteFront();
	cout<<dll.getSize();
	dll.deleteFront();
	cout<<dll.getSize();
	dll.deleteLast();
	cout<<dll.getSize();
	return 0;
}
