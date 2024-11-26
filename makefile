shortestPath: main.cpp
	g++ main.cpp -o shortestPath

clean:
	rm ./shortestPath

run: shortestPath
	./shortestPath
