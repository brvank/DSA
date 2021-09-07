#include<iostream>

using namespace std;

class Graph{
	private:
		int **adjMat;
		int vertices;
	
	public:
		Graph(int v){
			cout<<"Default graph created: \n";
			vertices = v;
			adjMat = new int*;
			for(int i=0; i<v; i++){
				*(adjMat + i) = new int;
				for(int j=0; j<v; j++){
					*(*(adjMat+i)+j) = 0;
					cout<<*(*(adjMat+i)+j)<<" ";
				}
				cout<<"\n";
			}
		}
		
		void addEdge(int from, int to, int data){
			*(*(adjMat+from) + to) = data;
		}
		
		void printGraph(){
			cout<<"\nNew graph: \n";
			for(int i=0; i<vertices; i++){
				for(int j=0; j<vertices; j++){
					cout<<**((adjMat+i)+j)<<" ";
				}
				cout<<"\n";
			}
		}
};

int main(){
	
	Graph g(5);
	g.addEdge(1,2,3);
	g.addEdge(2,2,0);
	g.addEdge(1,4,1);
	g.addEdge(2,3,2);
	g.addEdge(3,2,1);
	g.addEdge(3,0,1);
	g.addEdge(0,2,2);
	g.addEdge(0,3,2);
	g.addEdge(4,0,1);
	g.addEdge(3,4,1);
	g.addEdge(2,4,1);
	
	g.printGraph();
	
	return 0;
}

/*
void addEdge(int * add){
	cout<<"Edge added successfully.\n";
	*add = 1;
}

int main(){
	
	int vertex;
	
	cout<<"Enter number of vertices in the graph: ";
	cin>>vertex;
	
	int adjMat[vertex][vertex];
	
	for(int i=0;i<vertex;i++){
		for(int j=0;j<vertex;j++){
			adjMat[i][j] = 0;
		}
	}
	
	cout<<"Input anything else to exit and print the adjacency matrix.\n";
	cout<<"Add edges (from and to):\n";
	int from,to;
	while(cin>>from>>to){
		if((from >= vertex || from < 1) || (to >= vertex || to < 1)){
			cout<<"Warning: Out of bound index.\n";
		}if(adjMat[from-1][to-1]==1){
			cout<<"Edge is present already.\n";
		}else{
			addEdge(&adjMat[--from][--to]);
		}
	}
	
	cout<<"\n";
	for(int i=0;i<vertex;i++){
		for(int j=0;j<vertex;j++){
			cout<<adjMat[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}*/
