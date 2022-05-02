class Solution {
public:
	int totalFruit(vector<int>& tree) {
		int result = 0;
		int a = 0, b = 0, distinctCount = 0;
		unordered_map<int, int> count;
		while (b < tree.size())
		{
			if (++count[tree[b]] == 1)
				++distinctCount;
			while (distinctCount > 2)
			{
				if (--count[tree[a]] == 0)
					--distinctCount;
				++a;
			}
			++b;
			result = max(result, b - a);
		}
		return result;
	}
};