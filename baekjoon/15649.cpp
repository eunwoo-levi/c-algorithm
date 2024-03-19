// 15649 - backtracking 문제.
#include <bits/stdc++.h>
using namespace std;

int n,m;
int A[10], visited[10];

void func(int k){       // 현재 k개 까지 수를 택함   - DFS
    if(k==m){
        for(int i=0; i<m;i++){
            cout << A[i] << ' ';
        }
        cout << "\n";
        return;
    }
    
    for(int i=1; i<=n;i++){
        if(!visited[i]){
            visited[i] = 1;
            A[k] = i;   
            func(k+1);      // // 다음 수를 정하러 한 단계 더 들어감
            visited[i] = 0; // ** k번째 수를 i로 정한 모든 경우에 대해
        }                   // 다 확인했으니 i를 이제 사용되지않았다고 명시함.
    }
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    func(0);
}