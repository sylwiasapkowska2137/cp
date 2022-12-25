def inv(a, idx):
    a[idx] ^= 1
    s = 0
    ans = 0
    for x in a:
        if x == 0:
            ans+=s
        else:
            s += 1
    return ans

for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in map(int, input().split())]
    idx = -1
    for i in range(n):
        if a[i] == 0:
            idx = i
            break
    ans = 0
    if idx != -1:
        ans = max(ans, inv(a, idx))
    idx = -1
    for i in range(n-1, 0):
        if a[i] == 1:
            idx = i
            break
    if idx != -1:
        ans = max(ans, inv(a, idx))
    print(ans)