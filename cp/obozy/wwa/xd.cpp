#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

bool warunek(int n, int m, LL k, LL mid){
	LL cnt = 0LL;
	for (LL i = 1; i<=(LL)m; i++) cnt+=(LL)min(mid/i, (LL)n);
	if (cnt < k) return 1;
	return 0;
}

LL binsracz(int n, int m, LL k){
	LL start = 1, koniec = (LL)n*(LL)m;
	while (koniec>start){
		LL mid = start+(koniec-start)/2;
		if (warunek(n, m, k, mid)) start = mid+1;
		else koniec = mid;
	}
	return start;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	LL k;
	cin >> n >> m >> k;
	cout << binsracz(n, m, k) << "\n";
	return 0;
}



