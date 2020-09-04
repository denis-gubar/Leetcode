class Solution {
public:
	Solution(vector<vector<int>>& rects) : gen(rd()), rects(rects) {
		buckets.push_back(0);
		for (int i = 0; i < rects.size(); ++i)
			buckets.push_back(buckets.back() +
				(1LL + rects[i][2] - rects[i][0]) * (1LL + rects[i][3] - rects[i][1]));
		totalWeight = buckets.back();
		distribution = uniform_int_distribution<>(0, totalWeight - 1);
	}

	vector<int> pick() {
		int x = distribution(gen);
		int pos = upper_bound(buckets.begin(), buckets.end(), x) - buckets.begin() - 1;
		long long delta = x - buckets[pos];
		long long width = 1LL + rects[pos][2] - rects[pos][0];
		return { static_cast<int>(rects[pos][0] + delta % width),static_cast<int>(rects[pos][1] + delta / width) };
	}
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen; //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> distribution;
	vector<long long> buckets;
	vector<vector<int>> rects;
	long long totalWeight;
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */