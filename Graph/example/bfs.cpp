//bfs実装

#include <bits/stdc++.h>
using namespace std;

// 頂点 v を始点とした深さ優先探索
void rec(int v, vector<vector<int>> &G, vector<bool> &seen) {
    // 頂点 v を黒く塗る (= seen[v] を true に変える)
    seen[v] = true;
    // v を出力する
    cout << v << " ";
    // G[v] に含まれる頂点 v2 について、
    for(auto v2 : G[v]) {
        // v2 がすでに黒く塗られているならば、スキップする
        if(seen[v2]) {continue;}
        // v2 始点で深さ優先探索を行う (関数を再帰させる)
        rec(v2, G, seen);
    }
    return;
}

int main() {
    // 入力を受け取る
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N);   // グラフを表現する隣接リスト
    for(int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        // 頂点 a から頂点 b への辺を隣接リストに入れる
        G[a].push_back(b);
    }

    // 問題文より、各 G[v] は小さい順に並べる
    for(int v = 0; v < N; ++v) {
        sort(G[v].begin(), G[v].end());
    }

    vector<bool> seen(N, false);    // seen[v]：頂点 v が黒く塗られいているなら true, そうでないなら false
    // 頂点 0 を始点として深さ優先探索を開始する
    rec(0, G, seen);

	return 0;
}






//たどりつけない頂点

#include <bits/stdc++.h>
using namespace std;

// 頂点 v を始点とした深さ優先探索
void rec(int v, vector<vector<int>> &G, vector<bool> &seen) {
    // 頂点 v を黒く塗る (= seen[v] を true に変える)
    seen[v] = true;
    // G[v] に含まれる頂点 v2 について、
    for(auto v2 : G[v]) {
        // v2 がすでに黒く塗られているならば、スキップする
        if(seen[v2]) {continue;}
        // v2 始点で深さ優先探索を行う (関数を再帰させる)
        rec(v2, G, seen);
    }
    return;
}

int main() {
    // 入力を受け取る
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N);   // グラフを表現する隣接リスト
    for(int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        // 頂点 a から頂点 b への辺を隣接リストに入れる
        G[a].push_back(b);
    }

    vector<bool> seen(N, false);    // seen[v]：頂点 v が黒く塗られいているなら true, そうでないなら false
    // 頂点 0 を始点として深さ優先探索を開始する
    rec(0, G, seen);

    int ans = 0;    // 答えとなる変数
    // 各頂点 v について、頂点 v が黒く塗られていなければ ans を 1 増やす
    for(int v = 0; v < N; ++v) {
        if(seen[v] == false) {ans++;}
    }
    // 答えを出力する
    cout << ans << endl;

	return 0;
}






//連結性成分のチェック

#include <bits/stdc++.h>
using namespace std;

// 頂点 v を始点とした深さ優先探索
void rec(int v, vector<vector<int>> &G, vector<bool> &seen) {
    // 頂点 v を探索済みにする
    seen[v] = true;
    // G[v] に含まれる頂点 v2 について、
    for(auto v2 : G[v]) {
        // v2 がすでに探索済みならば、スキップする
        if(seen[v2]) {continue;}
        // v2 始点で深さ優先探索を行う (関数を再帰させる)
        rec(v2, G, seen);
    }
    return;
}

int main() {
    // 入力を受け取る
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N);   // グラフを表現する隣接リスト
    for(int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        // 頂点 a から頂点 b への辺を隣接リストに入れる
        G[a].push_back(b);
        // 無向グラフのため、頂点 b から頂点 a への辺を隣接リストに入れる
        G[b].push_back(a);
    }

    vector<bool> seen(N, false);    // seen[v]：頂点 v が探索済みなら true, そうでないなら false
    // 頂点 0 を始点として深さ優先探索を開始する
    rec(0, G, seen);

    string ans = "Yes";    // 答えとなる変数
    // 探索していない頂点が 1 つでもあるなら、答えは No
    for(int v = 0; v < N; ++v) {
        if(seen[v] == false) {ans = "No";}
    }
    // 答えを出力する
    cout << ans << endl;

	return 0;
}






//連結してないグラフの個数

#include <bits/stdc++.h>
using namespace std;

// 頂点 v を始点とした深さ優先探索
void dfs(int v, vector<vector<int>> &G, vector<bool> &seen) {
    // 頂点 v を探索済みにする
    seen[v] = true;
    // G[v] に含まれる頂点 v2 について、
    for(auto v2 : G[v]) {
        // v2 がすでに探索済みならば、スキップする
        if(seen[v2]) {continue;}
        // v2 始点で深さ優先探索を行う (関数を再帰させる)
        dfs(v2, G, seen);
    }
    return;
}

