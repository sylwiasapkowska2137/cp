#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

#define debug false

const int M = 305;

pair <int, int> t[M];
pair <int, int> events[2*M];
pair <int, int> fred;
int pos, numberOfEvents = 1, runners = 1, n, peopleInInterval, beforeRow, p1, p2, minEnd = 1000000000;
long double result;
long double dp[M][M];
long double probabilityOfGroupsWithinGivenRunner[M];

bool moveP2() {
    while (p2 == events[pos].ff && pos <= numberOfEvents) {
        if (events[pos].ss < 0)
            peopleInInterval--;
        else
            peopleInInterval++;
        pos++;
    }
    
    if (pos > numberOfEvents)
        return false;
    
    p2 = events[pos].ff;
    
    return true;
}

bool moveP1() {
    while (p1 == events[beforeRow].ff && beforeRow <= numberOfEvents) 
        beforeRow++;
    
    if (beforeRow > numberOfEvents)
        return false;
    
    p1 = events[beforeRow].ff;
    
    return true;
}

long double probabilityForIntervalOfRunner(int p1, int p2, long double fullLength) {   
    long double length = p2 - p1;
    if (length == 0)
        return 0;
    if (fullLength == 0)
        return 1;
    return length/fullLength;
}

int runnerIntervalLength(int i) {
    return t[i].ss - t[i].ff;
}

long double probabilityOfWinningInterval(int runners) {
    return (long double)1 / (long double)(runners + 1);
}

bool skipEvents() {
    return (moveP2() && moveP1());
}

bool readInput() {
    scanf("%d", &n);

    for (int i=1; i<=n; i++) {
        scanf("%d %d", &t[runners].ff, &t[runners].ss);
        
        minEnd = min(minEnd, t[runners].ss);
        
        if (i > 1 && t[runners].ss < t[1].ff)
            return false;
        
        if (i == 1)
            fred = t[i];
        
        events[numberOfEvents].ff = t[runners].ff;
        events[numberOfEvents].ss = i;
        events[numberOfEvents+1].ff = t[runners].ss;
        events[numberOfEvents+1].ss = -i;
        runners++;
        numberOfEvents+=2;
    }
    numberOfEvents--;
    runners--;
    
    return true;
}

long double fredIsAPoint() {
    result = 1;
    
    for (int i=1; i<=runners; i++) {     
        if (t[i].ss <= fred.ff && t[i].ff < t[i].ss)
            return 0;
        
        if (t[i].ff < fred.ff && t[i].ss > fred.ff) 
            result *= probabilityForIntervalOfRunner(fred.ff, t[i].ss, runnerIntervalLength(i));
    }
    
    return result;
}


int main() {
    if (!readInput() ) {
        printf("0.000000\n");
        return 0;
    }
    
    if (fred.ff == fred.ss) {
        printf("%.8Lf\n", fredIsAPoint());
        return 0;
    }
    
    sort(events + 1, events + numberOfEvents + 1);
    
    pos = 1;
    p2 = events[pos].ff;
    beforeRow = 0;
    events[0].ff = -1;
    p1 = -1;
    
    while (true) {
        if (p2 == fred.ff) {
            skipEvents();
            break;
        }
        skipEvents();
    }
    
    while (pos <= numberOfEvents) {
        long double probabilityForThisInterval = 0;
        
        // all options of Fred's time have been already analized
        if (p1 >= fred.ss || p1 >= minEnd) break;
        
        long double allWereLater = 1, someWereInThisInterval = 1;
        int cannotbeLater = 0;
       
        for (int k=0; k<peopleInInterval; k++) {
            for (int i=0; i<runners; i++)
                dp[i][k] = 0;
        }
        
        dp[1][0] = 1;
        
        for (int i=2; i<=runners; i++) {
            if (t[i].ss <= p1 || t[i].ff >= p2) {
                dp[i][0] = dp[i-1][0];
            }
            else {
                dp[i][0] = dp[i-1][0] * probabilityForIntervalOfRunner(p2, t[i].ss, runnerIntervalLength(i));
            }
        }
        
        for (int k=1; k<peopleInInterval; k++) {
            for (int i=2; i<=runners; i++) {
                if (t[i].ss <= p1 || t[i].ff >= p2) {
                    dp[i][k] = dp[i-1][k];
                }
                else {
                    dp[i][k] = (dp[i-1][k-1] * probabilityForIntervalOfRunner(p1, p2, runnerIntervalLength(i))) + (dp[i-1][k] * probabilityForIntervalOfRunner(p2, t[i].ss, runnerIntervalLength(i))) ; 
                }
            }
        }
        
        for (int i=0; i<peopleInInterval; i++) 
            result += (dp[runners][i] * probabilityForIntervalOfRunner(p1, p2, runnerIntervalLength(1)) * probabilityOfWinningInterval(i));
        
        if (!skipEvents())
            break;
    }
    
    printf("%.8Lf\n", result);
    
    return 0;
}
