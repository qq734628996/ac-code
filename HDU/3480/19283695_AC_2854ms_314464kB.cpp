#include <bits/stdc++.h>

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
const int MAXN = 1e4+5, MAXM = 5e3+5, INF = 0x3f3f3f3f, MOD = 998244353;

struct point {
    LL x,y;
    point operator-(const point& p) const {
        return point{x-p.x, y-p.y};
    }
};
inline LL cross(const point& u, const point& v) {
    return u.x*v.y - u.y*v.x;
}
struct dequeue {
    point q[MAXN];
    int st,ed;
    void init(){ st=1, ed=0; }
    void push(const point& u) {
        while (st<ed && cross(q[ed]-q[ed-1], u-q[ed-1])<=0) ed--;
        q[++ed]=u;
    }
    point pop(const LL& k) {
        while (st<ed && -k*q[st].x+q[st].y >= -k*q[st+1].x+q[st+1].y) st++;
        return q[st];
    }
} Q;
int n,m;
LL a[MAXN], d[MAXN][MAXM];
void solve()
{
    Q.init();
    Q.push(point{a[1],a[1]*a[1]});
    FOR(k,1,m) {
        FOR(i,k,n) {
            LL kk=2*a[i];
            LL w=a[i]*a[i];
            point t=Q.pop(kk);
            d[i][k]=-kk*t.x+t.y+w;
        }
        Q.init();
        FOR(j,k,n-1) {
            Q.push(point{a[j+1],a[j+1]*a[j+1]+d[j][k]});
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        scanf("%d%d", &n,&m);
        FOR(i,1,n) scanf("%lld", &a[i]);
        sort(a+1,a+1+n);
        solve();
        printf("Case %d: %lld\n", kase,d[n][m]);
    }

    return 0;
}






































