class Solution {
public:
	string hash(string t)
	{
		sort(t.begin(), t.end());
		t.resize(unique(t.begin(), t.end()) - t.begin());
		return t;
	}
	string nextClosestTime(string time) {
		string result = time;
		string sorted{ hash(time) };
		int HH = (time[0] - '0') * 10 + (time[1] - '0');
		int MM = (time[3] - '0') * 10 + (time[4] - '0');
		while (true)
		{
			++MM;
			if (MM == 60)
				MM = 0, ++HH, HH %= 24;
			result[0] = HH / 10 + '0';
			result[1] = HH % 10 + '0';
			result[3] = MM / 10 + '0';
			result[4] = MM % 10 + '0';
			string sortedResult{ hash(result) };
			string rest;
			set_union(sorted.begin(), sorted.end(), sortedResult.begin(), sortedResult.end(), back_inserter(rest));
			if (rest == sorted)
				return result;
		}
	}
};