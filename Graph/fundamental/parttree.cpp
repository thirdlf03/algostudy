//部分木探索

#include <bits/stdc++.h>
using namespace std;
// 頂点 v を根とする部分木を探索
// 頂点 v の子頂点を格納した配列を chs とする
void rec(int v) {
    // 頂点 v を出力
    cout << v << endl;

    // 各子頂点を探索
    for (auto ch : chs) {
        // 子頂点 ch を根とした部分木を再帰的に探索
        rec(ch);
    }
}




//行きがけ順

// 頂点 v を根とする部分木を探索
void rec(int v, const vector<vector<int>> &chs) {
    // 頂点 v を出力
    cout << v << " ";

    // 頂点 v の各子頂点を探索
    for (auto ch : chs[v]) {
        // 子頂点 ch を根とした部分木を再帰的に探索
        rec(ch, chs);
    }
}




//帰りがけ順
void rec(int v, const vector<vector<int>> &chs) {

    // 頂点 v の各子頂点を探索
    for (auto ch : chs[v]) {
        // 子頂点 ch を根とした部分木を再帰的に探索
        rec(ch, chs);
    }
    // 頂点 v を出力
    cout << v << " ";
}




//頂点の高さ

// 頂点 v を根とする部分木を探索
// p := 頂点 v の親
// depth[v] := 頂点 v の深さ
// chs[v] := 頂点 v の子頂点のリスト
void rec(int v, int p, vector<int> &depth, 
         const vector<vector<int>> &chs) {
    // 頂点 v の深さを求める
    if (v == 0) {
        // 根の場合
        depth[v] = 0;
    }
    else {
        // 根以外の場合は親頂点の深さ + 1
        depth[v] = depth[p] + 1;
    }
    
    // 頂点 v の各子頂点を探索
    for (auto ch : chs[v]) {
        // 子頂点 ch を根とした部分木を再帰的に探索
        // 子頂点 ch の親は v である
        rec(ch, v, depth, chs);
    }
}

//子孫の個数
// 頂点 v を根とする部分木を探索
// p := 頂点 v の親
// siz[v] := 頂点 v を根とする部分木のサイズ
// chs[v] := 頂点 v の子頂点のリスト
void rec(int v, int p, vector<int> &siz, 
         const vector<vector<int>> &chs) {
    // 頂点 v の各子頂点を探索
    for (auto ch : chs[v]) {
        // 子頂点 ch を根とした部分木を再帰的に探索
        // 子頂点 ch の親は v である
        rec(ch, v, siz, chs);
    }

    // 帰りがけ時に答えを合算する
    siz[v] = 1;
    for (auto ch : chs[v]) {
        siz[v] += siz[ch];
    }
}