#include <bits/stdc++.h>
using namespace std;
//#define int long long // do not forget "LL"

class OddEvenTree {
public:
        int n, f;
        vector<vector<int>> G;
        vector<int> col, ans;
        void dfs(int v, int u, int c) {
                if(col[v]) {
                        if(col[v] != c) f = 1;
                        return;
                }
                col[v] = c;
                if(u >= 0) {
                        ans.push_back(u);
                        ans.push_back(v);
                }
                for(auto &e: G[v]) {
                        dfs(e, v, c^3);
                        if(f) return;
                }
        }
        vector <int> getTree( vector <string> x ) {
                n = x.size();
                f = 0;
                ans.clear();
                G.assign(n,vector<int>());
                col.assign(n,0);
                for (int i = 0; i < n; i++)
                        for (int j = 0; j < n; j++)
                                if(x[i][j] == 'O') G[i].push_back(j);

                dfs(0,-1,1);
                for (int i = 0; i < n; i++) {
                        if(!col[i]) return {-1};
                        for (int j = 0; j < n; j++) {
                                if(col[i] == col[j] and x[i][j] == 'O') return {-1};
                                if(col[i] != col[j] and x[i][j] == 'E') return {-1};
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
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) { 
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
			string x[]                = {"EOE",
 "OEO",
 "EOE"};
			int expected__[]          = {0, 1, 2, 1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = OddEvenTree().getTree(vector <string>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string x[]                = {"EO",
 "OE"};
			int expected__[]          = {0, 1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = OddEvenTree().getTree(vector <string>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string x[]                = {"OO",
 "OE"};
			int expected__[]          = {-1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = OddEvenTree().getTree(vector <string>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string x[]                = {"EO",
 "EE"};
			int expected__[]          = {-1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = OddEvenTree().getTree(vector <string>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			string x[]                = {"EOEO",
 "OEOE",
 "EOEO",
 "OEOE"};
			int expected__[]          = {0, 1, 0, 3, 2, 1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = OddEvenTree().getTree(vector <string>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string x[]                = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = OddEvenTree().getTree(vector <string>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string x[]                = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = OddEvenTree().getTree(vector <string>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			string x[]                = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = OddEvenTree().getTree(vector <string>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
