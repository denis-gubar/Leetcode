/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
	int findInMountainArray(int target, MountainArray& mountainArr) {
        vector<int> results;
		int N = mountainArr.length();
		int a = 0, d = N - 1;
		int A = mountainArr.get(a);
		if (A == target)
			return a;
		int D = mountainArr.get(d);
		if (D == target)
			results.push_back(d);
		vector<vector<int>> check;
		while (d - a > 1)
		{
			int delta = max(1, (d - a) / 3);
			int b = a + delta;
			int c = d - delta;
			int B = mountainArr.get(b);
			if (B == target)
				results.push_back(b);
			int C = mountainArr.get(c);
			if (C == target)
				results.push_back(c);
			if (A < B && B <= C)
			{
				if (A <= target && target <= B)
					check.push_back({ a, A, b, B });
				a = b;
                A = B;
			}
			if (B >= C && C > D)
			{
				if (D <= target && target <= C)
					check.push_back({ d, D, c, C });
				d = c;
                D = C;
			}
		}
		for (vector<int> const& x : check)
		{
			int a = x[0], A = x[1], b = x[2], B = x[3];
            if (A == target)
                return a;
            if (B == target)
                return b;
			while (b - a > 1)
			{
				int m = (a + b) / 2;
				int M = mountainArr.get(m);
				if (M == target)
					return m;
				if (M < target)
					a = m;
				else
					b = m;
			}
		}
        if (!results.empty())
            return results[0];
		return -1;
	}
};