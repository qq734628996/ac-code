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
const int MAXN = 1e6+9, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 10007;

string S[150];
int T,n;
int solve()
{
    ROF(len,1,SZ(S[0])) {
        FOR(i,0,SZ(S[0])-len) {
            string tmp = S[0].substr(i,len);
            string rtmp(tmp); reverse(ALL(rtmp));
            bool flag = true;
            FOR(i,1,n-1) {
                if (S[i].find(tmp)==string::npos && S[i].find(rtmp)==string::npos) {
                    flag = false;
                    break;
                }
            }
            if (flag) return len;
        }
    }
    return 0;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        REP(i,n) cin>>S[i];
        int mi = 0;
        REP(i,n) if (SZ(S[i]) < SZ(S[mi])) mi = i;
        swap(S[0],S[mi]);
        printf("%d\n", solve());
    }

    return 0;
}










































































