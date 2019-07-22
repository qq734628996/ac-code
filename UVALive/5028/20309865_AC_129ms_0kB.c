f=[1,1]
for i in range(2,10004):
    f.append(((2*i+1)*f[i-1]+(3*i-3)*f[i-2])//(i+2))
while True:
    try:
        n=int(input())
        print(int(str(f[n])[-100:]))
    except EOFError:
        break