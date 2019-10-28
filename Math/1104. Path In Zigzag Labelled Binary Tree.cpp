class Solution {
public:
	vector<int> pathInZigZagTree(int label) {
		vector<int> result;
		vector<int> parents(label * 4 + 2);
		int level = 1, count = 2, total = 1;
		while (total < label)
		{
            for (int parent = total, x = 1; x < count; x += 2, --parent)
            {
                parents[total + x] = parent;
                parents[total + x + 1] = parent;
            }
			total += count;
			++level; count <<= 1;
		}
		while (label)
		{
			result.push_back(label);
			label = parents[label];
		}
		reverse(result.begin(), result.end());
		return result;
	}
};