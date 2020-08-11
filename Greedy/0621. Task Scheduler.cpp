class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		int N = tasks.size();
		vector<int>	count(26);
		for (char c : tasks)
			++count[c - 'A'];
		int max_frequency = *max_element(count.begin(), count.end());
		int max_count = 0;
		for (int x : count)
			max_count += x == max_frequency;
		int result = max(N, (max_frequency - 1) * (n + 1) + max_count);
		return result;
	}
};