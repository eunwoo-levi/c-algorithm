// 숨바꼭질 - bfs
#include <bits/stdc++.h>
using namespace std;

int n,m;
int visited[100001], cnt[100001];
queue<int> Q;                       // 가장 빠른 시간 -> BFS

int main(){
    
    cin >> n >> m;

    if(n == m){                    // 반례
        puts("0"); puts("1");
        return 0; 
    } 

    visited[n] = 1;
    cnt[n] = 1;

    Q.push(n);
    while(!Q.empty()){
        int now = Q.front();            // 1차원
        Q.pop();
        
        for(int next : {now-1, now+1, 2*now}){
            if(0<=next && next <=100000){           // next 조건 (오버플로우)
                if(!visited[next]){
                    Q.push(next);
                    visited[next] = visited[now] + 1;
                    cnt[next] += cnt[now];
                }
                else if(visited[next] == visited[now] + 1){
                    cnt[next] += cnt[now];
                }
            }
        }
    }

    cout << visited[m] - 1 << '\n';     // 시간을 1부터 시작했으므로 마지막에 -1 해야함
    cout << cnt [m] << '\n';
    return 0;
    

}