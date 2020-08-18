#include<bits/stdc++.h>
using namespace std;

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
        void topological_sort(){

            //indegree
            int *indegree = new int[V];
            //O indegree
            for(int i=0; i<V; i++){
                indegree[i] = 0;
            }
            //update indegree by traversing edges from x->y
            //indegree[y]++
            for(int i=0; i<V; i++){
                for(auto y: l[i]){
                    indegree[y]++;
                }
            }
            //bfs
            queue<int> q;
            //1.step find nodes with 0 indegree
            for(int i=0; i<V; i++){
                if(indegree[i] == 0){
                    q.push(i);
                }
            }

            //start removing elements from the queue
            while(!q.empty()){
                int node = q.front();
                cout << node << " ";
                q.pop();
                //iterate over nbrs of that node and reduce the indegree by 1
                for(auto nbrs: l[node]){
                    indegree[nbrs]--;
                    if(indegree[nbrs] == 0){
                        q.push(nbrs);
                    }
                }
            }
        }
};

int main() {

    Graph g(6);
    g.addEdge(0, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 2);
    g.addEdge(4, 5);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(3, 5);

    g.topological_sort();

    return 0;
}
