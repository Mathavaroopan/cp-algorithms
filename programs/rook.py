t = int(input())
for i in range(t):
    s = input()
    l = s[0]
    n = int(s[1])
    for i in range(1, 9):
        if i == n:
            continue
        ans = l
        if i != n: ans += str(i)
        print(ans)
    
    for i in ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']:
        if i == l:
            continue
        ans = i + str(n)
        print(ans)
        