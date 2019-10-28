class Solution {
public:
	int maxArea( vector<int>& height ) {		
		int result = 0;
		int n = height.size();
		for(int i = 0; i < n - 1; ++i )
			for (int j = n - 1; j > i; --j)
			{
				if (height[i] * (j - i) < result)
					break;
				int current = min( height[i], height[j] )  * (j - i);
				if (result < current)
					result = current;
			}
		return result;
	}
};