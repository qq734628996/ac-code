#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>

#include <iostream>
#include <algorithm>
#include <unordered_map>
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
#define MAXN (1e6)
typedef long long LL;
const int INF = ~0U>>1, MOD = ~0U>>1;


unordered_map<char, string> morse;
unordered_map<string, vector<string> > context;

bool isPrefix(const string& a, const string& b) //a是b的前缀
{ return a.size() < b.size() && b.compare(0,a.size(),a) == 0; }

void solve(const string& m) {
    if (context.count(m)) {
        const auto& v = context[m]; //取新变量节省代码
        cout<<v.front();
        if (v.size() > 1) cout<<"!";
        cout<<endl;
        return;
    }

    map<int, string> ans;
    for (const auto& p : context) {
        const string& cm = p.first;
        if (isPrefix(m,cm)) ans[cm.size() - m.size()] = p.second.front();
        else if (isPrefix(cm,m)) ans[m.size() - cm.size()] = p.second.front();
    }
    cout<<ans.begin()->second<<"?"<<endl;
}

int main()
{
    string C,M; //C用字符串解决了读入字符可能读到空格换行的问题
    while (cin>>C && C != "*") {
        cin>>M;
        morse[C[0]] = M;
    }

    while (cin>>C && C != "*") {
        M.clear();
        for(auto c : C) M += morse[c];
        context[M].push_back(C);
    }

    while (cin>>M && M != "*") solve(M);

    return 0;
}




























