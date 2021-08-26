class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		int notes5 = 0, notes10 = 0;
		for (int i = 0; i < bills.size(); ++i)
		{
			if (bills[i] == 20)
			{				
				if (notes10)
				{
					notes10 -= 2;
					bills[i] = 10;
				}
				else
				{
					if (notes5 >= 3)
						notes5 -= 3;
					else
						return false;
				}
			}
			if (bills[i] == 5)
				++notes5;
			if (bills[i] == 10)
			{
				++notes10;
				if (notes5)
					--notes5;
				else
					return false;
			}			
		}
		return true;
	}
};