#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

LL num(string &c){
	LL ans = 0LL;
	for (int i = 0; i<(int)c.size(); i++){
		ans*=10;
		ans+=(LL)(c[i]-'0');
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, first = -1, second = -1;
	LL value1, value2;
	string c;
	cin >> n;
	for (int i = 0; i<n; i++){
		cin >> c;
		if (c[0] == '*') continue;
		if (first == -1) {
			value1 = num(c);
			first = i+1;
		} else if (second == -1){
			value2 = num(c);
			second = i+1;
		} 
		//else break;
	}
	LL r = (value2-value1)/(second-first);
	LL f = value1 - ((LL)first-1)*r;
	cout << f << " " << r << "\n";
	return 0;
}


