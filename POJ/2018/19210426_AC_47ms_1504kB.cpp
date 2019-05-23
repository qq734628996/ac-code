//#include <bits/stdc++.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>

#include <iostream>
#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define pb push_back
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
typedef pair<int, int> pii;
const int MAXN = 1e5+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

namespace fastIO {
#define BUF_SIZE 100000
    bool IOerror = 0;
    inline char nc() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if(p1 == pend) {
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if(pend == p1) {
                IOerror = 1;
                return -1;
            }
        }
        return *p1++;
    }
    template <class T>
    inline bool read(T &ret) {
        char c;
        if (c=nc(),c==EOF)return 0;
        while(c!='-'&&(c<'0'||c>'9'))c=nc();
        int sgn =(c=='-')?-1:1;
        ret=(c=='-')?0:(c - '0');
        while(c=nc(),c>='0'&&c<='9') ret=ret*10+(c-'0');
        ret *= sgn;
        return 1;
    }
    template <class T>
    inline void print(T x) {
        if(x>9) print(x/10);
        putchar(x%10+'0');
    }
#undef BUF_SIZE
};
using namespace fastIO;
int n,m;
LL a[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (read(n)) {
        read(m);
        FOR(i,1,n) read(a[i]), a[i]+=a[i-1];
        double ans=-INF;
        for (int l=1, r=m; r<=n; r++) {
            if ((a[r-m]-a[l-1])<=ans*(r-l-m+1)) l=r-m+1;
            ans=max(ans,(double)(a[r]-a[l-1])/(r-l+1));
        }
        printf("%d\n", int(ans*1000));
    }

    return 0;
}






































