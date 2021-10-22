#include<iostream>
using namespace std;

//Stack code here
class NodeS{
	public:
		int data;
		NodeS * next;
};

class Stack{
	private:
		int size;
		NodeS * top;
		
	public:
		Stack(){
			size = 0;
			top = NULL;
		}
		
		void push(int data){
			if(top == NULL){
				top = new NodeS;
				top->data = data;
				top->next = NULL;
			}else{
				NodeS * temp = new NodeS;
				temp->data = data;
				temp->next = top;
				top = temp;
			}
			size++;
		}
		
		void pop(){
			if(top == NULL){
				cout<<"Stack is empty!\n";
			}else{
				NodeS * temp = top;
				top = temp->next;
				temp->next = NULL;
				delete temp;
				size--;
			}
		}
		
		int getTop(){
			if(top == NULL){
				cout<<"Stack is empty!\n";
				return -1;
			}else{
				return top->data;
			}
		}
		
		int getSize(){
			return size;
		}
		
		~Stack(){
			size = 0;
			NodeS * temp;
			while(top != NULL){
				temp = top->next;
				delete top;
				top = temp;
			}
		}
};

//Graph code here
class Node{
	public:
		int edgeTo;
		int value;
		Node * next;
};

class Graph{
	private:
		int vertices;
		Node * nodes;
		int * visited;
		
	public:
		Graph(int v){
			this->vertices = v;
			this->visited = new int[v];
			this->nodes = new Node[v];
			for(int i=0;i<v;i++){
				(nodes + i)->value = 0;
				(nodes + i)->edgeTo = i;
				(nodes + i)->next = NULL;
			}
		}
		
		void addEdge(int from, int to, int data){
			if(from >= vertices){
				cout<<"No vertix numbered "<<from<<". Remember the numbering is from 0!\n";
				return;
			}
			else if(to >= vertices){
				cout<<"No vertix numbered "<<to<<". Remember the numbering is from 0!\n";
				return;
			}
			//creating a node to be added
			Node * temp = new Node;
			temp->value = data;
			temp->edgeTo = to;
			temp->next = NULL;
			if((nodes+from)->next == NULL){
				(nodes+from)->next = temp;
			}else{
				Node * temp2 = (nodes+from);
				while(temp2->next != NULL){
					temp2 = temp2->next;
				}
				temp2->next = temp;
			}
		}
		
		void startVisited(){
			for(int i=0;i<vertices;i++){
				*(visited + i) = 0;
			}
		}
		
		void dfs(){
			//setting all the visited tags to 0
			startVisited();
			
			//main logic here
			Stack s1;
			s1.push((nodes + 0)->value);
			visited[0] = 1;
			while(s1.getSize()>0){
				int i = s1.getTop();
				cout<<i<<" -> ";
				s1.pop();
				Node * temp = (nodes + i);
				while(temp != NULL){
					if(!visited[temp->edgeTo] && temp->value){
						s1.push(temp->edgeTo);
						visited[temp->edgeTo] = 1;
					}
					temp = temp->next;
				}
				
			}
			cout<<" end"<<endl;
		}
		
		void printGraph(){
			for(int i=0; i<vertices; i++){
				Node * temp = (nodes + i);
				while(temp->next != NULL){
					cout<<temp->edgeTo<< ","<<temp->value<<" -> ";
					temp = temp->next;
				}
				cout<<temp->edgeTo<<","<<temp->value<<"\n";
			}
		}
};

int main(){
	
	Graph g(6);
	g.addEdge(0,1,2);
	g.addEdge(2,5,1);
	g.addEdge(2,3,1);
	g.addEdge(3,5,1);
	g.addEdge(0,4,1);
	g.addEdge(4,2,1);
	
	g.dfs();
	
	g.printGraph();
	
	return 0;
}
