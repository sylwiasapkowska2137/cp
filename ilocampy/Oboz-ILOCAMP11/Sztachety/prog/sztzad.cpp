#include <iostream>
#include <cassert>
#include <vector>

const int MAX_N = 1e6;
const int MIN_N = 1;

const int MAX_K = 1e6;
const int MIN_K = 1;

const int MAX_X = 1e6;
const int MIN_X = 1;

struct Node {
    int min;
    int max;
    int change;
    bool exist;
};

const int leaves = 1048576;  // 2^20
Node tree[leaves * 2 + 1];

std::vector<int> positions[MAX_N + 6];
std::vector<int>::const_iterator curPositionIt[MAX_N + 6];
int color[MAX_N + 6];

// after update tree[idx].change == 0
void updateNode(int idx);

void setNode(int position, int value);

int getPosition(int value);

void addToInterval(int start, int end, int val, int idx = 1, int curStart = 0,
                   int curEnd = leaves - 1);

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    assert(MIN_N <= n && n <= MAX_N);
    assert(MIN_K <= k && k <= MAX_K);

    int uniques = 0;
    for (int i = 0; i < n; i++) {
        int curColor;
        scanf("%d", &curColor);
        assert(MIN_X <= curColor && curColor <= MAX_X);

        if (positions[curColor].empty()) {
            uniques++;
        } else if (positions[curColor].size() == 1) {
            uniques--;
        }
        positions[curColor].push_back(i);
        curPositionIt[curColor] = positions[curColor].begin();

        setNode(i, uniques);
        color[i] = curColor;
    }

    int best = -1;
    for (int i = 0; i < n; i++) {
        int lastK = getPosition(k);
        if (lastK != -1) {
            best = std::max(best, lastK - i + 1);
        }

        int curColor = color[i];
        auto curIt = curPositionIt[curColor]++;
        auto nextIt = curIt + 1;
        auto nextNextIt = curIt + 2;

        if (nextIt == positions[curColor].end()) {
            addToInterval(*curIt, n - 1, -1);
        } else {
            // ??1????1????1??
            // 00-----+++++000
            addToInterval(*curIt, *nextIt - 1, -1);

            int end = n - 1;
            if (nextNextIt != positions[curColor].end()) {
                end = *nextNextIt - 1;
            }
            addToInterval(*nextIt, end, 1);
        }
    }

    printf("%d\n", best);
}

void setNode(int position, int value) {
    position += leaves;
    tree[position].min = tree[position].max = value;
    tree[position].change = 0;
    tree[position].exist = true;

    position >>= 1;
    while (position) {
        tree[position].exist = true;
        updateNode(position);
        position >>= 1;
    }
}

int getPosition(int value) {
    int idx = 1;

    updateNode(idx);
    if (value < tree[idx].min || tree[idx].max < value) {
        return -1;
    }

    while (idx < leaves) {
        int leftIdx = idx << 1;
        int rightIdx = (idx << 1) + 1;

        updateNode(rightIdx);
        Node &right = tree[rightIdx];
        if (right.exist && right.min <= value && value <= right.max) {
            idx = rightIdx;
            continue;
        }

        updateNode(leftIdx);
        idx = leftIdx;
    }

    return idx - leaves;
}

void addToInterval(int start, int end, int val, int idx, int curStart, int curEnd) {
    if (start == curStart && end == curEnd) {
        tree[idx].change += val;
        updateNode(idx);
        return;
    }

    updateNode(idx);

    int mid = (curStart + curEnd) >> 1;
    if (start <= mid) {
        addToInterval(start, std::min(end, mid), val, idx << 1, curStart, mid);
    }
    if (end > mid) {
        addToInterval(std::max(start, mid + 1), end, val, (idx << 1) + 1, mid + 1, curEnd);
    }

    updateNode(idx);
}

void updateNode(int idx) {
    Node &node = tree[idx];

    if (idx >= leaves) {
        node.min += node.change;
        node.max += node.change;
        node.change = 0;
        return;
    }

    Node &left = tree[idx << 1];
    Node &right = tree[(idx << 1) + 1];

    if (node.change) {
        left.change += node.change;
        right.change += node.change;
        node.change = 0;
    }

    node.min = left.min + left.change;
    node.max = left.max + left.change;

    if (right.exist) {
        node.min = std::min(node.min, right.min + right.change);
        node.max = std::max(node.max, right.max + right.change);
    }
}