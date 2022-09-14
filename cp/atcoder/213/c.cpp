#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	map<int, int>mapx, mapy;
	int h, w, n, a, b;
	cin >> h >> w >> n;
	vector<int>height, width;
	vector<pii>cards;
	for (int i = 0; i<n; i++){
		cin >> a >> b;
		cards.pb({a, b});
		height.pb(a);
		width.pb(b);
	}
	sort(height.begin(), height.end());
	sort(width.begin(), width.end());
	height.erase(unique(height.begin(), height.end()), height.end());
	width.erase(unique(width.begin(), width.end()), width.end());
	for (int i = 0; i<(int)height.size(); i++) mapx[height[i]] = i+1;
	for (int i = 0; i<(int)width.size(); i++) mapy[width[i]] = i+1;
	
	for (auto x: cards){
		cout << mapx[x.st] << " " << mapy[x.nd] << "\n";
	}
	return 0;
}



