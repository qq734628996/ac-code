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
const int MAXN = 1e3+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

const int a[][3] = {
    {1,2,3},
    {2,1,4},
    {3,1,2},
    {4,1,5},
    {5,1,3},
    {6,2,4}
};
const int rot[]={1,4,2,5,3,6};
bool jdg(char* s1, char* s2)
{
    int t[6];
    REP(i,6) {
        REP(j,3) t[j]=a[i][j], t[5-j]=7-t[j];
        REP(j,4) {
            if (j) {
                int tt[6];
                REP(k,6) tt[k]=t[rot[k]-1];
                memcpy(t,tt,sizeof(t));
            }
            //SHOW1(t,6)
            bool flag=true;
            REP(k,6) flag&=s1[k]==s2[t[k]-1];
            if (flag) return true;
        }
    }
    return false;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    char s[22];
    while (~scanf("%s", s)) {
        puts(jdg(s,s+6) ? "TRUE":"FALSE");
    }

    return 0;
}












































