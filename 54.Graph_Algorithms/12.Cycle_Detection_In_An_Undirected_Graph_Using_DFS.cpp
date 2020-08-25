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
            l[y].push_back(x);
        }

        bool cycle_helper(int node, bool *visited, int parent){
            visited[node] = true;

            for(auto nbr: l[node]){
                //two cases
                if(!visited[nbr]){
                    //go and recursively visit the nbr
                    bool cycle_mila = cycle_helper(nbr, visited, node);
                    if(cycle_mila){
                        return true;
                    }
                }
                //nbr is visited but nbr should not be equal to parent
                else if(nbr != parent){
                    return true;
                }

            }
            return false;
        }

        bool contains_cycle(){
            //Check for cycle in Directed Graph
            bool *visited = new bool[V];
            for(int i=0; i<V; i++){
                visited[i] = false;
            }
            return cycle_helper(0, visited, -1);
        }
};

int main() {

    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    if(g.contains_cycle()){
        cout << "Yes undirected graph contains cycle" << endl;
    }
    else{
        cout << "No undirected graph does not contain cycle" << endl;
    }

    return 0;
}
