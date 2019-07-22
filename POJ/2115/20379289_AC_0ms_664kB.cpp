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
//#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n) printf("%d%c", A[i],i==n-1?'\n':' '); }
#define SHOW2(A,m,n) { REP(j,m) SHOW1(A[j],n) }
#define pb push_back
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int INF = 0x3f3f3f3f, MOD = 1000000007;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 5e6+9, MAXM = 3e3+9;

LL ex_gcd(LL a, LL b, LL& d, LL& x, LL& y)
{
    if (!b) d=a, x=1, y=0;
    else ex_gcd(b,a%b,d,y,x), y-=x*(a/b);
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    LL A,B,C,k;
    while (cin>>A>>B>>C>>k && k) {
        //ax=b mod p
        //ax+py=b
        LL a=C, b=B-A, p=1LL<<k, d,x,y;
        ex_gcd(a,p,d,x,y);
        if (b%d) puts("FOREVER");
        else {
            x*=b/d;
            LL mo=p/d;
            x=(x%mo+mo)%mo;
            printf("%lld\n", x);
        }
    }

    return 0;
}

































