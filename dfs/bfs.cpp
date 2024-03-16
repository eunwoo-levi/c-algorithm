#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,m,k, a, b, visited[1001];
vector<int> V[1001];

void dfs(int u){
    visited[u] = 1;

    cout << u << " ";
    for(int i=0; i<V[u].size();i++){        
        sort(V[u].begin(), V[u].end());
        int idx = V[u][i];
        if(!visited[idx])   dfs(idx);
    }
}

void bfs(int u){
    queue<int> Q;
    Q.push(u);
    visited[u]= 1;
    
    while(!Q.empty()){
        u = Q.front();
        Q.pop();

        cout << u << " ";

        for(int i=0; i<V[u].size(); i++){
            int idx = V[u][i];
            if(!visited[idx]){
                visited[idx]=1;
                Q.push(idx);
            }
        }

    }
}

int main(){
    cin >> n >> m>> k;

    for(int i=0; i<m; i++){
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    dfs(k);
    fill(visited,visited+1001, 0);
    cout << "\n";
    bfs(k);
}