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
const int MAXN  = 1e3+5, INF = ~0U>>1, MOD = ~0U>>1;

char buf[130];
bool jdg(char* p)
{
    if (*p == '\0') return true;
    stack<char> S;
    for ( ; *p != '\0'; p++) {
        if (*p == '(' || *p == '[') S.push(*p);
        else if (*p == ')') {
            if (S.empty() || S.top() != '(') return false;
            else S.pop();
        } else if (*p == ']') {
            if (S.empty() || S.top() != '[') return false;
            else S.pop();
        }
    }
    return S.empty() ? true : false;
}


int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    gets(buf);
    while (gets(buf))puts(jdg(buf) ? "Yes" : "No");

    return 0;
}






















