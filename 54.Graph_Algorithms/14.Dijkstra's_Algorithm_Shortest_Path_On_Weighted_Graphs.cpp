#include<bits/stdc++.h>
using namespace std;

//Dijkstra's / Single Source Shortest Path Algorithm

template<typename T>
class Graph{
    unordered_map<T, list<pair<T,int> > > m;

public:

    void addEdge(T u,T v,int dist, bool bidir = true)
    {
        m[u].push_back(make_pair(v,dist));
        if(bidir){
            m[v].push_back(make_pair(u,dist));
        }

    }
    void printAdj()
    {
        //Let's try to print the adj List
        //Iterate over all the key value pairs in the map
        for(auto j:m)
            {
                cout << j.first << "->";

                //Iterate over the list of cities
                for(auto l: j.second)
                    cout << "(" << l.first << "," << l.second << ")";

                cout<<endl;
            }
    }

    void dijsktra(T src)
    {
        unordered_map<T,int> dist;

        //Set all distance to infinity
        for(auto j:m){
            dist[j.first] = INT_MAX;
        }

        //Make a set to find out node with the minimum distance
        set<pair<int, T> > s;

        dist[src] = 0;
        s.insert(make_pair(0,src));

        while(!s.empty())
        {
            //Find the pair at the front
            auto p =   *(s.begin());
            T node = p.second;

            int nodeDist = p.first;
            s.erase(s.begin());

            //Iterate over neighbours/children of the current node
            for(auto childPair: m[node])
            {
                if(nodeDist + childPair.second < dist[childPair.first])
                {
                    //In the set updation of a particular is not possible
                    //we have to remove the old pair and insert the new pair to simulation updation
                    T dest = childPair.first;
                    auto f = s.find( make_pair(dist[dest],dest));

                    if(f != s.end())
                        s.erase(f);

                    //Insert the new pair
                    dist[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest],dest));

                }
            }
        }

        cout<<"\nShortest distance from "<<src<<" : \n";
        for(auto d:dist){
            cout << d.first << " is located at distance of " << d.second << endl;
        }
    }

};

int main()
{
    Graph<int> g;
//    g.addEdge(1,4,60);
//    g.addEdge(1,5,70);
//    g.addEdge(1,7,120);
//    g.addEdge(1,2,10);
//
//    g.addEdge(2,3,20);
//    g.addEdge(2,5,30);
//
//    g.addEdge(3,4,170);
//
//    g.addEdge(4,5,80);
//    g.addEdge(4,7,70);
//
//    g.addEdge(5,6,50);
//    g.addEdge(5,7,150);
//
//    g.addEdge(6,1,100);
//
//    g.addEdge(7,3,40);

    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);


    g.printAdj();

    g.dijsktra(1);
//    g.dijsktra(2);
//    g.dijsktra(3);
//    g.dijsktra(4);

 return 0;
}

