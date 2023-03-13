#include <bits/stdc++.h>
using namespace std;
#include "oi.h"
void err(const char * = NULL, int = 0, int = 0) {
	printf("WRONG\nProgram pisze na standardowe wyjście\n");
	exit(0);
}
int sign(int x) {
	if (x > 0) return 1;
	if (x == 0) return 0;
	return -1;
}
int main(int argc, char **argv) {
	char _word[20];
	FILE *input = fopen(argv[1], "r");
	fscanf(input, "%s", _word);
	fclose(input);
	bool sample = strcmp(_word, "sample") == 0;
	FILE *out = fopen(argv[2], "r");
	oi::Scanner in(out, err, oi::PL);
	in.readString(_word, 16);
	string result = _word;
	if (result == "FAIL") {
		printf("WRONG\n");
		int c;
		while ((c = in.readChar()) != '\n') putchar(c);
		in.readEof();
	}
	else if (result == "OK") {
		in.readSpace();
		int t = in.readInt(0);
		in.readEoln();
		int r = 0;
		int x = 0;
		for (int _ = 0; _ < t; ++_) {
			int h = in.readInt(0, 25);
			in.readEoln();
			if (r == h) {
				x++;
			}
			else if (r < h) {
				r = h;
				x = 1;
			}
			vector <pair <vector <int>, int> > queries;
			for (int i = 0; i < h; ++i) {
				vector <int> w(7);
				for (int &x : w) {
					x = in.readInt(-1, 1);
					in.readSpace();
				}
				int r = in.readInt(-1, 1);
				in.readEoln();
				queries.emplace_back(w, r);
			}
			vector <int> ans(7);
			for (int i = 0; i < 7; ++i) {
				ans[i] = in.readInt(1, 7);
				if (i == 6) in.readEoln();
				else in.readSpace();
			}
			auto check = [&](const vector <int> &x) {
				for (auto [w, r] : queries) {
					int bal = 0;
					for (int i = 0; i < 7; ++i) bal += w[i] * x[i];
					if (r != sign(bal)) return false;
				}
				return true;
			};
			if (!check(ans)) {
				printf("WRONG\nBłędne przypisanie wag odważników\n");
				exit(0);
			}
			vector <int> ret(7);
			int found = 0;
			iota(ret.begin(), ret.end(), 1);
			do {
				if (check(ret)) {
					found++;
				}
			} while (next_permutation(ret.begin(), ret.end()));
			assert(found);
			if (found > 1 && !sample) {
				printf("WRONG\nBłędne przypisanie wag odważników\n");
				exit(0);
			}
		}
		in.readEof();
		int score = r <= 9 ? 100 : r <= 15 ? 40 + 10 * (15 - r) : r <= 25 ? 10 + 3 * (25 - r) : 0;
		printf("OK\nMaksymalnie %d zapyta%s. Maksymalna liczba osiągnięta w %d te%s\n%d\n", r, r == 1 ? "nie" : (r >= 2 && r <= 4) ? "nia" : "ń", x, x == 1 ? "ście" : "stach", score);
	}
	else err();
}
