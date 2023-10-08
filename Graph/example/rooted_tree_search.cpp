//根付き木の探索例
//ある葉から根までたどる
//N, X                  Nは葉の数, Xは指定された葉の場所
//A1, A2, A3 ... An-1   A1以外のAは親を表す

//4 2
//0 1 0
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 1; i < N; ++i) {
        cin >> A[i];
    }

    int res = 0;
    while (X != 0) {
        ++res;
        X = A[X];
    }

    cout << res << endl;
}

//