#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	LL res = 0;
	int n;
	cin >> n;
	vector <LL> a(n);
	stack<LL>s;
	for (int i = 0; i<n; i++) cin >> a[i];
	s.push(LLONG_MAX);
	s.push(a[n-1]);
	for (int i = n-2; i>=0; i--){
		if (a[i]<s.top()) {
			res+=s.size()-1;
			s.push(a[i]);
		} else {
			res+=s.size()-1;
			while (s.top() < a[i]) s.pop();
			s.push(a[i]);
		}
	}
	cout << res;
	return 0;
}
