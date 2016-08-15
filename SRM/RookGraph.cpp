#include <bits/stdc++.h>
using namespace std;
//#define int long long // do not forget "LL"

class RookGraph {
public:
        int countPlacements( int N, vector <string> graph ) {
                
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
			int N                     = 8;
			string graph[]            = {"11",
 "11"};
			int expected__            = 896;

			std::clock_t start__      = std::clock();
			int received__            = RookGraph().countPlacements(N, vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 8;
			string graph[]            = {"111",
 "110",
 "101"};
			int expected__            = 6272;

			std::clock_t start__      = std::clock();
			int received__            = RookGraph().countPlacements(N, vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 2;
			string graph[]            = {"11111",
 "11111",
 "11111",
 "11111",
 "11111"};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = RookGraph().countPlacements(N, vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 10;
			string graph[]            = {"1010000100",
 "0100101000",
 "1011010100",
 "0011010000",
 "0100100000",
 "0011010010",
 "0100001001",
 "1010000110",
 "0000010110",
 "0000001001"};
			int expected__            = 289151874;

			std::clock_t start__      = std::clock();
			int received__            = RookGraph().countPlacements(N, vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 50;
			string graph[]            = {"10111110000",
 "01011010000",
 "10100010011",
 "11010110001",
 "11001100101",
 "10011100110",
 "11110011111",
 "00000011100",
 "00001111100",
 "00100110010",
 "00111010001"};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = RookGraph().countPlacements(N, vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int N                     = 31;
			string graph[]            = {"10000000000000000000000000000000000000000000000000",
 "01000000000000000000000000000000000010000000010000",
 "00100000000010000000000100001100000000010010000000",
 "00010000000010000000001000000000000000000000000000",
 "00001000000000000000000000000000000000100000000000",
 "00000100101000000010000000000000000000100100000001",
 "00000010000000000100000001000000000000000000000001",
 "00000001000000001000000000000000000000000000000100",
 "00000100101000000000000000000000000000000000000001",
 "00000000010000000000000010000010000000000000100000",
 "00000100101000000000000000000010000000000000000001",
 "00000000000100000010000100001000000001001000100000",
 "00110000000010000000001000001000000000000010000000",
 "00000000000001000000000000000000000000000000000000",
 "00000000000000100000000000000000001010000000000010",
 "00000000000000010000000000100000000000000000000000",
 "00000001000000001000000000000000000000010000000000",
 "00000010000000000100000001000000010000000000000000",
 "00000100000100000010000000001000000001101100000000",
 "00000000000000000001000000000001000000000000001100",
 "00000000000000000000110000000000100000000000000010",
 "00000000000000000000110010000000100000000010000000",
 "00010000000010000000001000000001000000000001000000",
 "00100000000100000000000100000100000000010000100000",
 "00000000010000000000010011000000000000000010000000",
 "00000010000000000100000011000000000000000000000000",
 "00000000000000010000000000100000001000001000000000",
 "00000000000000000000000000010000010100000000000000",
 "00100000000110000010000000001000000001001010000000",
 "00100000000000000000000100000100000000010000000000",
 "00000000011000000000000000000010000000000000100000",
 "00000000000000000001001000000001000000000001001100",
 "00000000000000000000110000000000100100000000000000",
 "00000000000000000100000000010000010000000000000000",
 "00000000000000100000000000100000001000001000000000",
 "00000000000000000000000000010000100100000000000000",
 "01000000000000100000000000000000000010000000010010",
 "00000000000100000010000000001000000001001000000000",
 "00001100000000000010000000000000000000100100000000",
 "00100000000000001000000100000100000000010000000000",
 "00000000000100000010000000101000001001001000000000",
 "00000100000000000010000000000000000000100100000000",
 "00100000000010000000010010001000000000000010000000",
 "00000000000000000000001000000001000000000001000000",
 "00000000010100000000000100000010000000000000100000",
 "01000000000000000000000000000000000010000000010000",
 "00000000000000000001000000000001000000000000001100",
 "00000001000000000001000000000001000000000000001100",
 "00000000000000100000100000000000000010000000000010",
 "00000110101000000000000000000000000000000000000001"};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = RookGraph().countPlacements(N, vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int N                     = ;
			string graph[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RookGraph().countPlacements(N, vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			string graph[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RookGraph().countPlacements(N, vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int N                     = ;
			string graph[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RookGraph().countPlacements(N, vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
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
