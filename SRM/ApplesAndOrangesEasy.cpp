#include <bits/stdc++.h>
using namespace std;
//#define int long long // do not forget "LL"

class ApplesAndOrangesEasy {
public:
        int maximumApples( int n, int k, vector <int> info ) {
                int m = k/2;
                vector<int> f(n,0), g(n,0);
                for(auto &e: info) {
                        for (int i = e-1; i < min(n,e-1+k); i++) f[i]++;
                        g[e-1] = 1;
                }

                int ans = info.size();
                for (int i = 0; i < n; i++) {
                        if(g[i]) continue;
                        int mx = 0;
                        for (int j = i; j < min(n,i+k); j++) mx = max(mx, f[j]);
                        if(mx < m) {
                                ans++;
                                for (int j = i; j < min(n,i+k); j++) f[j]++;
                        }
                }
                return ans;
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
			int N                     = 3;
			int K                     = 2;
			int info[]                = {};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = ApplesAndOrangesEasy().maximumApples(N, K, vector <int>(info, info + (sizeof info / sizeof info[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 10;
			int K                     = 3;
			int info[]                = {3, 8};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = ApplesAndOrangesEasy().maximumApples(N, K, vector <int>(info, info + (sizeof info / sizeof info[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 9;
			int K                     = 4;
			int info[]                = {1, 4};
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = ApplesAndOrangesEasy().maximumApples(N, K, vector <int>(info, info + (sizeof info / sizeof info[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 9;
			int K                     = 4;
			int info[]                = {2, 4};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = ApplesAndOrangesEasy().maximumApples(N, K, vector <int>(info, info + (sizeof info / sizeof info[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 23;
			int K                     = 7;
			int info[]                = {3, 2, 9, 1, 15, 23, 20, 19};
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = ApplesAndOrangesEasy().maximumApples(N, K, vector <int>(info, info + (sizeof info / sizeof info[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

                case 5: {
			int N                     = 5;
			int K                     = 4;
			int info[]                = {1,5};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = ApplesAndOrangesEasy().maximumApples(N, K, vector <int>(info, info + (sizeof info / sizeof info[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int N                     = ;
			int K                     = ;
			int info[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ApplesAndOrangesEasy().maximumApples(N, K, vector <int>(info, info + (sizeof info / sizeof info[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int K                     = ;
			int info[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ApplesAndOrangesEasy().maximumApples(N, K, vector <int>(info, info + (sizeof info / sizeof info[0])));
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
