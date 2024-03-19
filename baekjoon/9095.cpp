// 9095 - DP - 1,2,3 더하기
#include <bits/stdc++.h>
using namespace std;

int t,n,res;

void solve(int Sum){
    if(Sum==n){
        res++;
        return;
    }
    if(Sum>n) return;

    for(int i=1;i<=3;i++){
        solve(Sum+i);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;

    for(int i=0; i<t;i++){
        cin >> n;
        solve(0);
        cout << res << '\n';
        res = 0;
    }
}