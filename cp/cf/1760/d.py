for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in map(int, input().split())]
    r = 0
    ile = 0
    for l in range(n):
        while r+1<n and a[r+1] == a[l]:
            r += 1
        if l == 0 or a[l-1] > a[l]:
            if r == n-1 or a[r+1] > a[r]:
                ile += 1
    if ile == 1:
        print("YES")
    else:
        print("NO")