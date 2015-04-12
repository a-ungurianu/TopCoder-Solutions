#include <string> 
#include <vector>
#include <iostream>
using namespace std;

class BadNeighbors {
public:
	int maxDonations( vector <int> donations ) {
		vector<int> max_donation(donations);
		for(int i = 2; i < max_donation.size()-1; ++i) {
			for(int j = 0; j < i-1; ++j) {
				max_donation[i] = max(max_donation[i], max_donation[j] + donations[i]);
			}
		}
		int max_don = *(max_donation.end() - 2);

		for(int donation:max_donation) {
			cout << donation << ' ';
		}
		cout << '\n';


		max_donation = donations;
		for(int i = 3; i < max_donation.size(); ++i) {
			for(int j = 1; j < i-1; ++j) {
				max_donation[i] = max(max_donation[i], max_donation[j] + donations[i]);
			}
		}

		max_don = max(max_don,max_donation.back());

		for(int donation:max_donation) {
			cout << donation << ' ';
		}
		cout << '\n';

		
		return max_don;
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
			int donations[]           =  { 10, 3, 2, 5, 7, 8 };
			int expected__            = 19;

			std::clock_t start__      = std::clock();
			int received__            = BadNeighbors().maxDonations(vector <int>(donations, donations + (sizeof donations / sizeof donations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int donations[]           = { 11, 15 };
			int expected__            = 15;

			std::clock_t start__      = std::clock();
			int received__            = BadNeighbors().maxDonations(vector <int>(donations, donations + (sizeof donations / sizeof donations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int donations[]           = { 7, 7, 7, 7, 7, 7, 7 };
			int expected__            = 21;

			std::clock_t start__      = std::clock();
			int received__            = BadNeighbors().maxDonations(vector <int>(donations, donations + (sizeof donations / sizeof donations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int donations[]           = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
			int expected__            = 16;

			std::clock_t start__      = std::clock();
			int received__            = BadNeighbors().maxDonations(vector <int>(donations, donations + (sizeof donations / sizeof donations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int donations[]           = { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61, 6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397, 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };
			int expected__            = 2926;

			std::clock_t start__      = std::clock();
			int received__            = BadNeighbors().maxDonations(vector <int>(donations, donations + (sizeof donations / sizeof donations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int donations[]           = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BadNeighbors().maxDonations(vector <int>(donations, donations + (sizeof donations / sizeof donations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int donations[]           = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BadNeighbors().maxDonations(vector <int>(donations, donations + (sizeof donations / sizeof donations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int donations[]           = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BadNeighbors().maxDonations(vector <int>(donations, donations + (sizeof donations / sizeof donations[0])));
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
