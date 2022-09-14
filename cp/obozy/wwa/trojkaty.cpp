//92
#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, ans = 0;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int ptr = 0;
	while (ptr+2<n){
		if (a[ptr]+a[ptr+1]>a[ptr+2]){
			ans++;
			ptr+=3;
		} else ptr++;
		//debug(ptr);
	}
	cout << ans;
	return 0;
}

