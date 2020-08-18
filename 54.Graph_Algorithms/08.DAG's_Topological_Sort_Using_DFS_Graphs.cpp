#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {

    map<T, list<T>> l;
    public:
        void addEdge(int x, int y){
            l[x].push_back(y);
        }

        void bfs(T src){
            map<T, int> visited;
            queue<T> q;
            q.push(src);
            visited[src] = true;

            while(!q.empty()){
                T node = q.front();
                q.pop();
                cout << node << " ";
                for(int nbr: l[node]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        //mark that nbr as visited
                        visited[nbr] = true;
                    }
                }
            }
        }

        void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering){
            //Recursive function that will traverse the graph

            cout << src << " ";
            visited[src] = true;

            //go to all nbr of that node that is not visited
            for(T nbr: l[src]){
                if(!visited[nbr]){
                    dfs_helper(nbr, visited, ordering);
                }
            }
            ordering.push_front(src);
            return;
        }

        void dfs(){
            map<T, bool> visited;
            list<T> ordering;
            //Mark all the nodes as not visited in the beginning
            for(auto p: l){
                T node = p.first;
                visited[node] = false;
            }

            //Iterate over all the vertices and init a dfs call
            for(auto p: l){
                T node = p.first;
                if(!visited[node]){
                    dfs_helper(node, visited, ordering);
                }
            }
            for(auto node: ordering){
                cout << node << endl;
            }
        }
};



int main() {

    Graph<int> g;
    g.addEdge("Python", "Data PreProcessing");
    g.addEdge("Python", "Pytorch");
    g.addEdge("Python", "ML");
    g.addEdge("Data PreProcessing", "ML");
    g.addEdge("PyTorch", "DL");
    g.addEdge("ML", "DL");
    g.addEdge("DL", "FaceRecogn");
    g.addEdge("DataSet", "FaceRecogn");
    g.dfs();

    return 0;
}
