#include<bits/stdc++.h>
using namespace std;

template<typename T>
//Directed Graph
class Graph {

    map<T, list<T>> l;
    public:
        void addEdge(int x, int y){
            l[x].push_back(y);
        }
        T bfs(T src, T dest){
            map<T, int> dist;
            map<T, T> parent;
            queue<T> q;

            //All other nodes will have INT_MAX

            for(auto node_pair: l){
                T node = node_pair.first;
                dist[node] = INT_MAX;
            }
            q.push(src);
            dist[src] = 0;
            parent[src] = src;
            while(!q.empty()){
                T node = q.front();
                q.pop();

                for(int nbr: l[node]){
                    if(dist[nbr] == INT_MAX){
                        q.push(nbr);
                        //mark that nbr as visited
                        dist[nbr] = dist[node] + 1;
                        parent[nbr] = node;
                    }
                }
            }

            //Print the dest to source node
            //Dest to src
            T temp = dest;
            while(temp != src){
                cout << temp << "<--";
                temp = parent[temp];
            }
            cout << src << endl;

            return dist[dest];
        }
};

int main() {

    int board[50] = {0};
    board[2] = 13; //It means ladder from 3 to 15 = 1(on dice) + 15(to 15) - 3(from 3)
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    //Add Edges to the Graph
    Graph<int> g;
    for(int i=0; i<37; i++){
        for(int dice = 1; dice<=6; dice++){
            int j = i + dice;
            j += board[j];

            if(j <= 36){
                g.addEdge(i, j);
            }
        }
    }
    g.addEdge(36, 36);
    cout << g.bfs(0, 36) << endl;

    return 0;
}
