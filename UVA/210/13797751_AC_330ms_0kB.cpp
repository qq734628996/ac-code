

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
const int MAXN  = 1e6, INF = ~0U>>1, MOD = ~0U>>1;















int main()
{
#ifdef LOCAL
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);
#endif //LOCAL


    int T;
    struct pro {
        int id, _q;
        queue<string> op;
    };

    cin >> T;
    REP(j, T) {
        if (j) puts("");

        int n, time[5], Q, lock(0), num[26]{0}, index;
        string str;
        deque<pro *> dq;
        queue<pro *> q;

        cin >> n;
        REP(i,5) cin >> time[i];
        cin >> Q; getchar(); //防止getline这一行的换行符读了!!

        REP(i,n) {
            pro *t = new pro;
            t->id = i+1;
            while (getline(cin, str), t->op.push(str), str != "end");
            dq.push_back(t);
        }
/*
        while (!dq.empty()) {
            pro* t = dq.front(); dq.pop_front();
            DEBUG(t->id)
            while (!t->op.empty()) { cout << t->op.front() << endl; t->op.pop(); }
        }
*/



        while (!dq.empty()) {
            pro* t = dq.front(); dq.pop_front();
            t->_q = Q;
            bool flag(false);
            while (t->_q > 0 && !flag) {
                stringstream ss(t->op.front());
                ss >> str;
                if (SZ(str) == 4 && lock) { q.push(t); flag = true; break; }
                t->op.pop();
                switch (SZ(str)) {
                    case 1: //=
                        index = str[0] - 'a';
                        ss >> str;
                        ss >> num[index];
                        t->_q -= time[0];
                        break;
                    case 5: //print
                        ss >> str;
                        printf("%d: %d\n", t->id, num[str[0]-'a']);
                        t->_q -= time[1];
                        break;
                    case 4: //lock
                        lock = 1;
                        t->_q -= time[2];
                        break;
                    case 6: //unlock
                        lock = 0;
                        if (!q.empty()) { dq.push_front(q.front()); q.pop(); }
                        t->_q -= time[3];
                        break;
                    case 3: //end
                        flag = true;
                        break;
                    default:
                        abort();
                        break;
                }
            }
            if (!flag && !t->op.empty()) dq.push_back(t);
        }








    }

















    return 0;
}
