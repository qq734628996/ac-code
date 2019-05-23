

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
const int MAXN  = 1e6 + 4e5, INF = ~0U>>1, MOD = ~0U>>1;






int n, k;
int a[MAXN];

int bfs()
{
    queue<int> q;
    q.push(n); a[n] = 1;

    while (true) {
        int t = q.front(); q.pop();
        if (t == k) { return a[t]-1; }
        else {
            if (0<t && !a[t-1]) { q.push(t-1); a[t-1] = a[t]+1; }
            if (t < k) {
                if (!a[t<<1]) { q.push(t<<1); a[t<<1] = a[t]+1; }
                if (!a[t+1]) { q.push(t+1); a[t+1] = a[t]+1; }
            }
        }
    }
}

int main()
{
    cin >> n >> k;
    cout << bfs() << endl;




























    return 0;
}
