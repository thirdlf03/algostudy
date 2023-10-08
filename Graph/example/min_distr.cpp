//DAGの最短路
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力を受け取る
    int N; cin >> N;
    vector<int> A(N-1), B(N-2);
    for(int i = 0; i < N-1; ++i) {cin >> A[i];}
    for(int i = 0; i < N-2; ++i) {cin >> B[i];}

    vector<int> dist(N);    // dist[v]：頂点 0 から頂点 v までの最短距離
    // 頂点番号の小さい順に dist を埋める
    for(int v = 0; v < N; ++v) {
        // v = 0, 1 のときのみ特殊なので場合分けを行う
        if(v == 0) {
            dist[v] = 0;
        }
        else if(v == 1) {
            dist[v] = dist[v-1] + A[v-1];
        }
        else {
            // v >= 2 のとき、頂点 v-1 から来る経路と頂点 v-2 から来る経路の 2 種類がある
            dist[v] = min(dist[v-1] + A[v-1], dist[v-2] + B[v-2]);
        }

    }

    // 頂点 0 から頂点 N-1 までの最短距離を出力する
    cout << dist[N-1] << endl;

	return 0;
}



//