#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << x << " "
#define LL long long
#define LD long double
#define pb push_back

struct p{ 
	LL x, y; 
	p(LL x, LL y): x(x), y(y) {}
};
vector <p> tab, ans;
stack <p> s;

bool cmp(p a, p b){
	if (a.y == b.y) return (a.x < b.x);
	return (a.y < b.y);
}

LL iloczyn(p a, p b){
	return (a.x*b.y - a.y*b.x);
}

bool angle(p a, p b){
	LL ilo = iloczyn(a, b);
	if (ilo == 0){
		LL o1 = (a.x*a.x)+(a.y*a.y);
		LL o2 = (b.x*b.x)+(b.y*b.y);
		return (o1<o2);
	} return (ilo > 0);
}

p next() { 
    p v = s.top(); 
    s.pop(); 
    p res = s.top(); 
    s.push(v); 
    return res; 
} 

bool orientation(p a, p b, p c) { 
	LL val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y); 
	return (val >= 0)?1:0;
} 

double dist(p a, p b){
	return sqrt(double((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << setprecision(7) << fixed;
	int n;
	LL x, y;
	double res = 0;
	cin >> n;
	for (int i = 0; i<n; i++){
		cin >> x >> y;
		tab.pb({x, y});
	}
	sort(tab.begin(), tab.end(), cmp);
	p zero = tab[0];
	for (int i = 0; i<n; i++){
		tab[i].x -= zero.x;
		tab[i].y -= zero.y;
	}
	sort(tab.begin(), tab.end(), angle);
	for (int i = 0; i<3; i++) s.push(tab[i]);
	for (int i = 3; i<n; i++){
		while (orientation(next(), s.top(), tab[i])) s.pop(); 
		s.push(tab[i]); 
	}
	while (!s.empty()){
		p v = s.top();
		s.pop();
		ans.pb(v);
	}
	int m = ans.size();
	for (int i = 0; i<m; i++) {
		if (i == m-1) res+=dist(ans[m-1], ans[0]);
		else res += dist(ans[i], ans[i+1]);
	}
	cout << res;
	return 0;
}
