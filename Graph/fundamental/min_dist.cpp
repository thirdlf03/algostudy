//重み付き単純有向グラフの実装例

// 辺情報を表す構造体
struct edge {
    int from;   // 辺の始点
    int leng;   // 辺の長さ
};

int N, M; cin >> N >> M;
vector<vector<edge>> G(N);
for(int i = 0; i < M; ++i) {
    int u, v, w; cin >> u >> v >> w;
    G[v].push_back({u, w});
}

//移動先と重みをpairでもつといい感じにできる