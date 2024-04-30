#include<bits/stdc++.h>
using namespace std;

void gbfs(int src, int dest, vector<int> vec[], vector<int> &hVal, vector<int> &vis, vector<int> &par) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({hVal[src], src});
    bool flag = false;
    while(!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        int h = p.first;
        int vert = p.second; 
        vis[vert] = 1;
        for(auto child : vec[vert]) {
            if(!vis[child]) {
                pq.push({hVal[child], child});
                par[child] = vert;
            }
        }

        if(vert == dest) {
            flag = true;
            break;
        }
    }

    if(flag == false) {
        cout<<"Goal Not Found!\n";
    }
    else {
        vector<int> path;
        while(dest != -1) {
            path.push_back(dest);
            dest = par[dest];
        }
        cout<<"Goal Found\n";
        reverse(path.begin(), path.end());
        cout<<"Path:\n";
        for(auto &it : path) cout<<it<<" -> ";
    }
}

int main() {
    int n, e;
    cin>>n;
    cin>>e;
    vector<int> hVal(n);
    for(int i=0; i<n; i++) {
        cin>>hVal[i];
    }
    vector<int> vec[n];
    vector<int> vis(n, 0);
    vector<int> par(n, -1);
    for(int i=0; i<e; i++) {
        int u, v;
        cin>>u>>v;
        vec[u].push_back(v);
        // vec[v].push_back(u); // for undirected graph
    }

    gbfs(0, 6, vec, hVal, vis, par);

	return 0;
}