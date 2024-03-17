// 13913 - 숨바꼭질4 - 12851 의 심화버전 (참고하기) - BFS
#include <bits/stdc++.h>
using namespace std;

const int max_n = 200004;       // 200000 까지 가는 것도 고려해야 함
int visited[max_n], Prev[max_n], n, k, ret, here, cnt, Next;   
vector<int> v; 
queue<int> q;  

int main() { 
    cin >> n >> k; 
    visited[n] = 1; 
    q.push(n);  

    while(q.size()){
        here = q.front();  
        q.pop();

        if(here == k){
            ret = visited[k]; 
            break;
        }

		for(int Next : {here + 1, here - 1, here * 2}){
            if(Next >= max_n || Next < 0 || visited[Next]) continue; //오버플로우,visited 체크
            visited[Next] = visited[here] + 1; 
            Prev[Next] = here;                  // 경로 추척!!
            q.push(Next); 
		} 

        /* 위에 for문과 같은 코드
        pair<int, int> d[] = { {1, 1}, {1, -1}, {2, 0} };
        for(int i=0; i<3; i++){
            int nx = here * d[i].first + d[i].second;
        }
        */
    }   
    for(int i = k; i != n; i = Prev[i]){
        v.push_back(i);
    }

    v.push_back(n);
    cout << ret - 1<< '\n'; 

    reverse(v.begin(), v.end());
	for(int i : v) cout << i << ' '; 
    return 0;
}