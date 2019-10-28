class Solution {
public:
	vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
		reverse(arr1.begin(), arr1.end());
		reverse(arr2.begin(), arr2.end());
		vector<int> result(arr1);
		for (int i = 0; i < result.size() || i < arr2.size(); ++i)
		{			
			if (i < arr2.size())
			{
				if (result.size() == i)
					result.push_back(0);
				result[i] += arr2[i];
			}
			if (result[i] > 1)
			{
				int k = result[i] / 2;
				result[i] -= k * 2;
				if (result.size() == i + 1)
					result.push_back(0);
				if (result.size() == i + 2)
					result.push_back(0);
				result[i + 1] += k;
				result[i + 2] += k;
				if (result[i + 1] >= 4 && result[i + 2] >= 2)
					result[i + 1] -= 4, result[i + 2] -= 2;
				if (result[i + 1] >= 2 && result[i + 2] >= 1)
					result[i + 1] -= 2, result[i + 2] -= 1;
			}
		}
		reverse(result.begin(), result.end());
		if (result.size() > 1)
		{
			int k = 0;
			while (k < result.size() && !result[k])
				++k;
			result = vector<int>(result.begin() + k, result.end());
            if (result.empty())
                result = {0};
		}
		return result;
	}
};