// Anadi Agrawal
// Zgłoszenie na 12 ILOCAMP
// 2016-01-21
// Złożoność: O(q*n), ogromna stała
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>

const int mxn = 1e6 + 9;
const LL INF = 1000000000000000001LL;

int n, w;
int mx = 0;
PII T[mxn];
LL wpref[mxn];
LL wsuf[mxn];
LL suf[mxn];

LL wylicz(int from, int mid, int to, int l){
	LL x = 0LL;
	if(mid > from)
		x = wsuf[from] - wsuf[mid] - (LL)(n - mid) * (suf[from] - suf[mid]);

	if(mid < n)
		x += wpref[to - 1] - wpref[mid] - (LL)mid * (suf[mid + 1] - suf[to]);

	x += (LL)(to - mid) * ((LL)l - suf[from] + suf[to]);
	return x;
}

LL wylicz2(int to, int mid, int from, int l){
	LL x = 0LL;
	if(mid < from)
		x += wpref[from] - wpref[mid] - (LL)mid * (suf[mid + 1] - suf[from + 1]);

	if(mid > 0)
		x += wsuf[to + 1] - wsuf[mid] - (LL)(n - mid) * (suf[to + 1] - suf[mid]);

	x += (LL)(mid - to) * ((LL)l - suf[to + 1] + suf[from + 1]);
	return x;
}

void solve(int a){
	if(a <= mx){
		puts("0");
		return;
	}

	if(a > suf[0]){
		puts("-1");
		return;
	}

	int wsk1 = 0;
	int wsk2 = 0;
	LL result = INF;
	for(int i = 0; i < n; ++i){
		while(suf[i] - suf[wsk2 + 1] < a && wsk2 <= n)
			++wsk2;
		if(wsk2 > n)
			break;
		if(wsk1 < i)
			++wsk1;
		LL now = wylicz(i, wsk1, wsk2, a);
		while(wsk1 < wsk2){
				if(wylicz(i, wsk1, wsk2, a) > now)
					break;
				now = wylicz(i, wsk1, wsk2, a);
				++wsk1;
		}
		--wsk1;
		result = min(result, now);
	}

	wsk2 = n;
	wsk1 = n;
	for(int i = n; i > 0; --i){
		while(suf[wsk2] - suf[i + 1] < a && wsk2 >= 0)	--wsk2;
		if(wsk2 < 0)	break;
		if(wsk1 > i)	--wsk1;
		LL now = wylicz2(wsk2, wsk1, i, a);
		while(wsk1 > wsk2){
			if(wylicz2(wsk2, wsk1, i, a) > now)
				break;
			now = wylicz2(wsk2, wsk1, i, a);
			--wsk1;
		}
		++wsk1;
		result = min(result, now);
	}

	printf("%lld\n", result);
}

int main(){
	scanf("%d %d", &n, &w);
	T[0].st = 0;
	for(int i = 1; i <= n; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		T[i - 1].nd = a;
		T[i].st = a + b;
		mx = max(mx, T[i - 1].nd - T[i - 1].st);
	}
	T[n].nd = w;
	mx = max(mx, T[n].nd - T[n].st);

	for(int i = 1; i <= n; ++i)
		wpref[i] = wpref[i - 1] + (LL)i * (LL)(T[i].nd - T[i].st);
	for(int i = n - 1; i >= 0; --i)
		wsuf[i] = wsuf[i + 1] + (LL)(n - i) * (LL)(T[i].nd - T[i].st);

	for(int i = n; i >= 0; --i)
		suf[i] = suf[i + 1] + T[i].nd - T[i].st;

	int q;
	scanf("%d", &q);
	while(q--){
		int a;
		scanf("%d", &a);
		solve(a);
	}

	return 0;
}
