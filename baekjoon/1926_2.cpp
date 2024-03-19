// 백준 1926 - 풀이 2 (BFS)
#include <bits/stdc++.h>
using namespace std;

int n,m, res_1, res_2=-1e9;
int A[501][501], visited[501][501];
const int dy[4] = {-1, 0 , 1 , 0}, dx[4] = {0,1,0,-1};
queue<pair<int,int>> Q;

int bfs(int y, int x){
    int cnt = 1;
    visited[y][x] = 1;
    Q.push({y,x});

    while(!Q.empty()){
        tie(y,x) = Q.front();
        Q.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny<0||ny>=n || nx<0 || nx>=m)    continue;
            if(visited[ny][nx] || A[ny][nx] == 0)   continue;
            cnt++;
            visited[ny][nx] = 1;
            Q.push({ny,nx});
        }
    }

    return cnt;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin >> A[i][j];
        }
    }



     for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(!visited[i][j] && A[i][j]==1){

                res_1++;
                res_2 = max(res_2,bfs(i,j));
            }
        }
    }



    cout << res_1 << "\n";
    cout << res_2 << "\n";
    
    return 0;
}