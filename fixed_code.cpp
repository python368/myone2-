#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

class FenwickTree {
private:
    vector<long long> tree;
    int size;

public:
    FenwickTree(int n) : size(n) {
        tree.resize(n + 20, 0);
    }

    void update(int index, long long value) {
        while (index <= size) {
            tree[index] += value;
            index += index & -index;
        }
    }

    long long query(int index) {
        long long sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    FenwickTree T0(n+20), T1(n+20);

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            // 更新常数项
            T0.update(l, 1 - l);
            T0.update(r+1, l - 1);  // 修复：使用(l-1)而不是-(1-l)
            // 更新一次项系数
            T1.update(l, 1);
            T1.update(r+1, -1);
        } else {
            int x;
            cin >> x;
            // 计算伤害值
            long long a = T1.query(x);
            long long b = T0.query(x);
            long long damage = a * x + b;
            damage %= MOD;
            if (damage < 0) damage += MOD;
            cout << damage << '\n';
        }
    }

    return 0;
}
