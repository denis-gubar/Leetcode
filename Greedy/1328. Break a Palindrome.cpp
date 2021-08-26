class Solution {
public:
	string breakPalindrome(string palindrome) {
		bool flag = false;
		string result(palindrome);
		for(int i = 0; i < result.size() / 2; ++i)
			if (result[i] != 'a')
			{
				result[i] = 'a';
				flag = true;
				break;
			}
		if (!flag) 
        {
            if (result.size() > 1)
                result.back() = 'b';
            else
                return {};
        }
		return result;
	}
};