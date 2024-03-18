// 16637 - 괄호 추가하기
#include <bits/stdc++.h>
using namespace std;  

int n,res=-1e9;
string S;
vector<int> num, op;

int cal(int a, char b, int c){
    if(b=='+')  return a + c;
    if(b=='-')  return a - c;
    if(b=='*')  return a * c;
}

void func(int idx, int tot){
    if(idx == num.size()-1){
        res = max(res, tot);
        return;
    }

    func(idx+1, cal(tot, op[idx], num[idx+1]));

    if(idx+2<=num.size()-1){
        int temp = cal(num[idx+1],op[idx+1], num[idx+2]);
        func(idx+2, cal(tot,op[idx], temp));
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
    
    cin >> n >> S;

    for(int i=0; i<n;i++){
        if(i%2==0)  num.push_back(S[i] -'0');
        else    op.push_back(S[i]);
    }

    func(0, num[0]);

    cout << res;

    return 0;
} 