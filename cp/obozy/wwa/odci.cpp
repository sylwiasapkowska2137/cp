#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define LD long double
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
const int MAX = 1e5+7;
struct elem{
	int x1, y1, x2, y2;
	elem(){}
	elem(int a, int b, int c, int d): x1(a), y1(b), x2(c), y2(d) {}
};
vector<elem>poziom, pion;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, x, y, x1, x2, y1, y2;
	cin >> n >> m;
	for (int i = 0; i<n; i++){
		cin >> x1 >> x2 >> y;
		poziom.pb({x1, y, x2, y});
	}
	
	for (int i = 0; i<m; i++){
		cin >> y1 >> y2 >> x;
		pion.pb({x, y1, x, y2});
	}
	int ans = 0;
	for (int i = 0; i<n; i++){
		for (int j = 0; j<m; j++){
			elem X = poziom[i];
			elem Y = pion[j];
			if (X.x1 <= Y.x1 && X.x2 >= Y.x1 && X.y1 >= Y.y1 && X.y1 <= Y.y2){
				ans = max(ans, min(min(Y.), min()));
			}
			
			
			ans = max(ans, )
		}
	}
	return 0;
}

