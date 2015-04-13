#include <string>
#include <vector>
using namespace std;

long long  map[52][101][101];

class ChessMetric {
public:
	long long howMany( int size, vector <int> start, vector <int> end, int numMoves ) {
		this->size = size;
		map[0][start[0]][start[1]] = 1;

		for(int mv = 1; mv <= numMoves; ++mv) {
			for(int i = 0; i < size; ++i) {
				for(int j = 0; j < size; ++j) {
					map[mv][i][j] = neigh_sum(mv-1,i,j);
				}
			}
		}
		return map[numMoves][end[0]][end[1]];
	}
private:
	int size;
	const vector<pair<int,int>> ds = {{ 0, 1}, { 1, 0}, { 0,-1}, {-1, 0},
									  { 1, 1}, {-1, 1}, { 1,-1}, {-1,-1}, 
									  { 1, 2}, { 2, 1}, {-1, 2}, {-2, 1},
									  { 1,-2}, { 2,-1}, {-1,-2}, {-2,-1}};
	long long neigh_sum(int mv, int i, int j) {
		long long total = 0;
		for(auto delta:ds) {
			int x = i + delta.first;
			int y = j + delta.second;
			if(inbound(x,y)) {
				total += map[mv][x][y];
			}
		}
		return total;
	}

	bool inbound(int i, int j) {
		return 0 <= i && i < size && 0 <= j && j < size;
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
			int size                  = 3;
			int start[]               = {0,0};
			int end[]                 = {1,0};
			int numMoves              = 1;
			long long expected__      = 1;

			std::clock_t start__      = std::clock();
			long long received__      = ChessMetric().howMany(size, vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(end, end + (sizeof end / sizeof end[0])), numMoves);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int size                  = 3;
			int start[]               = {0,0};
			int end[]                 = {1,2};
			int numMoves              = 1;
			long long expected__      = 1;

			std::clock_t start__      = std::clock();
			long long received__      = ChessMetric().howMany(size, vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(end, end + (sizeof end / sizeof end[0])), numMoves);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int size                  = 3;
			int start[]               = {0,0};
			int end[]                 = {2,2};
			int numMoves              = 1;
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = ChessMetric().howMany(size, vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(end, end + (sizeof end / sizeof end[0])), numMoves);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int size                  = 3;
			int start[]               = {0,0};
			int end[]                 = {0,0};
			int numMoves              = 2;
			long long expected__      = 5;

			std::clock_t start__      = std::clock();
			long long received__      = ChessMetric().howMany(size, vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(end, end + (sizeof end / sizeof end[0])), numMoves);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int size                  = 100;
			int start[]               = {0,0};
			int end[]                 = {0,99};
			int numMoves              = 50;
			long long expected__      = 243097320072600LL;

			std::clock_t start__      = std::clock();
			long long received__      = ChessMetric().howMany(size, vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(end, end + (sizeof end / sizeof end[0])), numMoves);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int size                  = ;
			int start[]               = ;
			int end[]                 = ;
			int numMoves              = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = ChessMetric().howMany(size, vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(end, end + (sizeof end / sizeof end[0])), numMoves);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int size                  = ;
			int start[]               = ;
			int end[]                 = ;
			int numMoves              = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = ChessMetric().howMany(size, vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(end, end + (sizeof end / sizeof end[0])), numMoves);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int size                  = ;
			int start[]               = ;
			int end[]                 = ;
			int numMoves              = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = ChessMetric().howMany(size, vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(end, end + (sizeof end / sizeof end[0])), numMoves);
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
