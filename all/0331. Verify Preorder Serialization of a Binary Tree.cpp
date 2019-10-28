class Solution {
public:
	bool isValidSerialization(string preorder) {
		int balance = 1;
		for(int i = 0; i < preorder.size(); ++i)
			if (preorder[i] == '#')
			{
				--balance;
				if (balance < 0 || balance == 0 && i + 1 < preorder.size())
					return false;
			}
			else if (isdigit(preorder[i]) && (!i || !isdigit(preorder[i - 1])))
				++balance;
		return balance == 0;
	}
};
