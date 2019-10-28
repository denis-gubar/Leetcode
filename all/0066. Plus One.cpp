class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		reverse(digits.begin(), digits.end());
		int n = digits.size();		
        int i = 0;
		for (; i < n && digits[i] == 9; ++i)
			digits[i] = 0;
        if (i < n)
            ++digits[i];
        else
            digits.push_back(1);
		reverse(digits.begin(), digits.end());
        return digits;
	}
};