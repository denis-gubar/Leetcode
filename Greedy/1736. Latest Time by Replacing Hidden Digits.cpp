class Solution {
public:
	string maximumTime(string time) {
		string result;
		for (int i = 0; i < 1440; ++i)
		{
			int hh = i / 60;
			int mm = i % 60;
			string current = to_string(100 + hh).substr(1) + ":" + to_string(100 + mm).substr(1);
			int difference_count = 0;
			for (int k = 0; k < time.size(); ++k)
				difference_count += time[k] != current[k] && time[k] != '?';
			if (difference_count == 0)
				result = current;
		}
		return result;
	}
};