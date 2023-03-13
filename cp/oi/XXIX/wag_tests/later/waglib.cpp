#include <bits/stdc++.h>
using namespace std;
namespace {
	bool _initialized = false;
	int current_test = 0;
	bool out = false;
	bool relative_order = false;
	uint64_t state = 0;
	int max_queries = 0;
	vector <int> where(7);
	vector <vector <int> > schedule;
	vector <pair <vector <int>, int> > query_history;
	vector <int> history[7];
	vector <int> relabel;
	struct record {
		vector <pair <vector <int>, int> > query_history;
		vector <int> ans;
	};
	vector <record> run_log;
	void acc() {
		printf("OK %d\n", (int) run_log.size());
		for (auto [h, a] : run_log) {
			printf("%d\n", (int) h.size());
			for (auto [q, r] : h) {
				for (int i = 0; i < 7; ++i) printf("%d ", q[i]);
				printf("%d\n", r);
			}
			for (int i = 0; i < 7; ++i) printf("%s%d", " " + !i, a[i]);
			printf("\n");
		}
		out = true;
		exit(0);
	}
	void err(const char *message) {
		printf("FAIL\n%s\n", message);
		out = true;
		exit(0);
	}
	int sign(int x) {
		if (x > 0) return 1;
		if (x == 0) return 0;
		return -1;
	}
	uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	uint64_t my_rand() {
		state = splitmix64(state);
		return state;
	}
	template <class c> void my_random_shuffle(c b, c e) {
		int n = e - b;
		for (int i = 1; i < n; ++i) {
			int j = my_rand() % (i + 1);
			if (i != j) swap(b[i], b[j]);
		}
	}
	void init_full_schedule() {
		vector <int> per(7);
		iota(per.begin(), per.end(), 1);
		do {
			schedule.push_back(per);
		}
		while (next_permutation(per.begin(), per.end()));
		my_random_shuffle(schedule.begin(), schedule.end());
	}
	void init_random_schedule() {
		for (int i = 0; i < 5040; ++i) {
			schedule.emplace_back(7);
			iota(schedule.back().begin(), schedule.back().end(), 1);
			my_random_shuffle(schedule.back().begin(), schedule.back().end());
		}
	}
	void fix_order() {
		for (int i = 0; i < 7; ++i) history[i].push_back(i);
	}
	void init_testcase(int test_id) {
		fill(where.begin(), where.end(), 0);
		assert(test_id < (int)schedule.size());
		query_history.clear();
		for (int i = 0; i < 7; ++i) history[i].clear();
		relabel.resize(7);
		iota(relabel.begin(), relabel.end(), 0);
		if (!relative_order) fix_order();
	}
	void init() {
		if(_initialized)
			return;
		static char word_tab[100];
		scanf("%s", word_tab);
		string word = word_tab;
		if (word == "sample") { //Sample test
			schedule = {{1, 2, 3, 4, 5, 6, 7}, {2, 1, 3, 7, 4, 5, 6}};
			relative_order = false;
		}
		else if (word == "1a") {
			state = 0xe37d2e2c295b7dc0;
			relative_order = false;
			init_random_schedule();
		}
		else if (word == "1b") {
			state = 0x798f65ec2e3d3293;
			relative_order = false;
			init_full_schedule();
		}
		else if (word == "1c") {
			state = 0x43c1452e08621642;
			relative_order = true;
			init_random_schedule();
		}
		else if (word == "1d") {
			state = 0xe695f00c7aedabee;
			relative_order = true;
			init_full_schedule();
		}
		else if (word == "1e") {
			state = 0x5d2bc59e0eb10c90;
			relative_order = true;
			init_full_schedule();
		}
		else if (word == "1f") {
			state = 0xe44e84c144486978;
			relative_order = true;
			init_full_schedule();
		}
		else {
			err("Program czyta ze standardowego wejścia");
		}
		init_testcase(0);
		_initialized = true;
	}
	void at_end() {
		if (!out) {
			if (current_test != (int)schedule.size()) {
				err("Program zakończył się bez wywołania funkcji odpowiedz t razy");
			}
		}
	}
	void update_sort() {
		sort(relabel.begin(), relabel.end(), [](int i, int j){return history[i] < history[j];});
	}
	void touch(const vector <int> &x) {
		int is[7] = {};
		for (int c : x) is[c] = 1;
		for (int i = 0; i < 7; ++i) history[i].push_back(is[i]);
		update_sort();
	}
	int _ = (atexit(at_end), 0);
}
void poloz_lewo(int x) {
	init();
	if (current_test == (int) schedule.size()) err("Wywołanie funkcji poloz_lewo po rozwiązaniu ostatniego przypadku testowego");
	if (x < 1 || x > 7) err("Wywołanie funkcji poloz_lewo z parametrem spoza przedziału [1, 7]");
	where[x - 1] = -1;
}
void poloz_prawo(int x) {
	init();
	if (current_test == (int) schedule.size()) err("Wywołanie funkcji poloz_prawo po rozwiązaniu ostatniego przypadku testowego");
	if (x < 1 || x > 7) err("Wywołanie funkcji poloz_prawo z parametrem spoza przedziału [1, 7]");
	where[x - 1] = 1;
}
void odloz(int x) {
	init();
	if (current_test == (int) schedule.size()) err("Wywołanie funkcji odloz po rozwiązaniu ostatniego przypadku testowego");
	if (x < 1 || x > 7) err("Wywołanie funkcji odloz z parametrem spoza przedziału [1, 7]");
	where[x - 1] = 0;
}
int wazenie() {
	init();
	if (current_test == (int) schedule.size()) err("Wywołanie funkcji wazenie po rozwiązaniu ostatniego przypadku testowego");
	if (query_history.size() >= 25) err("Przekroczenie limitu na liczbę wywołań funkcji wazenie");
	vector <int> l, r;
	for (int i = 0; i < 7; ++i) {
		if (where[i] == -1) l.push_back(i);
		else if (where[i] == 1) r.push_back(i);
	}
	if (l.size() > r.size() || (l.size() == r.size() && (my_rand() & 1))) {
		touch(l);
		touch(r);
	}
	else {
		touch(r);
		touch(l);
	}
	int balance = 0;
	for (int i = 0; i < 7; ++i) balance += schedule[current_test][i] * where[relabel[i]];
	query_history.emplace_back(where, sign(balance));
	return sign(balance);
}
void odpowiedz(vector<int> ans) {
	init();
	if (current_test == (int) schedule.size()) err("Wywołanie funkcji odpowiedz po rozwiązaniu ostatniego przypadku testowego");
	if ((int)ans.size() != 7) err("Wywołanie funkcji odpowiedź z listą długości innej niż 7");
	int seen[8] = {};
	for (int i = 0; i < 7; ++i) {
		int x = ans[i];
		if (x < 1 || x > 7) err("Wywołanie funkcji odpowiedz z parametrem spoza przedziału [1, 7]");
		if (seen[x]) err("Wywołanie funkcji odpowiedz z dwoma odważnikami o tej samej masie");
		seen[x] = true;
	}
	run_log.push_back({move(query_history), ans});
	current_test++;
	max_queries = max<int>(max_queries, query_history.size());
	if (current_test < (int) schedule.size()) init_testcase(current_test);
	else acc();
}
int liczba_testow() {
	init();
	return schedule.size();
}
