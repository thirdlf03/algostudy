#include <bits/stdc++.h>
using namespace std;

//グラフを使うときのデータ構造
using Graph = vector<vector<int>>;

// N = 頂点
// M = 辺の数
// A B は頂点Aと頂点Bが結ばれていることを表す
// Input 
// N M
// A B
// A2 B2
// A3 B3
// Am-1 Bm-1

int main(){
    int N, M;
    cin >> N >> M;
    //グラフ作成
    Graph G(N);
    for (int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        //頂点A からBへの辺を張る
        G[A].push_back(B);
        
        //無向グラフの時は
        //G[B].push_back(A); を追加
    }
}
