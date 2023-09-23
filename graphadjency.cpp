#include <iostream>
#include <vector>

class Graph {
private:
    int numVertices;
    bool isDirected;
    std::vector<std::vector<std::pair<int, int>>> adjacencyList;

public:
    Graph(int vertices, bool directed) {
        numVertices = vertices;
        isDirected = directed;
        adjacencyList.resize(numVertices);
    }

    void InsertEdge(int u, int v, int weight) {
        if (u < 0 || u >= numVertices || v < 0 || v >= numVertices) {
            std::cout << "Invalid vertex indices." << std::endl;
            return;
        }

        adjacencyList[u].emplace_back(v, weight);
        if (!isDirected) {
            adjacencyList[v].emplace_back(u, weight);
        }
    }

    void PrintGraph() {
        std::cout << "Adjacency List:" << std::endl;
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Vertex " << i << ": ";
            for (const auto& edge : adjacencyList[i]) {
                std::cout << "(" << edge.first << ", " << edge.second << ") ";
            }
            std::cout << std::endl;
        }
    }

    bool IsConnected(int u, int v) {
        if (u < 0 || u >= numVertices || v < 0 || v >= numVertices) {
            std::cout << "Invalid vertex indices." << std::endl;
            return false;
        }

        for (const auto& edge : adjacencyList[u]) {
            if (edge.first == v) {
                return true;
            }
        }

        return false;
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
