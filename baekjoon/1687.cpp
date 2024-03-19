// 1687 - 숨바꼭질
#include <bits/stdc++.h>
using namespace std;

int n,k, res=1e9;
int A[100001], visited[100001];
queue<int> Q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;

    if(n==k){
        cout << "0";
        return 0;
    }

    visited[n] = 1;
    Q.push(n);

    while(!Q.empty()){
        int x = Q.front();
        Q.pop();

        if(x==k){
            res = visited[x];
            break;
        }

        for(auto tmp : {x-1, x+1, 2*x}){
            if(tmp<0 || tmp>100000 || visited[tmp])    continue;
            visited[tmp] = visited[x] + 1;
            
            Q.push(tmp);
        }
    }

    cout << res - 1;
}