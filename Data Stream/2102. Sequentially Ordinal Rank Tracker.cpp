#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
class SORTracker {
public:
	SORTracker() {
		K = 0;
	}

	void add(string name, int score) {
		S.insert({ -score, name });
	}

	string get() {
		string result = S.find_by_order(K)->second;		
        ++K;
        return result;
	}
	int K, N;
	ordered_set<pair<int, string>> S;
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */