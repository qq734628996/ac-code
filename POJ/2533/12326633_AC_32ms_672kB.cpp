#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>

int main()
{
    int n, a[1024], b[1024] = {0}, max, j;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    b[max = 1] = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > b[max]) {
            b[++max] = a[i];
        } else if (a[i] < b[1]) {
            b[1] = a[i];
        } else {
            for (j = 1; j <= max && a[i] > b[j]; j++) ;
            b[j] = a[i];
        }
    }
    printf("%d\n", max);
}