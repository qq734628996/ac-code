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
#define SHOW1(A,n) { REP(i,n) cout<<A[i]<<(i==n-1?'\n':' '); }
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

LL fib[66];
char s[66],t[66];
string f(LL x)
{
    string ans;
    bool flag=false;
    for (int i=65; i>=0; i--) {
        if (x>=fib[i]) {
            x-=fib[i];
            ans+="1";
            flag=true;
        } else if (flag) ans+="0";
    }
    if (!SZ(ans)) return "0";
    return ans;
}
LL sum(char* S)
{
    int len=strlen(S);
    LL ans=0;
    REP(i,len) if (S[i]=='1') ans+=fib[len-1-i];
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    FOR(i,0,1) fib[i]=i+1;
    FOR(i,2,65) fib[i]=fib[i-1]+fib[i-2];
    while (scanf("%s%s", s,t)==2) {
        LL x=sum(s), y=sum(t);
        string a=f(x), b=f(y), c=f(x+y);
        int len=SZ(c);
        printf("%*s\n", len+2,a.c_str());
        printf("+ %*s\n", len,b.c_str());
        printf("  "); REP(i,len) printf("-"); puts("");
        printf("%*s\n", len+2,c.c_str());
        puts("");
    }

    return 0;
}

































