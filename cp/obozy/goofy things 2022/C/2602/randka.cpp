#include <bits/stdc++.h>
using namespace std;

struct Point{
	long long x, y; 
	int idx;
	void read(int i){
		cin >> x >> y;
		idx = i;
	}
	Point(){}
	Point (int _x, int _y){
		x = _x, y = _y;
	}

	Point& operator-=(const Point &t){
		x-=t.x;
		y-=t.y;
		return *this;
	}
};

long long dist(Point A, Point B){
	long long x = A.x-B.x;
	long long y = A.y-B.y;
	return x*x+y*y;
}

int orientation(Point A, Point B, Point C){
	A-=C; B-=C;
	long long c = B.y*A.x-B.x*A.y;
	if (c > 0) return 1;
	if (c < 0) return -1;
	return 0;
}
 
bool cw(Point A, Point B, Point C, bool include_collinear){
	int o = orientation(A, B, C);
	return (o < 0 || (include_collinear && !o));
}
 
bool collinear(Point A, Point B, Point C){
	return (orientation(A, B, C) == 0);
}

long long pole(Point A, Point B, Point C){
	B-=A, C-=A;
	return abs(C.y*B.x-C.x*B.y);
}

pair<pair<int, int>, long long> solve(vector<Point>&points, bool include_collinear = false){
	vector<Point>a = points;
	Point p0 = *min_element(a.begin(), a.end(), [](Point A, Point B){return make_pair(A.y, A.x) < make_pair(B.y, B.x);});
	sort(a.begin(), a.end(), [&p0](const Point& A, const Point& B){
		int o = orientation(p0, A, B);
		if (!o) return dist(p0, A) < dist(p0, B);
		return (o < 0);
	});
	if (include_collinear){
		int i = (int)a.size()-1;
		while (i && collinear(p0, a[i], a.back())) i--;
		reverse(a.begin()+i+1, a.end());
	}
	vector<Point>p;
	for (int i = 0; i<(int)a.size(); i++){
		while ((int)p.size() > 1 && !cw(p[(int)p.size()-2], p.back(), a[i], include_collinear)) p.pop_back();
		p.push_back(a[i]);
	}
	//for (auto [x, y, idx]:p)cerr << x << " " << y << " " << idx << "\n";
	int H = (int)p.size();
	pair<pair<int, int>, long long> ans = {{0, 0}, 0};
	for(int i=0, j=1; i<H; i++) {
    	while (pole(p[i], p[(i+1)%H], p[j]) < pole(p[i], p[(i+1)%H], p[(j+1)%H])) j = (j+1)%H;
		if (dist(p[i], p[j]) > ans.second) ans = {{p[i].idx, p[j].idx}, dist(p[i], p[j])};
		if (dist(p[(i+1)%H], p[j]) > ans.second) ans = {{p[(i+1)%H].idx, p[j].idx}, dist(p[(i+1)%H], p[j])};
	}
	return ans;
}

void solve(){
	int n; cin >> n;
	vector<Point>points(n);
	for (int i = 0; i<n; i++) points[i].read(i);
	int k = n-1;
	vector<long long>ans(n, -1);
	//pair<pair<int, int>, long long> curr = solve(points);
	//debug(curr);
	while (1){
		if ((int)points.size() <= 1) break;
		pair<pair<int, int>, long long> curr = solve(points);
		//debug(curr);
		int x = max(curr.first.first, curr.first.second);
		while ((int)points.size() > x) {
			points.pop_back();
			k--;
		}
		ans[k+1] = curr.second;
	}
	ans[0] = 0;
	for (int i = 1; i<n; i++) ans[i] = max(ans[i], ans[i-1]);
	//debug(ans);
	for (int i = 0; i<n; i++) cout << ans[i] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}