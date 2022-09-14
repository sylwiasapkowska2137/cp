#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
deque<pii>q;//(element, indeks)

void pop(int index){
	while (!q.empty() && q.front().nd <= index) q.pop_front();
}

void push(int val, int index){
	while (!q.empty() && q.back().st >= val) q.pop_back();
	q.push_back({val, index});
}

int minimum(){
	return q.front().st;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	for (auto x: a) debug(x);
	cerr << "\n";
	for (int i = 0; i<n; i++){
		if (i > k) pop(i-k);
		push(a[i], i);
		mini[i] = minimum(); //mini[i] = minimum na przedziale i-k, i
		//debug(minimum());
	}
	return 0;
}
