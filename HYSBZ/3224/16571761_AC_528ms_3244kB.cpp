#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define ll long long
#define lt tree[x].ls
#define rt tree[x].rs
using namespace std;
const int maxn=100010, inf=1e9+1;
int n, m, x, y, z, root, tott, tmp, opt;
struct treap{int rnd, sum, size, ls, rs;} tree[maxn];
inline void read(int &k)
{
    int f=1; k=0; char c=getchar();
    while(c<'0' || c>'9') c=='-'&&(f=-1), c=getchar();
    while(c<='9' && c>='0') k=k*10+c-'0', c=getchar();
    k*=f;   
}
inline void build(int &x, int delta) 
{
    tree[x=++tott].rnd=rand()<<15|rand(); 
    tree[x].sum=delta;
    tree[x].size=1;
}
inline void up(int x) {if(!x) return; tree[x].size=tree[lt].size+tree[rt].size+1;}
void merge(int &x, int l, int r)
{
    if(!l || !r) x=l+r;
    else if(tree[l].rnd<tree[r].rnd) x=l, merge(tree[x].rs, tree[x].rs, r), up(x);
    else x=r, merge(tree[x].ls, l, tree[x].ls), up(x);
}
void split(int x, int &l, int &r, int k)
{
    if(!k) l=0, r=x;
    else if(k==tree[x].size) l=x, r=0;
    else if(k<=tree[lt].size) r=x, split(lt, l, lt, k), up(x);
    else l=x, split(rt, rt, r, k-tree[lt].size-1), up(x);
}
int rank(int x, int w)
{
    if(!x) return 0;
    if(tree[x].sum>=w) return rank(lt, w);
    return rank(rt, w)+tree[lt].size+1;
}
inline void insert(int delta)
{
    int x, y, rk=rank(root, delta);
    split(root, x, y, rk);
    build(tmp, delta); 
    merge(x, x, tmp); merge(root, x, y);
}
inline void del(int delta)
{
    int x, y, z, rk=rank(root, delta)+1;
    split(root, x, y, rk); split(x, x, z, rk-1);
    merge(root, x, y);
}
inline int find(int delta)
{
    int x, y, z, ans;
    split(root, x, y, delta); split(x, z, x, delta-1);
    ans=tree[x].sum;
    merge(x, z, x); merge(root, x, y);
    return ans;
}
inline int pre(int delta)
{
    int x, y, z, ans, rk=rank(root, delta);
    split(root, x, y, rk); split(x, z, x, rk-1);
    ans=tree[x].sum; 
    merge(x, z, x); merge(root, x, y);
    return ans;
}
inline int succ(int delta)
{
    int x, y, z, ans, rk=rank(root, delta+1);
    split(root, x, y, rk+1); split(x, z, x, rk);
    ans=tree[x].sum;
    merge(x, z, x); merge(root, x, y);
    return ans;
}
int main()
{
    srand(19260817); read(n); tree[0].rnd=tree[0].sum=inf;
    for(int i=1;i<=n;i++)
    {
        read(opt); read(x);
        if(opt==1) insert(x);
        else if(opt==2) del(x);
        else if(opt==3) printf("%d\n", rank(root, x)+1);
        else if(opt==4) printf("%d\n", find(x));
        else if(opt==5) printf("%d\n", pre(x));
        else printf("%d\n", succ(x));
    }
}