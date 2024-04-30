#include<bits/stdc++.h>
using namespace std;

void ucs(int src, int dest, vector<pair<int, int>> vec[], vector<int> &dist, vector<int> &par) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        int cost = p.first;
        int source = p.second;
        for(auto child : vec[source]) {
            int destination = child.first; 
            int childCost = child.second;
            if(cost + childCost < dist[destination]) {
                dist[destination] = cost + childCost;
                pq.push({cost + childCost, destination});
                par[destination] = source;
            }
        }
    }

    cout<<src<<" -> "<<dest<<" = "<<dist[dest]<<"\n";

    vector<int> path;
    while(dest != -1) {
        path.push_back(dest);
        dest = par[dest];
    }
    reverse(path.begin(), path.end());
    cout<<"Path:\n";
    for(auto &it : path) cout<<it<<" -> ";
}

int main() {
    int n, e;
    cin>>n;
    cin>>e;
    vector<pair<int, int>> vec[n];
    vector<int> dist(n, 1e5);
    vector<int> par(n, -1);
    for(int i=0; i<e; i++) {
        int u, v, c;
        cin>>u>>v>>c;
        vec[u].push_back({v, c});
        // vec[v].push_back({u, c}); // for undirected graph
    }

    ucs(0, 5, vec, dist, par);

	return 0;
}