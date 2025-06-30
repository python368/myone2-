#include <iostream>
#include <vector>

// 定义模数，用于所有求和操作，防止整数溢出
const int MOD = 1e9 + 7;

// 全局向量，用于存储线段树的节点值和懒惰标记
// 使用 long long 以防止中间计算结果溢出，即使最终结果会取模
std::vector<long long> tree;
std::vector<long long> lazy; // lazy[node] 存储需要添加到 node 对应区间所有元素的总值
std::vector<int> initial_arr; // 存储初始数组的值

/**
 * @brief 构建线段树。
 *
 * 这是一个递归函数，用于从初始数组构建线段树。
 * 每个节点存储其所代表区间的元素总和。
 *
 * @param node 当前线段树节点的索引（通常从1开始）。
 * @param start 当前节点覆盖区间的起始索引（0-based）。
 * @param end 当前节点覆盖区间的结束索引（0-based）。
 */
void build(int node, int start, int end) {
    if (start == end) {
        // 如果是叶子节点，直接存储初始数组对应位置的值，并取模
        tree[node] = initial_arr[start] % MOD;
    } else {
        // 计算中间点，将当前区间分为两半
        int mid = start + (end - start) / 2; // 避免 (start + end) 溢出
        // 递归构建左子树和右子树
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        // 当前节点的值是其左右子节点值的总和，并取模
        tree[node] = (tree[2 * node] + tree[2 * node + 1]) % MOD;
    }
}

/**
 * @brief 将懒惰标记从当前节点下推到其子节点。
 *
 * 当一个节点有待处理的懒惰更新时，此函数将其应用到子节点，
 * 并将懒惰标记传播给子节点，然后清除当前节点的懒惰标记。
 *
 * @param node 当前线段树节点的索引。
 * @param start 当前节点覆盖区间的起始索引。
 * @param end 当前节点覆盖区间的结束索引。
 */
void push_down(int node, int start, int end) {
    // 只有当存在待处理的懒惰更新时才执行下推
    if (lazy[node]!= 0) {
        // 如果不是叶子节点（即有子节点），则将懒惰标记下推
        if (start!= end) {
            int mid = start + (end - start) / 2;

            // 将懒惰标记应用到左子节点的 tree 值
            // tree[2*node] += lazy[node] * (左子区间长度)
            tree[2 * node] = (tree[2 * node] + lazy[node] * (mid - start + 1)) % MOD;
            // 将懒惰标记传播给左子节点的 lazy 标记
            lazy[2 * node] = (lazy[2 * node] + lazy[node]) % MOD;

            // 将懒惰标记应用到右子节点的 tree 值
            // tree[2*node+1] += lazy[node] * (右子区间长度)
            tree[2 * node + 1] = (tree[2 * node + 1] + lazy[node] * (end - mid)) % MOD;
            // 将懒惰标记传播给右子节点的 lazy 标记
            lazy[2 * node + 1] = (lazy[2 * node + 1] + lazy[node]) % MOD;
        }
        // 清除当前节点的懒惰标记，表示已处理完毕
        lazy[node] = 0;
    }
}

/**
 * @brief 对指定区间 [l, r] 执行更新操作（加法）。
 *
 * 将值 val 添加到数组中从 l 到 r 的所有元素。
 *
 * @param node 当前线段树节点的索引。
 * @param start 当前节点覆盖区间的起始索引。
 * @param end 当前节点覆盖区间的结束索引。
 * @param l 目标更新区间的起始索引。
 * @param r 目标更新区间的结束索引。
 * @param val 要添加的值（已规范化到）。
 */
