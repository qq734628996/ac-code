#include <algorithm>
#include <iostream>
#include <cctype>
#include <climits>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <ctime>
#include <stack>
#define ls ch[0]
#define rs ch[1]
using namespace std;

int _n, _ch; bool _flag;
inline int ReadInt() {
    _n = 0, _ch = getchar(), _flag = false;
    while (!isdigit(_ch)) _flag |= _ch == '-', _ch = getchar();
    while (isdigit(_ch)) _n = (_n << 3) + (_n << 1) + _ch - '0', _ch = getchar();
    return _flag ? -_n : _n;
}

const int maxn = 50000 + 3, maxadd = 100 + 3, INF = 0x3f3f3f3f;
struct Treap *null, *pit;
struct Treap {
    int key, val, s;
    Treap *ch[2];
    Treap() {}
    Treap(int key, int val = rand()): key(key), val(val), s(1) {ch[0] = ch[1] = null;}
    void *operator new(size_t) {return pit++;}
    inline void maintain() {s = ch[0] -> s + ch[1] -> s + 1;}
}pool[4000000 + 3], *root[maxn];

inline Treap* newNode(const Treap *o) {
    if (o == null) return null;
    Treap *now = new Treap();
    *now = *o;
    return now;
}

Treap* merge(const Treap *a, const Treap *b) {
    if (a == null) return newNode(b);
    if (b == null) return newNode(a);
    if (a -> val < b -> val) {
        Treap *na = newNode(a);
        na -> rs = merge(a -> rs, b);
        na -> maintain();
        return na;
    }else {
        Treap *nb = newNode(b);
        nb -> ls = merge(a, b -> ls);
        nb -> maintain();
        return nb;
    }
}

typedef pair<Treap*, Treap*> Droot;

Droot split(const Treap *o, int k) {
    Droot d(null, null);
    if (o == null) return d;
    if (k == 0) return Droot(null, newNode(o));
    if (k == o -> s) return Droot(newNode(o), null);
    int s = o -> ls -> s;
    Treap *newroot = newNode(o);
    if (k <= s) {
        d = split(o -> ls, k);
        newroot -> ls = d.second;
        newroot -> maintain();
        d.second = newroot;
    }else {
        d = split(o -> rs, k - s - 1);
        newroot -> rs = d.first;
        newroot -> maintain();
        d.first = newroot;
    }
    return d;
}

Treap *stk[maxadd];
Treap *build(char *str) {
    Treap *root = new Treap(-INF, -INF);
    stk[0] = root; int sz = 1;
    for (int i = 0; str[i]; ++i) {
        Treap *now = new Treap(str[i]); int p = sz - 1;
        while (stk[p] -> val > now -> val) stk[p--] -> maintain();
        if (p != sz - 1) now -> ls = stk[p + 1];
        stk[p] -> rs = now; sz = p + 1;
        stk[sz++] = now;
    }
    while (sz) stk[--sz] -> maintain();
    return root = root -> rs;
}

int cntC = 0;
void print(Treap *o) {
    if (o == null) return;
    print(o -> ls);
    putchar(o -> key);
    if (o -> key == 'c') cntC++;
    print(o -> rs);
}

char a[maxadd];
int main() {
    srand(time(NULL));
    pit = pool, null = new Treap();
    null -> s = 0;
    int n = ReadInt(), cnt = 0;
    root[cnt] = null;
    for (int i = 0; i < n; ++i) {
        int oper = ReadInt();
        if (oper == 1) {
            int p = ReadInt() - cntC;
            scanf("%s", a);
            Droot l = split(root[cnt], p);
            root[++cnt] = merge(merge(l.first, build(a)), l.second);
        }else if (oper == 2) {
            int p = ReadInt() - cntC, c = ReadInt() - cntC;
            Droot l = split(root[cnt], p - 1), r = split(l.second, c);
            root[++cnt] = merge(l.first, r.second);
        }else if (oper == 3) {
            int v = ReadInt() - cntC, p = ReadInt() - cntC, c = ReadInt() - cntC;
            Droot l = split(root[v], p - 1);
            Droot r = split(l.second, c);
            print(r.first); putchar('\n');
        }else assert(false);
    }
    return 0;
}
