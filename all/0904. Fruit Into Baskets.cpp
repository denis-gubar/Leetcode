class Solution {
public:
	int totalFruit(vector<int>& tree) {
		int result = 0;
		int N = tree.size();
		int a = 0, b = 0;
		int typeA = -1, typeB = -1;
		while (b < N)
		{
			if (typeA != tree[b] && typeB != tree[b])
			{
				if (typeA == -1)
				{
					typeA = tree[b];
					result = max(result, b - a + 1);
				}
				else if (typeB == -1)
				{
					typeB = tree[b];
					result = max(result, b - a + 1);
				}
				else
				{
					result = max(result, b - a);
					while (a < N && tree[a] == typeA)
						++a;
					b = a;
					typeA = -1, typeB = -1;
					continue;
				}
			}
			else
				result = max(result, b - a + 1);
			++b;
		}
		return min(N, result);
	}
};
