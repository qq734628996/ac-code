c=[6,2,5,5,4,5,6,3,7,6]
d=[0]*3000
d[0]=1
for i in range(2001):
    for j in range(10):
        if i==0 and j==0:
            continue
        d[i+c[j]]+=d[i]
d[6]+=1
for i in range(2,2001):
    d[i]+=d[i-1]
while True:
    try:
        n=int(input().strip())
        print(d[n])
    except EOFError:
        break