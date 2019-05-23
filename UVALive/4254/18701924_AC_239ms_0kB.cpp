#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 10005;
struct P {
	int st, en, w;
	friend bool operator < (const P &a, const P &b) {
		return a.en > b.en;
	}
}p[N];
int n;
 
int cmp(P a, P b) {
	return a.st < b.st;
}
 
bool judge(int x) {
	priority_queue<P> q;
	int t = 1, i = 0;
	while (1) {
		while (i < n && t >= p[i].st)
			q.push(p[i++]);
		int re = x;	
		while (re != 0 && !q.empty()) {
			P u = q.top();
			q.pop();
			int temp = min(re, u.w);
			re -= temp;
			u.w -= temp;
			if (u.w != 0)
				q.push(u);
		}
		t++;
		if (!q.empty() && q.top().en <= t)
			return false;	
		if (q.empty() && i == n)
			return true;
	}
}
 
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int l = 0, r = N;
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &p[i].st, &p[i].en, &p[i].w);
		}
		sort(p, p + n, cmp);
		while (l < r) {
			int mid = (l + r) / 2;	
			if (judge(mid))
				r = mid;
			else
				l = mid + 1;
		}
		printf("%d\n", l);
	}
	return 0;
}
