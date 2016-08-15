#include <bits/stdc++.h>
using namespace std;

class ProblemSets {
public:
        long long e, em, m, mh, h;

        bool ok(long long x) {
                long long a = e, b = m, c = h, p = em, q = mh;
                if(a < x) {
                        long long tmp = min(x-a, p);
                        a += tmp;
                        p -= tmp;
                }
                if(a < x) return 0;
                b += p;
                if(b < x) {
                        long long tmp = min(x-b, q);
                        b += tmp;
                        q -= tmp;
                }
                if(b < x) return 0;
                c += q;
                return c >= x;
        }
        
        long long maxSets( long long E, long long EM, long long M, long long MH, long long H ) {
                cerr << 0x3f3f3f3f3f3f3f3fLL << endl;
                e = E;
                em = EM;
                m = M;
                mh = MH;
                h = H;
                long long lb = 0, ub = 2000000000000000000LL, mid;
                while(ub-lb > 1) {
                        mid = (lb+ub)/2;
                        if(ok(mid)) lb = mid;
                        else ub = mid;
                }
                return lb;
        }
};

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
	
	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) { 
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
			long long E               = 2;
			long long EM              = 2;
			long long M               = 1;
			long long MH              = 2;
			long long H               = 2;
			long long expected__      = 3;

			std::clock_t start__      = std::clock();
			long long received__      = ProblemSets().maxSets(E, EM, M, MH, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long E               = 100;
			long long EM              = 100;
			long long M               = 100;
			long long MH              = 0;
			long long H               = 0;
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = ProblemSets().maxSets(E, EM, M, MH, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long E               = 657;
			long long EM              = 657;
			long long M               = 657;
			long long MH              = 657;
			long long H               = 657;
			long long expected__      = 1095;

			std::clock_t start__      = std::clock();
			long long received__      = ProblemSets().maxSets(E, EM, M, MH, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long E               = 1;
			long long EM              = 2;
			long long M               = 3;
			long long MH              = 4;
			long long H               = 5;
			long long expected__      = 3;

			std::clock_t start__      = std::clock();
			long long received__      = ProblemSets().maxSets(E, EM, M, MH, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long E               = 1000000000000000000LL;
			long long EM              = 1000000000000000000LL;
			long long M               = 1000000000000000000LL;
			long long MH              = 1000000000000000000LL;
			long long H               = 1000000000000000000LL;
			long long expected__      = 1666666666666666666LL;

			std::clock_t start__      = std::clock();
			long long received__      = ProblemSets().maxSets(E, EM, M, MH, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			long long E               = ;
			long long EM              = ;
			long long M               = ;
			long long MH              = ;
			long long H               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = ProblemSets().maxSets(E, EM, M, MH, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long E               = ;
			long long EM              = ;
			long long M               = ;
			long long MH              = ;
			long long H               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = ProblemSets().maxSets(E, EM, M, MH, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long E               = ;
			long long EM              = ;
			long long M               = ;
			long long MH              = ;
			long long H               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = ProblemSets().maxSets(E, EM, M, MH, H);
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
