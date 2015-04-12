#include <string>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

class AvoidRoads {
	struct Corner {
		int ln,col;
		bool operator<(const Corner &oth) const {
			if(this->ln == oth.ln) return this->col < oth.col;
			return this->ln < oth.ln;
		}
	};

public:
	long long numWays( int width, int height, vector <string> bad ) {
		vector<vector<long long>> no_roads(height+1,vector<long long>(width+1,0));

		set<pair<Corner,Corner>> bad_roads;

		for(string b:bad) {
			stringstream inp(b);
			Corner c1,c2;
			inp >> c1.ln >> c1.col >> c2.ln >> c2.col;
			if(c1 < c2) {
				bad_roads.insert({c1,c2});
			}
			else {
				bad_roads.insert({c2,c1});
			}
		}

		for(int i = 0; i < no_roads.size(); ++i) {
			if(bad_roads.find({{i-1,0},{i,0}}) != bad_roads.end()) break;
			no_roads[i][0] = 1;
		}
		for(int j = 0; j < no_roads[0].size(); ++j) {
			if(bad_roads.find({{0,j-1},{0,j}}) != bad_roads.end()) break;	
			no_roads[0][j] = 1;
		}

		for(int i = 1; i < no_roads.size(); ++i) {
			for(int j = 1; j < no_roads[i].size(); ++j) {
				if(bad_roads.find({{i-1,j},{i,j}}) == bad_roads.end()) {
					no_roads[i][j] += no_roads[i-1][j];
				}

				if(bad_roads.find({{i,j-1},{i,j}}) == bad_roads.end()) {
					no_roads[i][j] += no_roads[i][j-1];
				}
			}
		}
		return no_roads[height][width];
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
			int width                 = 6;
			int height                = 6;
			string bad[]              = {"0 0 0 1","6 6 5 6"};
			long long expected__      = 252;

			std::clock_t start__      = std::clock();
			long long received__      = AvoidRoads().numWays(width, height, vector <string>(bad, bad + (sizeof bad / sizeof bad[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int width                 = 1;
			int height                = 1;
			string bad[]              = {};
			long long expected__      = 2;

			std::clock_t start__      = std::clock();
			long long received__      = AvoidRoads().numWays(width, height, vector <string>(bad, bad + (sizeof bad / sizeof bad[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int width                 = 35;
			int height                = 31;
			string bad[]              = {};
			long long expected__      = 6406484391866534976LL;

			std::clock_t start__      = std::clock();
			long long received__      = AvoidRoads().numWays(width, height, vector <string>(bad, bad + (sizeof bad / sizeof bad[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int width                 = 2;
			int height                = 2;
			string bad[]              = {"0 0 1 0", "1 2 2 2", "1 1 2 1"};
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = AvoidRoads().numWays(width, height, vector <string>(bad, bad + (sizeof bad / sizeof bad[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int width                 = ;
			int height                = ;
			string bad[]              = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = AvoidRoads().numWays(width, height, vector <string>(bad, bad + (sizeof bad / sizeof bad[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int width                 = ;
			int height                = ;
			string bad[]              = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = AvoidRoads().numWays(width, height, vector <string>(bad, bad + (sizeof bad / sizeof bad[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int width                 = ;
			int height                = ;
			string bad[]              = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = AvoidRoads().numWays(width, height, vector <string>(bad, bad + (sizeof bad / sizeof bad[0])));
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
