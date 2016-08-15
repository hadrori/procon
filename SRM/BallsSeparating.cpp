#include <bits/stdc++.h>
using namespace std;
//#define int long long // do not forget "LL"

class BallsSeparating {
public:
    int minOperations( vector <int> red, vector <int> green, vector <int> blue ) {
        
    }
};
//#undef int

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int red[]                 = {1, 1, 1};
			int green[]               = {1, 1, 1};
			int blue[]                = {1, 1, 1};
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int red[]                 = {5};
			int green[]               = {6};
			int blue[]                = {8};
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int red[]                 = {4, 6, 5, 7};
			int green[]               = {7, 4, 6, 3};
			int blue[]                = {6, 5, 3, 8};
			int expected__            = 37;

			std::clock_t start__      = std::clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int red[]                 = {7, 12, 9, 9, 7};
			int green[]               = {7, 10, 8, 8, 9};
			int blue[]                = {8, 9, 5, 6, 13};
			int expected__            = 77;

			std::clock_t start__      = std::clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int red[]                 = {842398, 491273, 958925, 849859, 771363, 67803, 184892, 391907, 256150, 75799};
			int green[]               = {268944, 342402, 894352, 228640, 903885, 908656, 414271, 292588, 852057, 889141};
			int blue[]                = {662939, 340220, 600081, 390298, 376707, 372199, 435097, 40266, 145590, 505103};
			int expected__            = 7230607;

			std::clock_t start__      = std::clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int red[]                 = ;
			int green[]               = ;
			int blue[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int red[]                 = ;
			int green[]               = ;
			int blue[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int red[]                 = ;
			int green[]               = ;
			int blue[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
