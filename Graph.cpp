
#include "Graph.h"
int Graph::getNumVert() {
    return numVert;
}
std::vector<Node*> Graph::getAdjList() {
    return adjList;
}
Graph::~Graph() {
    std::cout << "\n~Graph()\n";
    for (auto p : adjList)
    {
        Node* current = p;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    adjList.clear();

}
Graph::Graph(): numVert(-1){}
//for quickly making presentation graph
//this algorithm relies on all the vectos being the same as the numbers 
//on the index+1 
Graph::Graph(int vert, std::vector<Edge>edgy): numVert(vert) {
    //init list by pushing back vert nodes into list 
    std::cout << "\nGraph(int,vector)\n";
    for (int i = 0; i < numVert; i++) {
        adjList.push_back(new Node{ i });
    }
    for (auto edge : edgy) {
        Node* end=nullptr;
        if (adjList.at(edge.a)->next == nullptr) {
            adjList.at(edge.a )->next = new Node{ edge.b };
        }
        else {
            end = traverseLinkedList(adjList.at(edge.a ));
            end->next = new Node{ edge.b };
        }
        if (adjList.at(edge.b )->next == nullptr) {
            adjList.at(edge.b )->next = new Node{ edge.a };
        }
        else {
            end = traverseLinkedList(adjList.at(edge.b));
            end->next = new Node{ edge.a };
        }
    }
}

void Graph::print() {//for testing 
    for (auto node : adjList) {
        
        printLinkedList(node);
    }
}
void printLinkedList(Node* head) {//for testing
    Node* current = head;

    while (current != nullptr) {
        // Access the data at the current node
        std::cout << current->vertex << " ";

        // Move to the next node
        current = current->next;
    }

    std::cout << std::endl;
}
Node* traverseLinkedList(Node* &head) {
    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }
    return current;

}
Graph createGraph() {
    int size;
    std::vector<Edge>edgy;
    int i=1;
    bool run=true;
    std::cout << "Calling createGraph()..." << std::endl;
    std::cout << "    Enter size of Graph: ";
    std::cin >> size;
    while (run) {
        int a;
        int b;
        std::cout << "\nCreate edge #"<<i<<"(input -1 to end,no duplicates)";
        std::cout << "\n    vertex a: ";
        std::cin >> a;
        if (a < 0) {
        std::cout << "\nENDING LOOP";
        break;
        }
        while (a > size) {
            std::cout << "\n number not in vertex list try again:";
            std::cout << "\n    vertex a: ";
            std::cin >> a;
        }
        std::cout << "\n    vertex b: ";
        std::cin >> b;
        if (b < 0) {
            std::cout << "\nENDING LOOP";
            break;
        }
        while(b > size) {
            std::cout << "\n number not in vertex list try again:";
            std::cout << "\n    vertex b: ";
            std::cin >> b;
        }
        edgy.push_back({a,b});
        i++;
    }
    return Graph(size,edgy);


}
void BFS(Graph& G, int s) {
    for (auto node : G.adjList) {
        node->color = "white";
        node->d = -1;
        node->pi = nullptr;
    }
    G.adjList.at(s)->color = "gray";
    G.adjList.at(s)->d = 0;
    std::queue<Node*> q;
    q.push(G.adjList.at(s));
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            Node* u = q.front();
            q.pop();

            std::cout << u->vertex << " ";

            Node* head = u->next;
            while (head != nullptr) {
                Node* intermediate = G.adjList.at(head->vertex);
                if (intermediate->color == "white") {
                    intermediate->color = "gray";
                    intermediate->d = u->d + 1;
                    intermediate->pi = u;
                    q.push(intermediate);
                }
                head = head->next;
            }

            u->color = "black";
        }
        std::cout << std::endl;
    }
}
void printPath(Graph& G, int s, int v) {
    if (s==v) {
        std::cout << s;
    }
    else if (G.adjList.at(v)->pi==nullptr) {
        std::cout << "\nNo path from " << s << " to " << v << " exists" << std::endl;
    }
    else {
        printPath(G,s, G.adjList.at(v )->pi->vertex);
        std::cout << "->" <<v ;
    }

}