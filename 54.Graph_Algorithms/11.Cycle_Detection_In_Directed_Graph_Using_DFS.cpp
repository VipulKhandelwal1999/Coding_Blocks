#include<bits/stdc++.h>
using namespace std;

//Check if a Undirected Graph is a Tree or not
//We just have to detect any cycle
//If cycle is there there it is not a tree

class Graph {
    list<int> *l;
    int V;

    public:
        Graph(int V){
            this->V = V;
            l = new list<int>[V];
        }
        void addEdge(int x, int y){
            //directed Graph
            l[x].push_back(y);
        }

        bool cycle_helper(int node, bool *visited, bool *stack){
            //visit a node
            visited[node] = true;
            stack[node] = true;

            for(int nbr: l[node]){
                //two cases
                if(stack[nbr] == true){
                    return true;
                }
                else if(visited[nbr] == false){
                    bool cycle_mila = cycle_helper(nbr, visited, stack);
                    if(cycle_mila == true){
                        return true;
                    }
                }
            }

            //leave a node
            stack[node] = false;
            return false;
        }

        bool contains_cycle() {
            //Check for Cycle in Directed Graph
            bool *visited = new bool[V];
            bool *stack = new bool[V];

            for(int i=0; i<V; i++){
                visited[i] = stack[i] = false;
            }

            return cycle_helper(0, visited, stack);
        }
};

int main() {

    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(1, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 2); // Back Edge

    if(g.contains_cycle()){
        cout << "Yes contains cycle";
    }
    else{
        cout << "Not doesn't contain cycle";
    }

    return 0;
}
