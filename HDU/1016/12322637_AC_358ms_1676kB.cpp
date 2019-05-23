#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
int flag[21], a[20], kase, n;

int isprime(int x)
{
  for(int i = 2; i * i <= x; i++) {
    if(x % i == 0)
      return 0;
  }
  return 1;
}

void f(int n, int index)
{
    if (index == n) {
        if (isprime(a[0] + a[index-1])) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                printf(cnt++ ? " %d" : "%d", a[i]);
            }
            printf("\n");
        }
    } else {
        for (int i = 2; i <= n; i++) {
            if (!flag[i] && isprime(a[index-1]+i)) {
                flag[i] = 1;
                a[index] = i;
                f(n, index+1);
                flag[i] = 0;
            }
        }
    }
}

int main()
{
    while (~scanf("%d", &n)) {
        printf("Case %d:\n", ++kase);
        memset(flag, 0, 21*4);
        memset(a, 0, 20*4);
        flag[1] = a[0] = 1;
        f(n, 1);
        printf("\n");
    }
}