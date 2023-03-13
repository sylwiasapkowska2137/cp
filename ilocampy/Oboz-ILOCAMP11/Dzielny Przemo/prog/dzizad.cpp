#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

int n;
int tab[N];
int intervalMaxBegin[N], intervalMaxEnd[N], intervalMinBegin[N], intervalMinEnd[N];
pair<int, int> S[N], S2[N];
int Ssize, S2size;
vector<pair<int, int> >events[N];
bool out[N], out2[N];

priority_queue<pair<int, int> >Q, Q2;

void init() {
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        while (Ssize > 0 && S[Ssize].first < tab[i]) {
            Ssize--;
        }
        while (S2size > 0 && S2[S2size].first > tab[i]) {
            S2size--;
        }
        
        if (Ssize > 0) {
            intervalMaxBegin[i] = S[Ssize].second + 1;
        } else {
            intervalMaxBegin[i] = 1;
        }
        
        if(S2size > 0) {
            intervalMinBegin[i] = S2[S2size].second + 1;
        } else {
            intervalMinBegin[i] = 1;
        }
        S[++Ssize] = {tab[i], i};
        S2[++S2size] = {tab[i], i};
    }
    
    Ssize = S2size = 0;
    
    for (int i = n; i >= 1; i--) {
        while(Ssize > 0 && S[Ssize].first < tab[i]) {
            Ssize--;
        }
        while(S2size > 0 && S2[S2size].first > tab[i]) {
            S2size--;
        }
        
        if (Ssize > 0) {
            intervalMaxEnd[i] = S[Ssize].second - 1;
        } else {
            intervalMaxEnd[i] = n;
        }
        
        if (S2size > 0) {
            intervalMinEnd[i] = S2[S2size].second - 1;
        } else {
            intervalMinEnd[i] = n;
        }
        
        S[++Ssize] = {tab[i], i};
        S2[++S2size] = {tab[i], i};
    }
}

int main() {
    scanf("%d", &n);
    
    init();
    
    for (int i = 1; i <= n; i++) {
        events[intervalMaxEnd[i]].push_back({i, 0});
        events[intervalMinBegin[i]].push_back({i, 1});
    }
    
    int ans = 0;
    for(int j = 0; j < events[1].size(); j++) {
        int in = events[1][j].first;
        int type = events[1][j].second;
        if (type == 1) {
            Q.push({intervalMinEnd[in], in});
        }
    }
    for (int i = 1; i <= n; i++) {
        for(int j = 0; j < events[i + 1].size(); j++) {
            int in = events[i + 1][j].first;
            int type = events[i + 1][j].second;
            
            if (type == 1) {
                Q.push({intervalMinEnd[in], in});
            }
        }
        
        out[i] = true;
        
        Q2.push({-intervalMaxBegin[i], i});
        while(!Q.empty() && out[Q.top().second] == true) {
            Q.pop();
        }
        
        while(!Q2.empty() && out2[Q2.top().second] == true) {
            Q2.pop();
        }
        
        if (!Q.empty() && !Q2.empty()) {
            ans = max(ans, Q.top().first + Q2.top().first + 1);
        }
        
        for (int j = 0; j < events[i].size(); j++) {
            int in = events[i][j].first;
            int type = events[i][j].second;
            
            if (type == 0) {
                out2[in] = true;
            }
        }
        
    }

    
    printf("%d\n", ans);
    
    return 0;
}