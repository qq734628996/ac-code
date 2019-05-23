//#include "Head.h"
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
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
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
const int MAXN = 1e2+5, INF = 0x3f3f3f3f, MOD = 998244353;

int m, x, y;
struct node {
    int x, y;
    double t;
    bool operator<(const node& o) const {
        return t > o.t;
    }
} st, ed;
vector<node> E[MAXN];
inline double dist(node& a, node& b) { return hypot(a.x-b.x,a.y-b.y); }
const double walk = 10000/60, sub = 40000/60;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d%d%d%d", &st.x, &st.y, &ed.x, &ed.y);
    while (~scanf("%d%d", &x, &y)) {
        if (x == -1 && y == -1) m++;
        else E[m].pb((node){x,y,INF});
    }
    E[m++].pb((node){ed.x,ed.y,INF});
    priority_queue<node> pq;
    pq.push((node){st.x,st.y,0});
    while (!pq.empty()) {
        node tmp = pq.top(); pq.pop();
        x = tmp.x, y = tmp.y;
        if (x == ed.x && y == ed.y) {
            printf("%d\n", (int)(tmp.t+0.5+1e-9));
            break;
        }
        REP(i,m)REP(j,SZ(E[i])) {
            double dis = dist(tmp, E[i][j]);
            if (fabs(dis) < 1e-9) {
                if (j > 0 && E[i][j-1].t > tmp.t + dist(tmp,E[i][j-1])/sub) {
                    E[i][j-1].t = tmp.t + dist(tmp,E[i][j-1])/sub;
                    pq.push(E[i][j-1]);
                }
                if (j < SZ(E[i])-1 && E[i][j+1].t > tmp.t + dist(tmp,E[i][j+1])/sub) {
                    E[i][j+1].t = tmp.t + dist(tmp,E[i][j+1])/sub;
                    pq.push(E[i][j+1]);
                }
            }
            if (E[i][j].t > tmp.t + dis/walk) {
                E[i][j].t = tmp.t + dis/walk;
                pq.push(E[i][j]);
            }
        }
    }

    return 0;
}


















































































