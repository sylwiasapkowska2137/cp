#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

int init(string s){
	int ans = 0;
	for (int i = 0; i<(int)s.size(); i++){
		ans+= ((s[i]-'0')*(s[i]-'0'));
	}
	return ans;
}

int suma(int n){
	int ans = 0;
	while (n){
		ans += ((n%10)*(n%10));
		n/=10;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	string s;
	for (int i = 0; i<n; i++){
		cin >> s;
		if (s == "1" || s == "4"){
			cout << s << "\n";
			continue;
		} 
		int x = init(s);
		cout << s << " " << x << " ";
		while (x != 4 && x != 1){
			x = suma(x);
			cout << x << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
