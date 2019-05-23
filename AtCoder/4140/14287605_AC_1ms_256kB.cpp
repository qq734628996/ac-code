#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
const int MAXN  = 8e5, INF = ~0U>>1, MOD = ~0U>>1;



int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int n, ans = 0;
    string str;
    cin >> n >> str;
    for (int i = 1; i <= n-1; i++) {
        string str1 = str.substr(0,i);
        string str2 = str.substr(i);
        int cnt = 0;
        for (int j = 0; j < 26; j++) {
            if (str1.find('a'+j)!=string::npos && str2.find('a'+j)!=string::npos) {
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);

    return 0;
}
















































































