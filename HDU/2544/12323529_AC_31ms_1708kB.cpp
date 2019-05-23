#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f

int main()
{
    int map1[101][101], N, M, a, b, c;
    while (scanf("%d%d", &N, &M), N) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) {
                    map1[i][j] = 0;
                } else {
                    map1[i][j] = inf;
                }
            }
        }
        for (int i = 1; i <= M; i++) {
            scanf("%d%d%d", &a, &b, &c);
            map1[a][b] = map1[b][a] = c;
        }
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (map1[i][j] > map1[i][k] + map1[k][j]) {
                        map1[i][j] = map1[i][k] + map1[k][j];
                    }
                }
            }
        }
        printf("%d\n", map1[1][N]);
    }
}