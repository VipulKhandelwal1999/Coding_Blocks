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

        void dfs(){
            map<T, bool> visited;
            //Mark all the nodes as not visited in the beginning
            for(auto p: l){
                T node = p.first;
                visited[node] = false;
            }

            //Iterate over all the vertices and init a dfs call
            int cnt = 0;
            for(auto p: l){
                T node = p.first;
                if(!visited[node]){
                    cout << "Component " << cnt << " -->";
                    dfs_helper(node, visited);
                    cnt++;
                    cout << endl;
                }
            }
        }
};



int main() {

    Graph<int> g;
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 1);
    g.addEdge(5, 3);
    g.dfs();

    return 0;
}
