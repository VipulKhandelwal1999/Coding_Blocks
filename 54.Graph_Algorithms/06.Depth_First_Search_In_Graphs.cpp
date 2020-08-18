#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {

    map<T, list<T>> l;
    public:
        void addEdge(int x, int y){
            l[x].push_back(y);
            l[y].push_back(x);
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

        void dfs_helper(T src, map<T, bool> &visited){
            //Recursive function that will traverse the graph

            cout << src << " ";
            visited[src] = true;

            //go to all nbr of that node that is not visited
            for(T nbr: l[src]){
                if(!visited[nbr]){
                    dfs_helper(nbr, visited);
                }
            }
        }

        void dfs(T src){
            map<T, bool> visited;
            //Mark all the nodes as not visited in the beginning
            for(auto p: l){
                T node = p.first;
                visited[node] = false;
            }
            //call the helper function
            dfs_helper(src, visited);
        }
};



int main() {

    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.dfs(0);

    return 0;
}
