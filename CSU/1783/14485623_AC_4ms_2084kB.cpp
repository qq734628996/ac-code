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
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
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
typedef pair<int, int> pii;
//const int MAXN  = 205, INF = ~0U>>1, MOD = ~0U>>1;
#define MAXN 1005

string buf, n1, n2, str;
typedef pair<string, string> pss;
map<pss, bool> mp;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (getline(cin, buf)) {
            //DEBUG(buf)
        int j;
        for (j = 0; buf[j] != ':'; j++) {
            if (!isalpha(buf[j])) buf[j] = ' ';
        }
        buf[j] = ' ';
            //DEBUG(j) DEBUG(buf)
        FOR(i,j,SZ(buf)-1)
            if (isalpha(buf[i])) buf[i] = tolower(buf[i]);
            else buf[i] = ' ';
        stringstream ss(buf);
        ss >> n1 >> n2;
            //DEBUG(n1) DEBUG(n2)
        if (n2 < n1) swap(n1, n2);
        bool flag = false;
        while (ss >> str) {
                //DEBUG(str)
            if (SZ(str) < 4) continue;
            bool ok = true;
            REP(i,SZ(str)) {
                if (i&1) {
                    if (str[i] != 'e') { ok = false; break; }
                } else {
                    if (str[i] != 'h') { ok = false; break; }
                }
            }
            if (ok) { flag = true; break; }
        }
        mp[pss(n1,n2)] = flag;
    }
    int cnt = 0;
    for (auto& i : mp) if (i.second) cnt++;
    printf("%d%%\n", (int)(cnt * 100.0 / SZ(mp) + 0.5));

    return 0;
}















































































