#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define pb push_back
#define st first
#define nd second

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, s;
	cin >> n >> s;
	int S = s;
	s = abs(s);
	vector<bool>tab(n, 0);
	int maxx =  n*(n-1)/2;
	int a = s+maxx, x = 0;
	if (abs(s) > maxx || (a&1)){
		cout << "NIE\n";
		return 0;
	}
	a/=2;
	//debug(a);
	for (int i = n-1; i>=1; i--){
		if (a>i) {
			a-=i;
			tab[i] = 1;
		}
	}
	tab[a] = 1;
	int add;
	if (S < 0) add = -1;
	else add = 1;
	cout << "0\n";
	for (int i = 1; i<n; i++){
		//debug(tab[i]);
		if (tab[i]) x+=add;
		else x-=add;
		cout << x << "\n";
		
	}
	return 0;
}
