#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	if (k>=(n*m) || k < m+n-2) {
		cout << "NIE\n";
		return 0;
	}
	if (n&1){
		k-=(m+n-2);
		int x = 1, y = 1, direction = -1;
		while (y<n/2){
			if (y&1){
				while (x <= m){
					cout << y << " " << x << " " << y << " " << x+1 << "\n";
					x++;
					k--;
					if (!k) {
						direction = 0;//w prawo
						break;
					}
				}
				y++;
			} else {
				while (x >= 2){
					x--;
					cout << y << " " << x << " " << y << " " << x-1 << "\n";
					k--;
					if (!k) {
						direction = 1;//w lewo
						break;
					}
				}
				y++;
			}
		}
		debug(x);
		debug(y);
		y = n/2+1;
		while (y<=n){
			
		}
	} else {
		if (m&1){
			//swap
			
		} else {
			if (k < m+n-1) {
				cout << "NIE\n";
				return 0;
			}
			
		}
	}
	
	return 0;
}
