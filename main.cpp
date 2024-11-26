#include <iostream>
#include <limits>

const int numNodes = 16;
const double INF = std::numeric_limits<double>::infinity();

void dijkstra(double graph[numNodes][numNodes], double distances[], int previous[]){
	//tracking what nodes have been visited
	bool visited[numNodes] = {false};
	//assigning infinity distance to all nodes
	for(int i=0; i<numNodes; ++i){
		distances[i] = INF;
		previous[i] = -1;
	}
	//set initial node to zero distance
	distances[0] = 0.0;
	for(int i=0; i<numNodes; ++i){
		double minDistance = INF;
		int currentNode = -1;
		for(int j=0; j<numNodes; ++j){
			if(!visited[j] && distances[j] < minDistance){
				minDistance = distances[j];
				currentNode = j;
			}
		}
		if(currentNode == -1){
			i = numNodes;
			continue;
		}
		visited[currentNode] = true;
		for(int n=0; n<numNodes; ++n){
			if(!visited[n] && graph[currentNode][n] != INF){
				double newDistance = distances[currentNode] + graph[currentNode][n];
				if(newDistance < distances[n]){
					distances[n] = newDistance;
					previous[n] = currentNode;
				}
			}
		}
	}
}
//Show the path of nodes
void printPath(int previous[], int destination){
	if(previous[destination] == -1){
		std::cout << destination;
		return;
	}
	printPath(previous, previous[destination]);
	std::cout << " -> " << destination;
}

int main(){
	double graph[numNodes][numNodes];
	for(int i=0; i<numNodes; ++i){
		for(int j=0; j<numNodes; ++j){
			graph[i][j] = INF;
		}
	}
	//populating the graph
	graph[0][1] = 0.32;
	graph[0][2] = 0.4;
	graph[1][4] = 0.4;
	graph[2][3] = 0.1;
	graph[2][5] = 0.2;
	graph[3][4] = 0.08;
	graph[3][6] = 0.2;
	graph[4][7] = 0.2;
	graph[5][6] = 0.1;
	graph[5][8] = 0.28;
	graph[6][7] = 0.05;
	graph[6][8] = 0.15;
	graph[7][9] = 0.35;
	graph[8][9] = 0.25;
	graph[9][10] = 0.2;
	graph[9][11] = 0.3;
	graph[9][13] = 0.3;
	graph[10][11] = 0.2;
	graph[11][12] = 0.28;
	graph[11][14] = 0.05;
	graph[12][15] = 0.2;
	graph[13][14] = 0.45;
	graph[14][15] = 0.3;
	//Add reverses
	for(int i=0; i<numNodes; ++i){
		for(int j=0; j<numNodes; ++j){
			if(graph[i][j] != INF){
				graph[j][i] = graph[i][j];
			}
		}
	}
	double distances[numNodes];
	int previous[numNodes];
	dijkstra(graph, distances, previous);
	std::cout << "Shortest distance from A to B: " << distances[15] << "\n";
	std::cout << "Path: ";
	printPath(previous, 15);
	std::cout << "\n";
	return 0;
}
