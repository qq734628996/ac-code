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
const int MAXN  = 1e4+5, INF = ~0U>>1, MOD = ~0U>>1;


map<string, int> IDcache;
vector<string> Setcache;
int ID(string& str)
{
    if (IDcache.count(str)) return IDcache[str];
    Setcache.push_back(str);
    return IDcache[str] = SZ(Setcache) - 1;
}

vector<int> depend[MAXN], depended[MAXN], installed;
int status[MAXN];

void install(int x, int level)
{
    if (status[x]) return;
    REP(i,SZ(depend[x])) install(depend[x][i], 1);
    cout << "   Installing " << Setcache[x] << endl;
    status[x] = level;
    installed.push_back(x);
}
bool needed(int x)
{
    REP(i,SZ(depended[x]))if(status[depended[x][i]])return true;
    return false;
}
void rm(int x, bool level)
{
    if ((level || status[x] == 1) && !needed(x)) {
        status[x] = 0;
        installed.erase(remove(ALL(installed), x), installed.end());
        cout << "   Removing " << Setcache[x] << endl;
        REP(i,SZ(depend[x]))rm(depend[x][i], false);
    }
}


int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    ios::sync_with_stdio(false);
    string buf, str;
    int x, y;
    while (getline(cin, buf), buf[0] != 'E') {
        cout << buf << endl;
        if (buf[0] == 'L') { REP(i,SZ(installed))cout << "   " << Setcache[installed[i]] << endl; continue; }
        stringstream ss(buf);
        REP(i,2) ss >> str;
        x = ID(str);
        switch (buf[0]) {
        case 'D':
            while (ss >> str) {
                y = ID(str);
                depend[x].push_back(y);
                depended[y].push_back(x);
            }
            break;
        case 'I':
            if (status[x]) cout << "   " << Setcache[x] << " is already installed.\n";
            else install(ID(str), 2);
            break;
        case 'R':
            if (!status[x]) cout << "   " << Setcache[x] << " is not installed.\n";
            else if (needed(x)) cout << "   " << Setcache[x] << " is still needed.\n";
            else rm(x, true);
            break;
        }
    }
    cout << "END\n";

    return 0;
}






















