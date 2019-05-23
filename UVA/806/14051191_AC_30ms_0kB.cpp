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
const int MAXN  = 70, INF = ~0U>>1, MOD = ~0U>>1;

char s[MAXN][MAXN];
struct tree {
    int c1, c2, c3, c4, val; //1black 0white -1not leaf
} tr[MAXN*MAXN*2];
int cnt, n, root, t, kase;
vector<int> V;

int inittree(int si, int sj, int len)
{
    int u = ++cnt, white = 0, black = 0;
    REP(i,len)REP(j,len)s[si+i][sj+j]=='0' ? white++ : black++;
        //printf("si=%d,sj=%d,len=%d,white=%d,black=%d\n",si,sj,len,white,black);
    if (!white) tr[u].val = 1;
    else if (!black) tr[u].val = 0;
    else {
        tr[u].val = -1;
        int half = len>>1;
        tr[u].c1 = inittree(si, sj, half);
        tr[u].c2 = inittree(si, sj+half, half);
        tr[u].c3 = inittree(si+half, sj, half);
        tr[u].c4 = inittree(si+half, sj+half, half);
    }
    return u;
}
void getAns(int rt, int num, int layer)
{
    if (tr[rt].val == 1) V.push_back(num);
    else if (tr[rt].val == -1) {
        getAns(tr[rt].c1, num+1*(pow(5,layer)+1e-5), layer+1); //pow有误差
        getAns(tr[rt].c2, num+2*(pow(5,layer)+1e-5), layer+1);
        getAns(tr[rt].c3, num+3*(pow(5,layer)+1e-5), layer+1);
        getAns(tr[rt].c4, num+4*(pow(5,layer)+1e-5), layer+1);
    }
}

void paint(int si, int sj, int len, int num)
{
    if (!num) REP(i,len)REP(j,len)s[si+i][sj+j] = '*';
    else {
        int half = len>>1;
        switch (num % 5) {
            case 1: paint(si, sj, half, num/5); break;
            case 2: paint(si, sj+half, half, num/5); break;
            case 3: paint(si+half, sj, half, num/5); break;
            case 4: paint(si+half, sj+half, half, num/5); break;
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n), n) {
        if (kase) puts("");
        printf("Image %d\n", ++kase);
        if (n > 0) {
            REP(i,n)scanf("%s", s[i]);
            cnt = 0;
            root = inittree(0, 0, n);
            V.clear();
            getAns(root, 0, 0);
            sort(ALL(V));
            if (SZ(V)) {
                REP(i,SZ(V)-1)printf("%d%c", V[i], (i+1)%12 ? ' ' : '\n');
                printf("%d\nTotal number of black nodes = %d\n", V[SZ(V)-1], SZ(V));
            } else printf("Total number of black nodes = 0\n");
        } else {
            V.clear();
            while (scanf("%d", &t), t != -1) V.push_back(t);
            REP(i,-n)REP(j,-n)s[i][j] = '.';
            REP(i,SZ(V)) paint(0, 0, -n, V[i]);
            REP(i,-n){REP(j,-n)putchar(s[i][j]);puts("");}
        }
    }

    return 0;
}

































