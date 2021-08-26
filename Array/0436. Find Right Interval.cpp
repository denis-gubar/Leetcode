class Solution {
public:
	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		int N = intervals.size();
		vector<int>	result(N, -1);
		set<pair<int, int>> pairs;
        for (int i = 0; i < N; ++i)
            pairs.insert({ intervals[i][0], i });
		for (int i = 0; i < N; ++i)
		{
			auto it = pairs.lower_bound({ intervals[i][1], 0 });
			if (it != pairs.end()) 
				result[i] = it->second;			
		}
		return result;
	}
};