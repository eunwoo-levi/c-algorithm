#include <bits/stdc++.h>
using namespace std;

int n,m;
string a,b;
map<string, string> M;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for(int i=0; i<n;i++){
        cin >> a >> b;
        M[a] = b;
    }

    for(int i=0; i<m;i++){
        cin >> a;
        cout << M[a] << '\n';
    }

    return 0;
}