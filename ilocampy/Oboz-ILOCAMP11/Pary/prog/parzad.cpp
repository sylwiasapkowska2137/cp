#include <bits/stdc++.h>

using namespace std;

const int N = 1000005, REPEATS = 30;

int n;
int bestFriend[N], sex[N];
bool wasResultCalculated[N];
pair<int, int> dp[N], dpMatched[N], dpNotMatched[N];
bool odw[N];
vector<int> V[N];
int back[N];

pair<int, int> operator + (const pair<int, int>&A, const pair<int, int> &B) {
    return {A.first + B.first, A.second + B.second};
}

pair<int, int> calcResult(vector<int> &nodes) {
    dp[0] = dpMatched[nodes[0]];
    for (int i = 1; i < nodes.size(); i++) {
        pair<int, int> toAdd = {1, sex[nodes[i]] != sex[nodes[i - 1]]};
        pair<int, int> zeroPair = {0, 0};
        dp[i] = max(dpNotMatched[nodes[i]] + dpNotMatched[nodes[i - 1]] + toAdd + (i > 1? dp[i - 2]: zeroPair), dpMatched[nodes[i]] + dp[i - 1]);
    }
    return dp[nodes.size() - 1];
}

void countDP(int w) {
    wasResultCalculated[w] = true;
    vector<pair<int, int> > pref(V[w].size());
    pair<int, int> sum = {0, 0};
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
    
        if (back[w] == u) {
            swap(V[w][i], V[w].back());
            V[w].pop_back();
            i--;
            continue;
        }
        
        countDP(u);
        if (i == 0) {
            pref[i] = dpMatched[u];
        } else {
            pref[i] = pref[i - 1] + dpMatched[u];
        }
        sum = sum + dpMatched[u];
    }
    
    dpNotMatched[w] = sum;
    dpMatched[w] = dpNotMatched[w];
    sum = {0, 0};
    
    for (int i = V[w].size() - 1; i >= 0; i--) {
        int u = V[w][i];
       
            pair<int, int> toAdd1 = {1, sex[w] != sex[u]};
            pair<int, int> zeroPair = {0, 0};
            pair<int, int> toAdd = toAdd1 + (i == 0? zeroPair: pref[i - 1]);
            dpMatched[w] = max(dpMatched[w], sum + toAdd + dpNotMatched[u]);
            sum = sum + dpMatched[u];
    }
}


pair<int, int> answerForComponent(int startNode) {
    vector<int> visitedNodes;
    
    while (odw[startNode] == false) {
        visitedNodes.push_back(startNode);
        odw[startNode] = true;
        startNode = bestFriend[startNode];
    }
    
    for (int x: visitedNodes) {
        odw[x] = false;
    }
    
    visitedNodes.clear();
    
    while (odw[startNode] == false) {
        back[bestFriend[startNode]] = startNode;
        odw[startNode] = true;
        visitedNodes.push_back(startNode);
        startNode = bestFriend[startNode];
    }
    
    for (int x: visitedNodes) {
        countDP(x);
    }
    
    pair<int, int> ret = {0, 0};
    
    for (int repeats = 0; repeats < min(2, (int)visitedNodes.size()); repeats++) {
        int cut = repeats;
        vector<int> nodes;
        for (int j = cut; j < visitedNodes.size(); j++) {
            nodes.push_back(visitedNodes[j]);
        }
        for (int j = 0; j < cut; j++) {
            nodes.push_back(visitedNodes[j]);
        }
        ret = max(ret, calcResult(nodes));
    }
    
    return ret;
}

int main() {
    srand(515101971);
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &bestFriend[i], &sex[i]);
        V[bestFriend[i]].push_back(i);
    }
    
    pair<int, int> ans = {0, 0}; 
    for (int i = 1; i <= n; i++) {
        if (wasResultCalculated[i] == false) {
            ans = ans + answerForComponent(i);
        }
    }
    
    printf("%d %d\n", ans.first, ans.second);
    return 0;
}