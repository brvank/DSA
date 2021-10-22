#include<iostream>
using namespace std;

class NodeQ{
	public:
		int data;
		NodeQ * next;
};

class Queue{
	private:
		int size;
		NodeQ * front;
		NodeQ * back;
		
	public:
		Queue(){
			size = 0;
			front = NULL;
			back = NULL;
		}
		
		void push(int data){
			if(front == NULL){
				front = new NodeQ;
				front->data = data;
				front->next = NULL;
				back = front;
			}else{
				NodeQ * temp = new NodeQ;
				temp->data = data;
				temp->next = NULL;
				back->next = temp;
				back = temp;
			}
			size++;
		}
		
		void pop(){
			if(front == NULL){
				cout<<"Queue is empty!\n";
			}else if(front == back){
				delete back;
				front = back = NULL;
				size--;
			}else{
				NodeQ * temp = front;
				front = temp->next;
				temp->next = NULL;
				delete temp;
				size--;
			}
		}
		
		int getFront(){
			if(front == NULL){
				cout<<"Queue is empty!\n";
				return -1;
			}else{
				return front->data;
			}
		}
		
		int getSize(){
			return size;
		}
		
		~Queue(){
			size = 0;
			NodeQ * temp;
			while(front != NULL){
				temp = front->next;
				delete front;
				front = temp;
			}
			front = back = NULL;
		}
};

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
		
		void bfs(){
			//setting all the visited tags to 0
			startVisited();
			
			//main logic here
			Queue q;
			q.push((nodes+0)->value);
			visited[0] = 1;
			while(q.getSize()>0){
				int i = q.getFront();
				cout<<i<<"->";
				q.pop();
				Node * temp = (nodes + i);
				while(temp != NULL){
					if(!visited[temp->edgeTo] && temp->edgeTo){
						q.push(temp->edgeTo);
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
	
	g.bfs();
	
	g.printGraph();
	
	return 0;
}
