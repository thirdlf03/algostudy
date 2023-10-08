//BFS実装例
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

using Graph = vector<vector<int>>;

int main(){
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;

        G[A].push_back(B);
        G[B].push_back(A);
    }

    vector<int> dist(N, -1);

    queue<int> que;

    dist[0] = 0;
    que.push(0);

    while (!que.empty()){
        int v = que.front();

        que.pop();

        for (auto next_v : G[v]){
            if (dist[next_v] != -1){
                continue;
            }

            dist[next_v] = dist[v] + 1;
            que.push(next_v);
        }
    }
}