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



int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    int n;
    string s[123];
    while (cin>>n) {
        REP(i,n) cin>>s[i];
        sort(s,s+n);
        int ma=0;
        REP(i,n) ma=max(ma,SZ(s[i]));
        int c=62/(ma+2);
        int r=(n+c-1)/c;
        cout<<setfill('-')<<setw(60)<<""<<endl;
        cout<<setiosflags(ios::left)<<setfill(' ');
        REP(i,r) {
            REP(j,c) {
                int x=j*r+i, nxt=(j+1)*r+i;
                if (x>=n) break;
                if (j) cout<<"  ";
                cout<<setw(ma)<<s[x];
            }
            cout<<endl;
        }
    }

    return 0;
}












































