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
const int MAXN = 1e6+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 2520;

struct point {
    LL x,y;
    point operator-(const point& p) const {
        return (point){x-p.x,y-p.y};
    }
};
inline LL cross(const point& u, const point& v)
{
    return u.x*v.y-v.x*u.y;
}
struct dequeue {
    point q[MAXN];
    int st,ed;
    void init() { st=1; ed=0; }
    void push(const point& u) {
        while (st<ed && cross(q[ed]-q[ed-1],u-q[ed-1])<=0) ed--;
        q[++ed]=u;
    }
    point pop(const LL& k) {
        while (st<ed && (-k)*q[st].x+q[st].y >= (-k)*q[st+1].x+q[st+1].y) st++;
        return q[st];
    }
} Q;
int n,M;
LL a[MAXN],d[MAXN];
void solve()
{
    Q.init();
    Q.push((point){0,0});
    FOR(i,1,n) {
        LL k=2*a[i];
        LL w=a[i]*a[i]+M;
        point t=Q.pop(k);
        d[i]=-k*t.x+t.y+w;
        Q.push((point){a[i],d[i]+a[i]*a[i]});
    }
    printf("%lld\n", d[n]);
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &n,&M)==2) {
        FOR(i,1,n) scanf("%lld", &a[i]), a[i]+=a[i-1];
        solve();
    }

	return 0;
}










































