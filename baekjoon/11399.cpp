//11399 - ATM - 정렬
#include <bits/stdc++.h>
using namespace std;

int n,m, res;
vector<int> A;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    
    for(int i=0; i<n;i++){
        cin >> m;
        A.push_back(m);
    }

    sort(A.begin(),A.end());

    for(int i=0; i<n;i++){
        int Sum=0;
        for(int j=0; j<=i;j++){
            Sum += A[j];
        }
        res += Sum;
    }

    cout << res;
    
}