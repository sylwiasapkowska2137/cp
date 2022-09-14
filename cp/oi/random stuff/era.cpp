#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second

const int MAX = 30;
int tab[3][MAX];
map<pair<LL, LL>, string>s;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, num;
	LL ans = -1, x, y, z;
	string k, out;
	cin >> n;
	for (int i = 0; i<n; i++) cin >> tab[0][i] >> tab[1][i] >> tab[2][i];
	int l = n/2;
	int r = n-l;
	for (int i = 0; i<(int)pow(3, l); i++){
		num = i;
		k.clear();
		x = 0, y = 0, z = 0;
		for (int j = 0; j<l; j++){
			a = num%3;
			k+=(char)(a+'0');
			if (a == 0) {
				y+=tab[1][j];
				z+=tab[2][j];
			} else if (a == 1){
				x+=tab[0][j];
				z+=tab[2][j];
			} else {
				x+=tab[0][j];
				y+=tab[1][j];
			}
			num/=3;
		}
		s[{x-y, x-z}] = k;
	}
	for (int i = 0; i<(int)pow(3, r); i++){
		num = i;
		k.clear();
		LL x = 0, y = 0, z = 0;
		for (int j = 0; j<r; j++){
			a = num%3;
			k+=(char)(a+'0');
			if (a == 0) {
				y+=tab[1][j+l];
				z+=tab[2][j+l];
			} else if (a == 1){
				x+=tab[0][j+l];
				z+=tab[2][j+l];
			} else {
				x+=tab[0][j+l];
				y+=tab[1][j+l];
			}
			num/=3;
		}
		
		auto it = s.find({y-x, z-x});
		if (it != s.end()){
			LL t = 0;
			for (int j = 0; j<l; j++){
				if (k[j]!='0') t+=(LL)tab[0][j];
			}
			for (int j = 0; j<r; j++){
				if ((it->nd[j])!='0') t+=(LL)tab[0][j+l];
			}
			if (t > ans){
				ans = t;
				out = (it->nd)+k;
			}
		}
	}
	if (ans == -1){
		cout << "Impossible\n";
		return 0;
	}
	for (int i = 0; i<out.size(); i++){
		if (out[i]=='0') cout << "MW\n";
		else if (out[i] == '1') cout << "LW\n";
		else cout << "LM\n";
	}
	return 0;
}
