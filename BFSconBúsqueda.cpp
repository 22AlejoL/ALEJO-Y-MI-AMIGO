#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class GraphVisitor;

// Interface para los elementos del grafo
class GraphElement {
public:
    virtual void accept(GraphVisitor &visitor) = 0;
};

// Interface para el visitante
class GraphVisitor {
public:
    virtual void visit(class Node &node) = 0;
};

class Node : public GraphElement {
public:
    int id;
    vector<int> neighbors;

    Node(int id) : id(id) {}

    void addNeighbor(int neighbor) {
        neighbors.push_back(neighbor);
    }

    void accept(GraphVisitor &visitor) override {
        visitor.visit(*this);
    }
};

// Clase `DFSVisitor` que implementa `GraphVisitor` para el recorrido completo
class DFSVisitor : public GraphVisitor {
public:
    void visit(Node &node) override {
        cout << node.id << " ";
    }
};

// Clase `SearchVisitor` que implementa `GraphVisitor` y busca un nodo específico
class SearchVisitor : public GraphVisitor {
public:
    int target;
    bool found;
    vector<int> path;

    SearchVisitor(int target) : target(target), found(false) {}

    void visit(Node &node) override {
        path.push_back(node.id);
        if (node.id == target) {
            found = true;
        }
    }

    void printPath() {
        for (int id : path) {
            cout << id << " ";
        }
    }
};

// Estructura de datos para almacenar un borde de grafo
struct Edge {
    int src, dest;
};

// Una clase para representar un objeto grafo
class Graph {
public:
    vector<Node> nodes;

    Graph(int n) {
        for (int i = 0; i < n; i++) {
            nodes.push_back(Node(i));
        }
    }

    void addEdge(int src, int dest) {
        nodes[src].addNeighbor(dest);
        nodes[dest].addNeighbor(src);
    }

    void DFS(Node &node, vector<bool> &discovered, GraphVisitor &visitor) {
        discovered[node.id] = true;
        node.accept(visitor);

        for (int neighbor : node.neighbors) {
            if (!discovered[neighbor]) {
                DFS(nodes[neighbor], discovered, visitor);
            }
        }
    }

    bool DFS(Node &node, vector<bool> &discovered, SearchVisitor &visitor) {
        discovered[node.id] = true;
        node.accept(visitor);

        if (visitor.found) {
            return true;
        }

        for (int neighbor : node.neighbors) {
            if (!discovered[neighbor]) {
                if (DFS(nodes[neighbor], discovered, visitor)) {
                    return true;
                }
            }
        }
        return false;
    }

    void BFS(Node &startNode, vector<bool> &discovered, GraphVisitor &visitor) {
        queue<Node*> q;

        discovered[startNode.id] = true;
        startNode.accept(visitor);
        q.push(&startNode);

        while (!q.empty()) {
            Node *v = q.front();
            q.pop();

            for (int neighbor : v->neighbors) {
                if (!discovered[neighbor]) {
                    discovered[neighbor] = true;
                    nodes[neighbor].accept(visitor);
                    q.push(&nodes[neighbor]);
                }
            }
        }
    }

    bool BFS(Node &startNode, vector<bool> &discovered, SearchVisitor &visitor) {
        queue<Node*> q;

        discovered[startNode.id] = true;
        startNode.accept(visitor);
        q.push(&startNode);

        while (!q.empty()) {
            Node *v = q.front();
            q.pop();

            if (visitor.found) {
                return true;
            }

            for (int neighbor : v->neighbors) {
                if (!discovered[neighbor]) {
                    discovered[neighbor] = true;
                    nodes[neighbor].accept(visitor);
                    q.push(&nodes[neighbor]);

                    if (visitor.found) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    void traverseBFS(GraphVisitor &visitor) {
        vector<bool> discovered(nodes.size(), false);

        for (Node &node : nodes) {
            if (!discovered[node.id]) {
                BFS(node, discovered, visitor);
            }
        }
    }

    void traverseBFS(SearchVisitor &visitor) {
        vector<bool> discovered(nodes.size(), false);

        for (Node &node : nodes) {
            if (!discovered[node.id]) {
                if (BFS(node, discovered, visitor)) {
                    break;
                }
            }
        }
    }
};

int main() {
    // número total de nodos en el grafo (etiquetados de 0 a 12)
    int n = 13;
    Graph graph(n);

    // vector de los bordes del grafo según el diagrama anterior
    vector<Edge> edges = {
        // Observe que el nodo 0 no está conectado
        {1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
        {3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}
    };

    // agregar bordes al grafo
    for (auto &edge : edges) {
        graph.addEdge(edge.src, edge.dest);
    }

    // Crear un visitante BFS para el recorrido completo
    DFSVisitor fullVisitor;
    cout << "El recorrido completo del grafo es: ";
    graph.traverseBFS(fullVisitor);
    cout << endl;

    // nodo a buscar
    int target = 5;
    SearchVisitor searchVisitor(target);

    // realizar el recorrido BFS usando el SearchVisitor
    cout << "El recorrido hasta encontrar el valor es: ";
    graph.traverseBFS(searchVisitor);
    searchVisitor.printPath();
    cout << endl;

    if (searchVisitor.found) {
        cout << "Node " << target << " found." << endl;
    } else {
        cout << "Node " << target << " not found." << endl;
    }

    return 0;
}
