class Solution {
public:
	Solution(vector<int>& w) {
		buckets.push_back(0);
		partial_sum(w.begin(), w.end(), back_inserter(buckets));
		totalWeight = buckets.back();
		distribution = uniform_int_distribution<>(0, totalWeight - 1);
	}

	int pickIndex() {
		return upper_bound(buckets.begin(), buckets.end(), distribution(gen)) - buckets.begin() - 1;
	}
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen; //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> distribution;
	vector<int> buckets;
	int totalWeight;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */