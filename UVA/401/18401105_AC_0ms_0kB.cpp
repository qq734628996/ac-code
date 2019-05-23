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
const int MAXN = 1e7+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;



int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    const char* mirr="A---3--HIL-JM-O---2TUVWXY51SE-Z--8-";
    char str[100];
    while (~scanf("%s",str)) {
        bool pal=true,mir=true;
        int len=strlen(str);
        REP(i,len) {
            pal&=(str[i]==str[len-1-i]);
            char ch=(isdigit(str[i]) ? mirr[str[i]-'0'+25] : mirr[str[i]-'A']);
            mir&=(ch==str[len-1-i]);
        }
        printf("%s -- ", str);
        if (pal&&mir) puts("is a mirrored palindrome.");
        else if (pal) puts("is a regular palindrome.");
        else if (mir) puts("is a mirrored string.");
        else puts("is not a palindrome.");
        puts("");
    }

    return 0;
}














































