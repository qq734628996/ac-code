T=int(input())
for i in range(T):
    n=int(input())
    print(1+n*(n-1)//2+n*(n-1)*(n-2)*(n-3)//24)