//DFS実装例
#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

void dfs(int v, Graph &G, vector<bool> &seen) {
    seen[v] = true;
    for (auto v2 : G[v]){
        if (seen[v2]){
            continue;
        }
        dfs(v2, G, seen);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    //ソートが必要な場合
    //for (int i = 0; i < N; i++){
        //sort(G[i].begin(), G[i].end());
    //}

    vector<bool> seen(N, false);
    dfs(0, G, seen);
    int count = 0;
    for (int i = 0; i < N; i++){
        if (seen[i] == false){
            count++;
        }
    }
    cout << count << endl;
}