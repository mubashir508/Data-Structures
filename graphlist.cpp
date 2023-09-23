#include <iostream>
#include <vector>

class Graph {
private:
    int numVertices;
    bool isDirected;
    std::vector<std::vector<int>> adjacencyMatrix;

public:
    Graph(int vertices, bool directed) {
        numVertices = vertices;
        isDirected = directed;
        adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
    }

    void InsertEdge(int u, int v, int weight) {
        if (u < 0 || u >= numVertices || v < 0 || v >= numVertices) {
            std::cout << "Invalid vertex indices." << std::endl;
            return;
        }

        adjacencyMatrix[u][v] = weight;
        if (!isDirected) {
            adjacencyMatrix[v][u] = weight;
        }
    }

    void PrintGraph() {
        std::cout << "Adjacency Matrix:" << std::endl;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjacencyMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    bool IsConnected(int u, int v) {
        if (u < 0 || u >= numVertices || v < 0 || v >= numVertices) {
            std::cout << "Invalid vertex indices." << std::endl;
            return false;
        }

        return adjacencyMatrix[u][v] != 0;
    }
};

int main() {
    int numVertices;
    char graphType;
    std::cout << "Enter the number of vertices: ";
    std::cin >> numVertices;

    std::cout << "Is the graph directed? (y/n): ";
    std::cin >> graphType;

    bool directed = (graphType == 'y' || graphType == 'Y');
    Graph graph(numVertices, directed);

    int u, v, weight;
    while (true) {
        std::cout << "Enter edge (u v weight), or -1 to stop: ";
        std::cin >> u;
        if (u == -1) {
            break;
        }
        std::cin >> v >> weight;
        graph.InsertEdge(u, v, weight);
    }

    graph.PrintGraph();

    int source, destination;
    std::cout << "Enter source and destination vertices: ";
    std::cin >> source >> destination;
    bool connected = graph.IsConnected(source, destination);
    if (connected) {
        std::cout << "There is a connection between vertex " << source << " and vertex " << destination << std::endl;
    } else {
        std::cout << "There is no connection between vertex " << source << " and vertex " << destination << std::endl;
    }

    return 0;
}
