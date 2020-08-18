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
        bool is_tree(){
            bool *visited = new bool[V];
            int *parent = new int[V];

            queue<int> q;
            for(int i=0; i<V; i++){
                visited[i] = false;
                parent[i] = i;
            }
            int src = 0;
            q.push(src);
            visited[src] = true;

            //pop out one node and visit its nbrs
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int nbr: l[node]){
                    if(visited[nbr] == true and parent[node]!= nbr){
                        return false;
                    }
                    else if(!visited[nbr]){
                        visited[nbr] = true;
                        parent[nbr] = node;
                        q.push(nbr);
                    }
                }
            }
            return true;
        }
};

int main() {

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(3, 2);
    g.addEdge(1, 2);
    g.addEdge(0, 3);

    if(g.is_tree()){
        cout << "Yes it is a tree" << endl;
    }
    else{
        cout << "No it is not a tree" << endl;
    }

    return 0;
}
