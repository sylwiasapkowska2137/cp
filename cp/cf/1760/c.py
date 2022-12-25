for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = sorted(a)
    for x in a:
        if x == b[-1]:
            print(x-b[-2], end=" ")
        else:
            print(x-b[-1], end=" ")
    print()