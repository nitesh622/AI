#include<bits/stdc++.h>
using namespace std;

void aStar(int src, int dest, vector<pair<int, int>> vec[], vector<int> &hVal, vector<int> &dist, vector<int> &par) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = hVal[src];
    pq.push({hVal[src], src});
    while(!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        int cost = p.first;
        int source = p.second;
        for(auto child : vec[source]) {
            int destination = child.first; 
            int childCost = child.second;
            int newCost = cost + childCost + hVal[destination] - hVal[source];
            if(newCost < dist[destination]) {
                dist[destination] = newCost;
                pq.push({newCost, destination});
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
    vector<int> hVal(n);
    for(int i=0; i<n; i++) {
        cin>>hVal[i];
    }
    vector<pair<int, int>> vec[n];
    vector<int> dist(n, 1e5);
    vector<int> par(n, -1);
    for(int i=0; i<e; i++) {
        int u, v, c;
        cin>>u>>v>>c;
        vec[u].push_back({v, c});
        // vec[v].push_back({u, c}); // for undirected graph
    }

    aStar(0, 5, vec, hVal, dist, par);

	return 0;
}