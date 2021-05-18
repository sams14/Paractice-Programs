// You're spending your afternoon at a local school, teaching kids how to code. You give them a
// simple task: find the difference between the maximum and minimum values in an array of integers.

// After a few hours, they came up with some promising source code. Unfortunately, it doesn't 
// compile! Since you don't want to discourage them, you decide to make their code work without 
// modifying it by adding preprocessor macros.

// Review the locked stub code in your editor and add the preprocessor macros necessary to make 
// the code work.


//#################################################################################

#define INF (unsigned)!((int)0)
#define FUNCTION(name,operator) inline void name(int &current, int candidate) {!(current operator candidate) ? current = candidate : false;}
#define io(v) cin>>v
#define toStr(a) #a
#define foreach(v, i) for (int i = 0; i < v.size(); ++i)

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}