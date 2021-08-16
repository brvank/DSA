// Linked List implementation in C++.
#include<iostream>

using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

class LinkedList{
	private:
		Node* head;
		Node* temp;
		int count;
		
	public:
		LinkedList(){
			head = NULL;
			count = 0;
		}
		
		void addFront(int data){
			if(head == NULL){
				head = new Node;
				head->data = data;
				head->next = NULL;
				count++;
			}else{
				temp = new Node;
				temp->data = data;
				temp->next = head;
				head = temp;
				count++;
			}
		}
		
		void addAt(int data, int index){
			if(index==0){
				addFront(data);
			}else if(index>count){
				printf("Warning: Index out of bound!\tNot added %d at index %d\n",data,index);		//Warning if index is out of the scope.
			}else{
				temp = head;
				for(int i=1;i<index;i++){
					temp = temp->next;
				}
				Node* temp2= new Node;
				temp2->data = data;
				temp2->next = temp->next;
				temp->next = temp2;
				count++;
			}
		}
		
		void addLast(int data){
			if(head == NULL){
				addFront(data);
			}else{
				temp = head;
				while(temp->next != NULL){
					temp = temp->next;
				}
				Node* temp2;
				temp2 = new Node;
				temp2->data = data;
				temp2->next = NULL;
				temp->next = temp2;
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
		
		int getFrom(int index){
			if(head == NULL){
				printf("Warning: List is empty!\n");
			}else if(index>=count){
				printf("Warning: Index out of bound!\tNo node at index %d.\n",index);
			}else{
				temp = head;
				for(int i=0;i<index;i++){
					temp = temp->next;
				}
				return temp->data;
			}
			return -1;
		}
		
		int getLast(){
			if(head == NULL){
				printf("Warning: List is empty!\n");
			}else{
				temp = head;
				for(int i=2;i<=count;i++){
					temp = temp->next;
				}
				return temp->data;
			}
			return -1;
		}
		
		void deleteFront(){
			if(head == NULL){
				printf("Warning: List is empty!\n");
			}else{
				temp = head;
				head = head->next;
				delete temp;
				count--;
			}
		}
		
		void deleteFrom(int index){
			if(head == NULL){
				printf("Warning: List is empty!\n");
			}else if(index>=count){
				printf("Warning: Index out of bound!\tNo node at index %d.\n",index);
			}else if(index == 0){
				deleteFront();
			}else if(index == count-1){
				deleteLast();
			}else{
				temp = head;
				for(int i=1;i<index;i++){
					temp = temp->next;
				}
				Node* temp2;
				temp2 = temp->next;
				temp->next = temp2->next;
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
				Node* temp2;
				temp = head;
				temp2 = temp;
				while(temp->next!=NULL){
					temp2 = temp;
					temp = temp->next;
				}
				temp2->next=NULL;
				delete temp;
				count--;
			}
		}
		
		void printList(){
			if(head == NULL){
				printf("Warning: List is empty!\n");
			}else{
				temp = head;
				while(temp != NULL){
					printf("%d ",temp->data);
					temp = temp->next;
				}
				printf("\n");
			}
			
		}
		
		int getSize(){
			return count;
		}
		
		~LinkedList(){
			while(head != NULL){
				temp = head->next;
				delete head;
				head = temp;
			}
		}
};

int main(){
	LinkedList ll;
	ll.addFront(23);
	ll.addFront(45);
	ll.addFront(89);
	ll.addFront(26);
	ll.addFront(67);
	ll.addAt(43,1);
	printf("\n%d\n",ll.getFrom(30));
	ll.printList();
	return 0;
}
