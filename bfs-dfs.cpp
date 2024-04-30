#include<bits/stdc++.h>
using namespace std;

void dfs(int vert, vector<int> vec[], vector<int> &vis) {
    vis[vert] = 1;
    cout<<vert<<" ";
    for(auto child : vec[vert]) {
        if(!vis[child]) {
            dfs(child, vec, vis);
        }
    }
}

void bfs(int source, vector<int> vec[], vector<int> &vis) {
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        cout<<curr<<" ";
        for(int child : vec[curr]) {
            if(!vis[child]) {
                q.push(child);
                vis[child] = 1;
            }
        }
    }
}

int main() {
    int n, e;
    cin>>n;
    cin>>e;
    vector<int> vec[n];
    vector<int> vis(n, 0);
    for(int i=0; i<e; i++) {
        int u, v;
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u); // for undirected graph
    }

    dfs(0, vec, vis);

	return 0;
}