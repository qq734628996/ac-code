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

int x,y,st,len,integer,t;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &x,&y)==2) {
        integer=x/y;
        t=x;
        map<int,int> mp;
        for (int i=1; ; i++) {
            t=(t%y)*10;
            if (mp.count(t)) {
                st=mp[t];
                len=i-mp[t];
                break;
            } else mp[t]=i;
        }
        printf("%d/%d = %d.", x,y,integer);
        t=x;
        for (int i=1; i<=50; i++) {
            t=(t%y)*10;
            if (i==st) printf("(");
            printf("%d", t/y);
            if (i==st+len-1) break;
        }
        if (st+len-1>50) printf("...");
        if (st<50) printf(")");
        printf("\n   %d = number of digits in repeating cycle\n\n", len);
    }

    return 0;
}














































