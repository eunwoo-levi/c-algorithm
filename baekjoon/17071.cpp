#include <bits/stdc++.h>
using namespace std;

int n,k,ok, turn=1;
int visited[2][500001]; // [2] 는 홀수와 짝수 구별하기 위함 -> 수빈이가 방문했는지 확인하는 배열
queue<int> Q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    if(n==k){
        cout << "0";
        return 0;
    }

    visited[0][n] = 1;
    Q.push(n);

    while(!Q.empty()){
        k += turn;                  // k +1 +2 +3 +4 ..... 구현
        if(k>500000)  break;

        if(visited[turn%2][k]){     // 수빈이가 (홀, 짝) 방문하였는지 체크
            ok = true;
            break;
        }

        int qSize = Q.size();
        for(int i = 0; i < qSize; i++){             // 플러드필 알고리즘
            int x = Q.front(); 
            Q.pop();
			for(int nx : {x + 1, x - 1, x * 2}){
                if(nx < 0 || nx > 500000 || visited[turn % 2][nx]) continue;

                visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1; 
                if(nx == k){
                    ok = 1; 
                    break;
                }
                Q.push(nx); 
			} 
			if(ok)  break;
        }
        if(ok)  break;
        turn++;
    }

    if(ok) cout << turn;
    else cout << "-1";
    return 0;
}