#include<iostream>

using namespace std;

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
		
	public:
		Graph(int v){
			this->vertices = v;
			nodes = new Node[v];
			for(int i=0; i<v; i++){
				(nodes+i)->value = 0;
				(nodes+i)->edgeTo = i;
				(nodes+i)->next = NULL;
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
			//creating a node before checking for if the list is empty or not
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
	
	Graph g(5);
	
	g.addEdge(0,4,1);
	g.addEdge(0,2,3);
	g.addEdge(1,2,2);
	g.addEdge(1,4,9);
	g.addEdge(2,4,-2);
	
	g.printGraph();
	
	return 0;
}