int main() {
    // 入力を受け取る
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N);   // グラフを表現する隣接リスト
    for(int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        // 頂点 a から頂点 b への辺を隣接リストに入れる
        G[a].push_back(b);
        // 無向グラフのため、頂点 b から頂点 a への辺を隣接リストに入れる
        G[b].push_back(a);
    }

    vector<bool> seen(N, false);    // seen[v]：頂点 v が探索済みなら true, そうでないなら false
    int ans = 0;    // 答えとなる変数
    // 全ての頂点について
    for(int v = 0; v < N; ++v) {
        // 頂点 v がすでに訪問済みであれば、スキップ
        if(seen[v]) {continue;}
        // そうでなければ、頂点 v を含む連結成分は未探索
        // 深さ優先探索で新たに訪問し、答えを 1 増やす
        dfs(v, G, seen);
        ans++;
    }
    // 答えを出力する
    cout << ans << endl;

	return 0;
}







//塊の個数

#include <bits/stdc++.h>
using namespace std;

// 周囲 4 マスを探索するときに使う、差分を表す配列
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// マス (x, y) がグリッド内のマスであるかを判定する
bool isvalid(int x, int y, int H, int W) {
    if(0 <= x && x < H && 0 <= y && y < W) {return true;}
    else {return false;}
}

// マス (x, y) の頂点番号
int getnum(int x, int y, int H, int W) {
    return (x * W + y);
}

// 頂点 v を始点とした深さ優先探索
void dfs(int v, vector<vector<int>> &G, vector<bool> &seen) {
    // 頂点 v を探索済みにする
    seen[v] = true;
    // G[v] に含まれる頂点 v2 について、
    for(auto v2 : G[v]) {
        // v2 がすでに探索済みならば、スキップする
        if(seen[v2]) {continue;}
        // v2 始点で深さ優先探索を行う (関数を再帰させる)
        dfs(v2, G, seen);
    }
    return;
}

int main() {
    // 入力を受け取る
    int H, W; cin >> H >> W;
    vector<vector<int>> grid(H, vector<int> (W, 0));    // grid[x][y]：マス (x, y) が白なら 0 、黒なら 1
    for(int x = 0; x < H; ++x) {
        string S; cin >> S;
        for(int y = 0; y < W; ++y) {
            if(S[y] == '#') {grid[x][y] = 1;}
            else if(S[y] == '.') {grid[x][y] = 0;}
        }
    }

    vector<vector<int>> G(H * W);   // グラフを表現する隣接リスト
    // グリッドの情報からグラフを作る
    for(int x = 0; x < H; ++x) {
        for(int y = 0; y < W; ++y) {
            // マス (x, y) が白マスなら、何もしない
            if(grid[x][y] == 0) {continue;}

            int v = getnum(x, y, H, W); // マス (x, y) に対応する頂点番号
            // マス (x, y) の上下左右のマスを探索
            for(int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                // マス (nx, ny) が盤内にあり、黒マスならば、対応する頂点同士を辺で結ぶ
                if(isvalid(nx, ny, H, W)) {
                    if(grid[nx][ny] == 0) {continue;}

                    int nv = getnum(nx, ny, H, W);  // マス (nx, ny) に対応する頂点番号
                    // 頂点 v から頂点 nv への辺を張る
                    G[v].push_back(nv);
                    // ダブルカウントされないよう、頂点 nv から頂点 v への辺は入れない
                }
            }
        }
    }

    vector<bool> seen(H * W, false);    // seen[v]：頂点 v が探索済みなら true, そうでないなら false
    int ans = 0;    // 答えとなる変数
    for(int x = 0; x < H; ++x) {
        for(int y = 0; y < W; ++y) {
            // マス (x, y) が白マスなら、何もしない
            if(grid[x][y] == 0) {continue;}

            int v = getnum(x, y, H, W);
            // 頂点 v がすでに訪問済みであれば、スキップ
            if(seen[v]) {continue;}
            // そうでなければ、頂点 v を含む連結成分は未探索
            // 深さ優先探索で新たに訪問し、答えを 1 増やす
            dfs(v, G, seen);
            ans++;
        }
    }
    // 答えを出力する
    cout << ans << endl;

	return 0;
}


