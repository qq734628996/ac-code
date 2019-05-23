#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <map>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define tr(e,x) for(typeof(x.begin()) e = x.begin(); e != x.end(); e++)
#define Debug(x) cout << #x << "=" << x << endl;
#define pb push_back
#define MAXN 1024
#define MO 2 //matrix order
typedef long long LL;
const int INF = ~0U>>1, MOD = 10000;

struct Mat
{
    int M[MO][MO];
    Mat() { memset(M, 0, sizeof(M)); }
    void operator=(const Mat &o) { memcpy(M, o.M, sizeof(M)); }
    int& operator()(int i, int j) { return M[i][j]; }
    Mat operator*(Mat &o)
    {
        Mat T;
        REP(i,MO)REP(j,MO)REP(k,MO) T(i,j) += M[i][k]*o(k,j)%MOD;
        return T;
    }
    void show() { REP(i,MO){ REP(j,MO) printf("%d ", M[i][j]); printf("\n"); } }
}orig, ans;

Mat mypow(Mat M, int n)
{
    if (!n) { REP(i,MO)REP(j,MO) M.M[i][j] = i == j; return M; }
    return n & 1 ? mypow(M, n-1) * M : mypow(M * M, n >> 1);
}

int main()
{
    //freopen("in", "r", stdin);
    orig.M[0][0] = orig.M[0][1] = orig.M[1][0] = 1;
    orig.M[1][1] = 0;
    int n;
    while (scanf("%d", &n), n != -1) {
        ans = orig;
        ans = mypow(ans, n);
        printf("%d\n", ans.M[0][1] % MOD);
    }
}
