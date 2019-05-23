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

int m,n,len,kase;
char s[12],a[12][12345];
const char* Hex="0123456789ABCDEF";
LL parity;
bool valid()
{
    REP(j,n*len) {
        int cnt=0;
        REP(i,m) cnt+=a[i][j]=='x';
        if (cnt>1) return false;
        LL t=0;
        if (cnt==1) {
            REP(i,m) if (a[i][j]!='x') t^=a[i][j]-'0';
            REP(i,m) if (a[i][j]=='x') a[i][j]=(t^parity)+'0';
        } else {
            REP(i,m) t^=a[i][j]-'0';
            if (t!=parity) return false;
        }
    }
    return true;
}
void decode()
{
    int cnt=0,now=0,x=0;
    REP(j,n) {
        REP(i,m) if (i!=now) {
            REP(k,len) {
                x=x*2+a[i][j*len+k]-'0';
                if ((cnt=(cnt+1)%4)==0) {
                    putchar(Hex[x]);
                    x=0;
                }
            }
        }
        now=(now+1)%m;
    }
    if (cnt) {
        do x<<=1; while (cnt=(cnt+1)%4);
        putchar(Hex[x]);
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d%d", &m,&len,&n)==3 && m) {
        scanf("%s", s);
        parity=s[0]=='O';
        REP(i,m) scanf("%s", a[i]);
        printf("Disk set %d is ", ++kase);
        if (!valid()) puts("invalid.");
        else {
            printf("valid, contents are: ");
            decode();
            puts("");
        }
    }

    return 0;
}












































