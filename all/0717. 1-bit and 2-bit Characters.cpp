class Solution {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		vector<int> temp{ 0 };
		int k = 0;
		for(int i = 0; i < bits.size(); ++i)
			if (bits[i])
			{
				++k;
			}
			else
			{
				if (k % 2)
					temp.push_back(1);
				k = 0;
				temp.push_back(0);
			}
		return temp[temp.size() - 2] == 0;
	}
};
