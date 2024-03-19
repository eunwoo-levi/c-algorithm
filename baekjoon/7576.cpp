// 백준 7576 - 토마토 문제
#include <bits/stdc++.h>
using namespace std;

int n,m,x,y, res;
int A[1001][1001], visited[1001][1001];
const int dy[4] = {-1,0,1,0},dx[4] = {0,1,0,-1};
queue<pair<int,int>> Q;

int main(){
    cin >> m >> n;

    int flag = 0;

    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin >> A[i][j];
            if(A[i][j]==1){
                visited[i][j] = 1;
                Q.push({i,j});
            }
            if(A[i][j]==0)  flag=1;
        }
    }

    if(flag==0){
        cout << "0";
        return 0;
    }

    while(!Q.empty()){
        tie(y,x) = Q.front();
        Q.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny<0||ny>=n||nx<0||nx>=m)   continue;
            if(visited[ny][nx] || A[ny][nx] == -1)  continue;
            visited[ny][nx] = visited[y][x] + 1;
            res = max(res, visited[ny][nx]);
            Q.push({ny,nx});
        }
    }

    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(A[i][j]==0 && visited[i][j] == 0){
                cout << "-1";
                return 0;
            }
        }
    }


    cout << res-1;
    return 0;
}