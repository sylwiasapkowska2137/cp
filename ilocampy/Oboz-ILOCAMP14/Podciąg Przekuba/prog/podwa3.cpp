#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <set>
#include <string.h>
#define MAXN 500000
#define INF 10001
#define EPS 0.00000001
#define LL long long
#define re return
#define N 5010
#define K 5010
using namespace std;

short k;

typedef struct{ short a[N], n; short next[N][K]; }tn;
void cntNext(tn & a) {
	short prev[K];
	for (short ki = 1; ki <= k; ++ki) prev[ki] = a.n + 1;
	for (short i = a.n - 1; i >= 0; --i) {
		prev[a.a[i]] = i + 1;

		for (short ki = 1; ki <= k; ++ki)
			a.next[i][ki] = prev[ki];
	}
	for (short ki = 1; ki <= k; ++ki) {
		a.next[a.n + 1][ki] = a.n + 1;
		a.next[a.n][ki] = a.n + 1;
	}
}

short d[N][N];
short ch[N][N];
tn a, b;

short go(short &ia, short &ib, short deep) {
	
	if (ia >= a.n + 1 && ib >= b.n + 1) {
		re 0;
	}
	if (ia >= a.n && ib >= b.n) {
		ch[ia][ib] = 1;
		re 1;
	}
	if (d[ia][ib] != 0) {
		re d[ia][ib] - 1;
	}
	short * anext = a.next[ia];
	short * bnext = b.next[ib];

	short my = INF, &mch = ch[ia][ib];
	if (deep > (10000/k) + 200)re my;

		for (short ki = 1; ki <= k; ++ki) {
			short res = go(anext[ki], bnext[ki], deep + 1);
			if (res < my) {
				my = res;
				mch = ki;
				if (res == 0)
					break;
			}
		}
	
	d[ia][ib] = my + 2;
	re my + 1;
}

int main(){
	cin >> k;

	cin >> a.n;
	for (short i = 0; i < a.n; ++i)cin >> a.a[i];
	cin >> b.n;
	for (short i = 0; i < b.n; ++i)cin >> b.a[i];

	cntNext(a);
	cntNext(b);

	short u = 0, o = 0;
	short res = go(u, o, 1);
	cout << res << endl;
	for (short i = 0, ia = 0, ib = 0; i < res; ++i){
		cout << ch[ia][ib] << " ";
		int ia1 = a.next[ia][ch[ia][ib]];
		int ib1 = b.next[ib][ch[ia][ib]];
		ia = ia1;
		ib = ib1;
	}
	re 0;
}
