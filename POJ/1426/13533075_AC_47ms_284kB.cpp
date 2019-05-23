

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
#include <sstream>
#include <string>
#include <vector>
#include <list>
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
typedef long long LL;
const int MAXN  = 105, INF = ~0U>>1, MOD = ~0U>>1;










struct bigInt{
    char s[MAXN];
    int len;
    bigInt (int len=0) : len(0) {}
    void operator = (const bigInt& b) {
        memcpy(s, b.s, sizeof(s));
        len = b.len;
    }
    void print() {
        REP(i,len) putchar('0'+s[i]);
        puts("");
    }
    bool jdg(int k) {
        int num(0);
        REP(i,len) {
            num = num*10 + s[i];
            if (num < k) continue;
            while (num >= 0)
                num -= k;
            num += k;
        }
        return !num;
    }
}t, ans[205];

void genInt(int index, int len)
{
    if (len >= 24) return;
    if (index >= len) { genInt(1, len+1); return; }
    bool finish(true);
    t.len = len;
    for (int i = 1; i >= 0; i--) {
        t.s[index] = i;
        //putchar(t.s[index]+'0'); puts("");
        //t.print();

        FOR(j,1,200)
            if (!ans[j].len) {
                finish = false;
                if (t.jdg(j)) ans[j] = t;
            }

        //FOR(j,1,200) if (ans[j].len) { cout << j << ": "; ans[j].print(); }

        if (finish) return;
        else genInt(index+1, len);

    }
    return;
}

int main()
{
    /*
    bigInt b;
    REP(i,18) b.s[i] = i%3 ? 0 : 1;
    b.len = 18;
    b.print();
    cout << b.jdg(6) << endl;

    REP(i,18) b.s[i] = 1;
    b.print();
    cout << b.jdg(19) << endl;
    */

    t.s[0] = 1;
    genInt(1,2);
    int n;
    while (cin >> n, n) {
        ans[n].print();
    }


























    return 0;
}
