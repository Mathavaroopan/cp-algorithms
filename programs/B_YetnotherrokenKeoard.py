t = int(input())
for i in range(t):
    s = input()
    cap = []
    low = []
    for j in range(len(s)):
        i = s[j]
        if i == 'b' and len(low)!=0:
            low.pop(-1)
        elif i == 'B' and len(cap)!=0:
            cap.pop(-1)
        elif i != 'b' and i != 'B':
            a = i
            if a.capitalize() == i:
                cap.append(j)
            else:
                low.append(j)
    ans = ""
    cap += low
    cap.sort()
    for i in cap:
        ans += s[i]
    print(ans)
    
    