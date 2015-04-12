#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class ZigZag {
public:
	int longestZigZag( vector <int> sequence ) {
		if(sequence.size() <= 2) return sequence.size();
		vector<int> diffs(sequence.size()-1);
		for(int i = 0; i < diffs.size(); ++i) {
			if(sequence[i+1] - sequence[i] == 0) {
				diffs[i] = 0;
			}
			else {
				diffs[i] = copysign(1,sequence[i+1] - sequence[i]);
			}
		}

		for(int diff:diffs) {
			cout << diff << ' ';
		}
		cout << '\n';

		vector<int> zigzag(diffs.size(),1);
		for(int i = 1; i < diffs.size(); ++i) {
			if(diffs[i] == 0) {
				zigzag[i] = zigzag[i-1];
			}
			else {
				for(int j = 0; j < i; ++j) {
					
					if(diffs[j] == -diffs[i]) {
						zigzag[i] = max(zigzag[i],zigzag[j]+1);
					}
				}
			}
		}
		for(int zig:zigzag) {
			cout << zig << ' ';
		}
		cout << '\n';
		return zigzag.back() + 1; 
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
			int sequence[]            = { 1, 7, 4, 9, 2, 5 };
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = ZigZag().longestZigZag(vector <int>(sequence, sequence + (sizeof sequence / sizeof sequence[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int sequence[]            = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
			int expected__            = 7;

			std::clock_t start__      = std::clock();
			int received__            = ZigZag().longestZigZag(vector <int>(sequence, sequence + (sizeof sequence / sizeof sequence[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int sequence[]            = { 44 };
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = ZigZag().longestZigZag(vector <int>(sequence, sequence + (sizeof sequence / sizeof sequence[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int sequence[]            = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = ZigZag().longestZigZag(vector <int>(sequence, sequence + (sizeof sequence / sizeof sequence[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int sequence[]            = { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 };
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = ZigZag().longestZigZag(vector <int>(sequence, sequence + (sizeof sequence / sizeof sequence[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int sequence[]            = { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 249, 22, 176, 279, 23, 22, 617, 462, 459, 244 } ;
			int expected__            = 36;

			std::clock_t start__      = std::clock();
			int received__            = ZigZag().longestZigZag(vector <int>(sequence, sequence + (sizeof sequence / sizeof sequence[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int sequence[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ZigZag().longestZigZag(vector <int>(sequence, sequence + (sizeof sequence / sizeof sequence[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int sequence[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ZigZag().longestZigZag(vector <int>(sequence, sequence + (sizeof sequence / sizeof sequence[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int sequence[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ZigZag().longestZigZag(vector <int>(sequence, sequence + (sizeof sequence / sizeof sequence[0])));
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
