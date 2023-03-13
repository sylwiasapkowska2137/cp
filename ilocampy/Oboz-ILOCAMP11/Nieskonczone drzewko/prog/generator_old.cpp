#include <cstdio>
#include <vector>
#include <iostream>
#include <assert.h>
#include <algorithm>
#include <cstdlib>
#include <functional>

class TestManager {
public:
	TestManager(std::string taskID) : binName("./" + taskID + "zad"), testFilePath("../test/" + taskID) {}
	
	// 1 vector of ints = 1 line of ints separated by spaces
	void addTest(std::string testID, const std::vector<std::vector<int>> &input) {
		ins.push_back(testFilePath + testID + ".in");
		outs.push_back(testFilePath + testID + ".out");
		
		FILE *file = fopen(ins.back().c_str(), "w");
		assert(file && "unable to open file");
		
		for (int line = 0; line < input.size(); line++) {
			if (line) {
				fprintf(file, "\n");
			}
			for (int col = 0; col < input[line].size(); col++) {
				if (col) {
					fprintf(file, " ");
				}
				fprintf(file, "%d", input[line][col]);
			}
		}
		
		fclose(file);
		
		printf("%-10s %25s\n", "created:", ins.back().c_str());
	}
	
	void generateOut(bool log = false) const {
		for (int i = 0; i < ins.size(); ++i) {
			system((binName + " < " + ins[i] + " > " + outs[i]).c_str());
			
			if (log) {
				system(("echo " + outs[i] + ": && cat " + outs[i] + " && echo \"\"").c_str());
			} else {
				printf("%-10s %26s\n", "generated:", outs[i].c_str());
			}
		}
	}
	
private:
	const std::string binName;
	const std::string testFilePath;
	std::vector<const std::string> ins;
	std::vector<const std::string> outs;
};

int main(int argc, char *argv[]) {
	srand(234);
	TestManager testManager("nie");
	int n;
	
	testManager.addTest("1a", {
		{4, 9}
	});
	testManager.addTest("1b", {
		{15, 15}
	});
	
	testManager.addTest("2a", {
		{15, 35}
	});
	testManager.addTest("2b", {
		{17, 31}
	});
	
    n = 100;
	testManager.addTest("3a", {
		{rand()%n, rand()%n}
	});
	testManager.addTest("3b", {
		{60, 91}
	});
	
	n = 1000;
	testManager.addTest("4a", {
		{rand()%n, rand()%n}
	});
	testManager.addTest("4b", {
		{651, 991}
	});
	
	n = 1000;
	testManager.addTest("5a", {
		{rand()%n, rand()%n}
	});
	testManager.addTest("5b", {
		{891, 513}
	});
	
	n = 10 * 1000;
	testManager.addTest("6a", {
		{rand()%n, rand()%n}
	});
	testManager.addTest("6b", {
		{9000, 5500}
	});
	
	n = 1000 * 1000;
	testManager.addTest("7a", {
		{rand()%n, rand()%n}
	});
	testManager.addTest("7b", {
		{7400, 94000}
	});

	n = 1000 * 1000 * 1000;
	testManager.addTest("8a", {
		{rand()%n, rand()%n}
	});
    testManager.addTest("8b", {
		{rand()%n, rand()%n}
	});
	
	n = 1000 * 1000 * 1000;
	testManager.addTest("9a", {
		{rand()%n, rand()%n}
	});
    testManager.addTest("9b", {
		{rand()%n, rand()%n}
	});
	
	n = 1000 * 1000 * 1000;
	testManager.addTest("10a", {
		{rand()%n, rand()%n}
	});
    testManager.addTest("10b", {
		{rand()%n, rand()%n}
	});
	
	testManager.generateOut(argc > 1 && atoi(argv[1]));
}