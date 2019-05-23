#include <bits/stdc++.h>
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
const int MAXN = 1e6+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

const int dice[24][6]={
{0,1,2,3,4,5},{0,3,1,4,2,5},{0,4,3,2,1,5},{0,2,4,1,3,5},
{1,0,3,2,5,4},{1,2,0,5,3,4},{1,5,2,3,0,4},{1,3,5,0,2,4},
{2,0,1,4,5,3},{2,4,0,5,1,3},{2,5,4,1,0,3},{2,1,5,0,4,3},
{3,0,4,1,5,2},{3,1,0,5,4,2},{3,5,1,4,0,2},{3,4,5,0,1,2},
{4,0,2,3,5,1},{4,3,0,5,2,1},{4,5,3,2,0,1},{4,2,5,0,3,1},
{5,1,3,2,4,0},{5,2,1,4,3,0},{5,4,2,3,1,0},{5,3,4,1,2,0}
};
int color_cnt;
map<string, int> color_map;
int ID(string& s)
{
    if (color_map.count(s)) return color_map[s];
    return color_map[s]=color_cnt++;
}
int n,a[4][6],b[4][6],ans;
void dfs(int now, int k)
{
    REP(j,6) b[now][j]=a[now][dice[k][j]];
    if (now==n-1) {
        int cnt=0;
        REP(j,6) {
            int t=INF;
            REP(i,n) {
                int tt=0;
                REP(ii,n) tt+=b[i][j]!=b[ii][j];
                t=min(t,tt);
            }
            cnt+=t;
        }
        ans=min(ans,cnt);
        return;
    }
    REP(j,24) dfs(now+1,j);
}
int solve()
{
    if (n==1) return 0;
    ans=INF;
    REP(j,6) b[0][j]=a[0][j];
    REP(j,24) dfs(1,j);
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1 && n) {
        color_cnt=0;
        color_map.clear();
        REP(i,n)REP(j,6) {
            string s; cin>>s;
            a[i][j]=ID(s);
        }
        printf("%d\n", solve());
    }

    return 0;
}












































