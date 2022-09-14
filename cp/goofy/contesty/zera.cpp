#include <bits/stdc++.h>

using namespace std;
#define LL long long
queue < pair <string, int> > q;
set<int> visit;

string solve(int n){
	pair <string ,int> tmp;
	while (!q.empty()) q.pop();
	q.push({"1", 1});
	while (!q.empty()){
		tmp = q.front();
		q.pop();
		if (tmp.second == 0) return tmp.first;
		else if (visit.find(tmp.second) == visit.end()){
			visit.insert(tmp.second);
			q.push({tmp.first+"0", (tmp.second*10+n)%n});
			q.push({tmp.first+"1", (tmp.second*10+1+n)%n});
		}
	} 
	return tmp.first;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int z, a;
	cin >> z;
	while (z--){
		cin >> a;
		visit.clear();
		cout << solve(a) << "\n";
	}
	return 0;
}


