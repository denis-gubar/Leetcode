class Solution {
public:
	int countConsistentStrings(string allowed, vector<string>& words) {
		int result = 0;
        int A = 0;
        for(char c : allowed)
            A |= 1 << (c - 'a');
		for (string const& w : words)
		{
			bool flag = true;
			for (char c : w)
				if ((A & (1 << c - 'a')) == 0)
                {
					flag = false;
                    break;
                }
			result += flag;
		}
		return result;
	}
};