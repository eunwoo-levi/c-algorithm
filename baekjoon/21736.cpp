#include <bits/stdc++.h>
using namespace std;

int n,m, a,b,cnt,res;
char A[604][604];
int visited[604][604];
const int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
queue<pair<int,int>> Q;

int bfs(int y, int x){
    visited[y][x] = 1;
    Q.push({y,x});

    while(!Q.empty()){
        tie(y,x) = Q.front();
        Q.pop();

        if(A[y][x] == 'P')  cnt++;

        for(int i=0; i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny<0 || ny>=n || nx<0 || nx>=m)    continue;
            if(A[ny][nx] == 'X' || visited[ny][nx])    continue;
            visited[ny][nx] = 1;
            Q.push({ny,nx});
        }
    }

    return cnt;
}

int main(){
    cin >> n >> m;

    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin >> A[i][j];
            if(A[i][j]=='I')    tie(a,b) = {i,j};
        }
    }

    res = bfs(a,b);

    if(res == 0){
        cout << "TT";
        return 0;
    }
    
    cout << res;

    return 0;
}