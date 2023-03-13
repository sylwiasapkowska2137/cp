#include <iostream>
#include <cstdio>
#include <cassert>

const int wordLen = 5;

char firstTime[10], secondTime[10];

int main() {
    scanf("%s", firstTime);
    scanf("%s", secondTime);

    assert(strlen(firstTime) == wordLen && strlen(secondTime) == wordLen);
    
    assert('0' <= firstTime[0] && firstTime[0] <= '2');
    assert('0' <= firstTime[1] && firstTime[1] <= '9');
    int firstHour = (firstTime[0] - '0') * 10 + (firstTime[1] - '0');

    assert('0' <= firstTime[3] && firstTime[3] <= '5');
    assert('0' <= firstTime[4] && firstTime[4] <= '9');
    int firstMinute = (firstTime[3] - '0') * 10 + (firstTime[4] - '0');

    assert('0' <= secondTime[0] && secondTime[0] <= '2');
    assert('0' <= secondTime[1] && secondTime[1] <= '9');
    int secondHour = (secondTime[0] - '0') * 10 + (secondTime[1] - '0');

    assert('0' <= secondTime[3] && secondTime[3] <= '5');
    assert('0' <= secondTime[4] && secondTime[4] <= '9');
    int secondMinute = (secondTime[3] - '0') * 10 + (secondTime[4] - '0');

    int minutesFirst = firstHour * 60 + firstMinute;
    int minutesSecond = secondHour * 60 + secondMinute;

    if (minutesFirst > minutesSecond) {
        // if on next day
        minutesSecond += 24 * 60;
    }

    printf("%d", minutesSecond - minutesFirst);
    return 0;
}