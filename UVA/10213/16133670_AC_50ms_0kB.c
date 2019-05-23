T = int(input())
for i in range(T):
    n = int(input())
    u = n*(n-1)//2
    v = n*(n-1)*(n-2)*(n-3)//24
    print(1+u+v)