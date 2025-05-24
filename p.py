import sys
MOD = 10**9 + 7

class Fenwick:
    __slots__ = ['n', 'tree']  # 优化内存
    def __init__(self, size):
        self.n = size
        self.tree = [0]*(self.n+2)
    
    def update(self, idx, v):
        while idx <= self.n:
            self.tree[idx] += v
            idx += idx & -idx
    
    def query(self, idx):
        res = 0
        while idx > 0:
            res += self.tree[idx]
            idx -= idx & -idx
        return res

def main():
    input = sys.stdin.read().split()
    ptr = 0
    n = int(input[ptr])
    ptr +=1
    m = int(input[ptr])
    ptr +=1
    
    ft_A = Fenwick(n)
    ft_B = Fenwick(n)
    
    for _ in range(m):
        op = input[ptr]
        ptr +=1
        if op == '1':
            l = int(input[ptr])
            ptr +=1
            r = int(input[ptr])
            ptr +=1
            # 系数更新
            ft_A.update(l, 1)
            if r+1 <= n:
                ft_A.update(r+1, -1)
            # 常数项更新
            delta = (-l +1)
            ft_B.update(l, delta)
            if r+1 <= n:
                ft_B.update(r+1, -delta)
        else:
            x = int(input[ptr])
            ptr +=1
            a = ft_A.query(x)
            b = ft_B.query(x)
            print((a*x + b) % MOD)

if __name__ == '__main__':
    main()