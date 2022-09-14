#include <bits/stdc++.h>

using namespace std;

struct point{
	int x,y,z;
	point() {}
	point(int x, int y, int z): x(x), y(y), z(z){}
};
vector <point> tab;

bool cmp(point a, point b){
	if (a.x == b.x){
		if (a.y == b.y){
			return (a.z < b.z);
		} return (a.y < b.y);
	} return (a.x < b.x);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, a, b, c;
	cin >> n;
	for (int i = 0; i<n; i++){
		cin >> a >> b >> c;
		point x(a,b,c);
		tab.push_back(x);
	}
	sort(tab.begin(), tab.end(), cmp);
	for (auto x: tab) cout << x.x << " " << x.y << " " << x.z << "\n";
	return 0;
}

