#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;

const int M = 33554440;
int n;
long long s;
bitset<25> state = 1, newState, cycleBeginState;
bitset<25> matrix[30];
bool map[M];
vector <bitset<25> > path;

void moveToNextState() {
    newState = state;
    for (int i=1; i<=n; i++) {
        int value = (state & matrix[i]).count();
        value %= 2;
        newState.set(i-1, value);
    }
    state = newState;
}

int main() {
    scanf("%d %lld", &n, &s);
   
    for (int i=1; i<=n; i++) {
        int m;
        scanf("%d", &m);
        
        while (m--) {
            int a;
            scanf("%d", &a);
            matrix[i].set(a-1, 1);
        }
    }
    
    path.push_back(state);
    map[1] = true;
    bool cycleFound = false;
    
    long long last = s + 1;
    for (int i=1; i<=s; i++) {
        moveToNextState();

        if (map[state.to_ullong()]) {
            cycleFound = true;
            cycleBeginState = state;
            last = i;
            break;
        }
        
        path.push_back(state);
        map[state.to_ullong()] = true;
    }
    
    printf("%lld\n", last);
    return 0;
    
    long long result = 0, cycleVibrations = 0;
    int cycleLength, cycleBeginIndex;
    bool cycle = false;
    
    for (int i=0; i<last; i++) {
        if (path[i] == cycleBeginState) {
            cycleLength = last - i;
            cycleBeginIndex = i;
            cycle = true;
        }
        if (cycle) 
            cycleVibrations += path[i].count();
        if (i > 0)
            result +=path[i].count();
    }
    
    if (cycle && cycleLength) {
        long long repeats = (s - last + 1) / cycleLength;
        int trail = (s - last + 1) % cycleLength;       
        
        result += repeats * cycleVibrations;
        
        for (int i=cycleBeginIndex; i<cycleBeginIndex+trail; i++)
            result += path[i].count();
    }
    
    printf("%lld\n", result);
    
    return 0;
}