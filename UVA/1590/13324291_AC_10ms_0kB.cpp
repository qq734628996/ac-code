

//#include "Head.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>

#include <iostream>
#include <algorithm>
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



int n;

struct IP
{
    int byte[4];
}ip[1005],ans,mask;
istream& operator>> (istream& in, IP& ip)
{ REP(i,4) { in>>ip.byte[i]; cin.get(); } return in; }
ostream& operator<< (ostream& out, const IP& ip)
{ REP(i,3) out<<ip.byte[i]<<'.'; out<<ip.byte[3]<<endl; return out; }

bool cmp(const IP& ip1, const IP& ip2)
{
    if(ip1.byte[0]==ip2.byte[0])
        if(ip1.byte[1]==ip2.byte[1])
            if(ip1.byte[2]==ip2.byte[2])
                return ip1.byte[3]<ip2.byte[3];
            else return ip1.byte[2]<ip2.byte[2];
        else return ip1.byte[1]<ip2.byte[1];
    else return ip1.byte[0]<ip2.byte[0];
}




bool read()
{
    if(scanf("%d",&n)==-1)return false;
    REP(i,n)cin>>ip[i]; return true;
}
void solve()
{
    sort(ip,ip+n,cmp);
    //REP(i,n)cout<<ip[i];
    REP(i,4){ans.byte[i]=0;mask.byte[i]=0;}
    for(int i=0;i<4;i++)
        for(int j=7;j>=0;j--)
            if ( ( ip[0].byte[i] & (1<<j) ) == ( ip[n-1].byte[i] & (1<<j) ) )
                { ans.byte[i] |= ( ip[0].byte[i] & (1<<j) ); mask.byte[i] |= (1<<j); }
            else goto OUT;
OUT:
    cout<<ans<<mask;
}


int main()
{
#ifdef LOCAL
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);
#endif //LOCAL

#ifdef _DEBUG

#endif //_DEBUG

    while (read()) {
        //cout<<"----------------------------\n";
        solve();
    }



















    return 0;
}
