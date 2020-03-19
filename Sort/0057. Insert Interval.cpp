class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {		
		int A = newInterval[0];
		int B = newInterval[1];
		auto start_it = lower_bound(intervals.begin(), intervals.end(), vector<int>{ A, A });
        if (start_it != intervals.begin())
            --start_it;
		auto end_it = lower_bound(intervals.begin(), intervals.end(), vector<int>{B + 1, B + 1});
		vector<vector<int>> result(intervals.begin(), start_it);
		for (auto it = start_it; it != end_it; ++it)
		{
			if (A <= (*it)[1])
				A = min(A, (*it)[0]);
			if (B < (*it)[1])
				B = (*it)[1];
            if (A > (*it)[1])
                result.push_back(*it);
		}
		result.push_back({ A, B });
		copy(end_it, intervals.end(), back_inserter(result));
		return result;
	}
};