void update(int node, int start, int end, int l, int r, int val) {
    // 在处理当前节点之前，先将任何待处理的懒惰更新下推
    push_down(node, start, end);

    // 情况1：当前节点覆盖的区间完全在目标更新区间之外
    if (start > end || 
        start > r || 
        end < l) {
        return;
    }

    // 情况2：当前节点覆盖的区间完全包含在目标更新区间之内
    if (l <= start && end <= r) {
        // 直接更新当前节点的 tree 值
        // tree[node] += val * (当前区间长度)
        tree[node] = (tree[node] + (long long)val * (end - start + 1)) % MOD;

        // 如果不是叶子节点，则标记其子节点进行懒惰传播
        if (start!= end) {
            lazy[2 * node] = (lazy[2 * node] + val) % MOD;
            lazy[2 * node + 1] = (lazy[2 * node + 1] + val) % MOD;
        }
        return;
    }

    // 情况3：当前节点覆盖的区间与目标更新区间部分重叠，递归处理子节点
    int mid = start + (end - start) / 2;
    update(2 * node, start, mid, l, r, val);
    update(2 * node + 1, mid + 1, end, l, r, val);

    // 递归调用返回后，根据子节点的新值更新当前节点的 tree 值
    tree[node] = (tree[2 * node] + tree[2 * node + 1]) % MOD;
}

/**
 * @brief 查询指定区间 [l, r] 的总和。
 *
 * @param node 当前线段树节点的索引。
 * @param start 当前节点覆盖区间的起始索引。
 * @param end 当前节点覆盖区间的结束索引。
 * @param l 目标查询区间的起始索引。
 * @param r 目标查询区间的结束索引。
 * @return 区间 [l, r] 内元素的总和，已取模。
 */
long long query(int node, int start, int end, int l, int r) {
    // 在处理当前节点之前，先将任何待处理的懒惰更新下推
    push_down(node, start, end);

    // 情况1：当前节点覆盖的区间完全在目标查询区间之外
    if (start > end || 
        start > r || 
        end < l) {
        return 0; // 不对查询结果做贡献
    }

    // 情况2：当前节点覆盖的区间完全包含在目标查询区间之内
    if (l <= start && end <= r) {
        return tree[node]; // 直接返回当前节点存储的总和
    }

    // 情况3：当前节点覆盖的区间与目标查询区间部分重叠，递归查询子节点
    int mid = start + (end - start) / 2;
    long long p1 = query(2 * node, start, mid, l, r);
    long long p2 = query(2 * node + 1, mid + 1, end, l, r);

    // 组合子查询的结果并取模
    return (p1 + p2) % MOD;
}

int main() {
    // 优化 C++ 标准输入/输出流，提高执行速度
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M; // N: 数组大小，M: 操作次数
    std::cin >> N >> M;

    initial_arr.resize(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> initial_arr[i];
    }

    // 根据 N 的大小调整线段树和懒惰标记数组的大小
    // 通常分配 4 * N 的空间足以容纳所有节点
    tree.resize(4 * N);
    lazy.resize(4 * N, 0); // 懒惰标记数组初始化为0

    // 构建线段树
    build(1, 0, N - 1); // 从根节点（索引1）开始构建，覆盖整个数组 [0, N-1]

    // 处理 M 次操作
    for (int i = 0; i < M; ++i) {
        int opt; // 操作类型
        std::cin >> opt;
        if (opt == 1) { // 更新操作
            int l, r, x; // 区间 [l, r]，要添加的值 x
            std::cin >> l >> r >> x;
            // 将 x 规范化到 范围，以正确处理负数和模运算
            int val_for_update = (x % MOD + MOD) % MOD;
            // 调用更新函数，注意将 1-based 索引转换为 0-based 索引
            update(1, 0, N - 1, l - 1, r - 1, val_for_update);
        } else { // opt == 2，查询操作
            int l, r; // 查询区间 [l, r]
            std::cin >> l >> r;
            // 调用查询函数，注意将 1-based 索引转换为 0-based 索引
            long long result = query(1, 0, N - 1, l - 1, r - 1);
            std::cout << result << "\n"; // 输出查询结果
        }
    }

    return 0;
}