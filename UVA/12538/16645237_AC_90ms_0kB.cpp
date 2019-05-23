#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define pb push_back
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
typedef pair<int, int> pii;
const int MAXN = 5e4+9, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 10007;

int tot,cntC;
struct node *null,*pit;
struct node {
    int key,rnd,sz;
    node *l,*r;
    node(){}
    node(int key, int rnd = rand()):key(key),rnd(rnd),sz(1){ l=r=null; }
    void* operator new(size_t){ return pit++; }
    void upd(){ sz = l->sz+r->sz+1; }
} pool[4000010], *root[MAXN];
node* newnode(node* o)
{
    if (o==null) return null;
    node* now = new node();
    *now = *o;
    return now;
}
node* Merge(node* a, node* b)
{
    if (a==null) return newnode(b);
    if (b==null) return newnode(a);
    node* tmp;
    if (a->rnd < b->rnd) {
        tmp = newnode(a);
        tmp->r = Merge(a->r,b);
    } else {
        tmp = newnode(b);
        tmp->l = Merge(a,b->l);
    }
    tmp->upd();
    return tmp;
}
typedef pair<node*, node*> droot;
droot split(node* o, int k)
{
    droot d(null,null);
    if (o==null) return d;
    if (k==0) return droot(null,newnode(o));
    if (k==o->sz) return droot(newnode(o),null);
    int sz = o->l->sz;
    node* tmp = newnode(o);
    if (k<=sz) {
        d = split(o->l,k);
        tmp->l = d.se;
        tmp->upd();
        d.se = tmp;
    } else {
        d = split(o->r,k-sz-1);
        tmp->r = d.fi;
        tmp->upd();
        d.fi = tmp;
    }
    return d;
}
node* stk[MAXN];
node* build(char* s)
{
    node* rt = new node(-INF,-INF);
    stk[0] = rt; int sz = 1;
    for (int i = 0; s[i]; i++) {
        node* now = new node(s[i]); int top = sz-1;
        while (stk[top]->rnd > now->rnd) stk[top--]->upd();
        if (top != sz-1) now->l = stk[top+1];
        stk[top]->r = now; sz = top+1;
        stk[sz++] = now;
    }
    while (sz) stk[--sz]->upd();
    return rt = rt->r;
}
void print(node* o)
{
    if (o==null) return;
    print(o->l);
    putchar(o->key);
    if (o->key == 'c') cntC++;
    print(o->r);
}
void init()
{
    srand(time(NULL));
    pit = pool; null = new node();
    null->sz = 0;
    root[tot] = null;
}
void Insert(int pos, char* s)
{
    droot l = split(root[tot],pos);
    root[++tot] = Merge(Merge(l.fi,build(s)),l.se);
}
void Remove(int pos, int k)
{
    droot l = split(root[tot],pos-1);
    droot r = split(l.se,k);
    root[++tot] = Merge(l.fi,r.se);
}
void print(int v, int pos, int k)
{
    droot l = split(root[v],pos-1);
    droot r = split(l.se,k);
    print(r.fi); puts("");
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    char s[MAXN];
    init();
    int n; scanf("%d", &n);
    REP(i,n) {
        int op; scanf("%d", &op);
        int v,p,k;
        if (op == 1) scanf("%d%s", &p,s), Insert(p-cntC,s);
        else if (op == 2) scanf("%d%d", &p,&k), Remove(p-cntC,k-cntC);
        else scanf("%d%d%d", &v,&p,&k), print(v-cntC,p-cntC,k-cntC);
    }

    return 0;
}









































































