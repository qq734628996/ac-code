

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
const int MAXN  = 1e4, INF = ~0U>>1, MOD = ~0U>>1;





typedef pair<string, string> ps; //author and title
map<string, int> ID; //title and id
vector<ps> book;

string readAuthor (string str = "") {
    cin >> str; getchar();
    getline(cin, str);
    return str;
}

int main()
{
    #ifdef LOCAL
        freopen("i", "r", stdin);
        freopen("o", "w", stdout);
    #endif //LOCAL

    string title, op;
    set<int> shelve, borrow, _return;

    while (getchar() == '\"') {
        getline(cin, title, '\"');
        book.push_back(ps(readAuthor(), title));
    }
    sort(ALL(book));
    REP(i,SZ(book)) shelve.insert(ID[book[i].second] = i);

    cin >> op; getchar();
    while (cin >> op, op[0] != 'E') {
        if (op[0] == 'S') {
            for (auto& i : _return) {
                cout << "Put \"" << book[i].second;
                auto it = lower_bound(ALL(shelve), i);
                if (it == shelve.begin()) cout << "\" first\n";
                else {
                    cout << "\" after \"" << book[*--it].second << "\"\n";
                } //教训，迭代器没有重载加减号只有++--，且指针方面*(p++)与*p++等价！
                shelve.insert(i);
            }
            _return.clear(); puts("END");
        } else {
            while (getchar() != '\"');
            getline(cin, title, '\"');
            int id = ID[title];
            if (op[0] == 'B') { shelve.erase(id); borrow.insert(id); }
            else { borrow.erase(id); _return.insert(id); }
        }
    }































    return 0;
}





