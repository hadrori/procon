#include <bits/stdc++.h>
using namespace std;
//#define int long long // do not forget "LL"

class CampLunch {
public:
        int count( int N, int M, vector <string> a ) {
                
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
			int N                     = 2;
			int M                     = 2;
			string a[]                = {"AB","AB"};
			int expected__            = 7;

			std::clock_t start__      = std::clock();
			int received__            = CampLunch().count(N, M, vector <string>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 2;
			int M                     = 3;
			string a[]                = {"ABC","ABC"};
			int expected__            = 22;

			std::clock_t start__      = std::clock();
			int received__            = CampLunch().count(N, M, vector <string>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 2;
			int M                     = 3;
			string a[]                = {"ABC","BAC"};
			int expected__            = 21;

			std::clock_t start__      = std::clock();
			int received__            = CampLunch().count(N, M, vector <string>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 1;
			int M                     = 1;
			string a[]                = {"A"};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = CampLunch().count(N, M, vector <string>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 1;
			int M                     = 10;
			string a[]                = {"ABDEFHIGJC"};
			int expected__            = 89;

			std::clock_t start__      = std::clock();
			int received__            = CampLunch().count(N, M, vector <string>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int N                     = 16;
			int M                     = 16;
			string a[]                = {"ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP"};
			int expected__            = 950052677;

			std::clock_t start__      = std::clock();
			int received__            = CampLunch().count(N, M, vector <string>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int N                     = ;
			int M                     = ;
			string a[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CampLunch().count(N, M, vector <string>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int M                     = ;
			string a[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CampLunch().count(N, M, vector <string>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int N                     = ;
			int M                     = ;
			string a[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CampLunch().count(N, M, vector <string>(a, a + (sizeof a / sizeof a[0])));
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
