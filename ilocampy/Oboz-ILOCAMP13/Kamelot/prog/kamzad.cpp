#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

const int M = 100005;
long long n, k, a, b, t, tmin, answer, maxDistance, l, r, act, used;
vector <pair <long long, pair <long long, long long> > > G[M];
long long distances[M];
bool visited[M];

void countDistances(int w) {
    visited[w] = true;
    
    for (int i=0; i<G[w].size(); i++) {
        pair <long long, pair <long long, long long> > s = G[w][i]; 
        
        if (!visited[s.ff]) {
            countDistances(s.ff);
            distances[w] = max(distances[w], distances[s.ff] + s.ss.ff);
            maxDistance = max(maxDistance, distances[w]);
        }
    }
}

bool DFS(int w, long long current) {
    visited[w] = true;
    
    for (int i=0; i<G[w].size(); i++) {
        pair <long long, pair <long long, long long > > s = G[w][i]; 
        
        if (!visited[s.ff]) {
            long long lack = current + s.ss.ff + distances[s.ff] - act;
                
            if (lack > 0) {
                used += min(lack, s.ss.ff - s.ss.ss);

                if (used > k || current + s.ss.ss > act)
                    return false;
                
                if (s.ss.ff - s.ss.ss < lack) {
                    if (!DFS(s.ff, current + s.ss.ss))
                        return false;
                }
            }
        }
    }
    
    return true;
}

int main() {
    scanf("%lld %lld", &n, &k);
    
    for (int i=0; i<n-1; i++) {
        scanf("%lld %lld %lld %lld", &a, &b, &t, &tmin);
        
        G[a].push_back(make_pair(b, make_pair(t, tmin)));
        G[b].push_back(make_pair(a, make_pair(t, tmin)));
    }
    
    countDistances(1);
    
    l = 0;
    r = maxDistance;
    act = -1;
    
    while ((l + r) / 2 != act) {
        for (int i=1; i<=n; i++)
             visited[i] = false;
        used = 0;
        
        act = (l + r) / 2;
        if (DFS(1, 0)) {
            r = act;
            answer = act;
        }
        else
            l = act + 1;
    }
    
    printf("%lld\n", answer);
    
    return 0;
}