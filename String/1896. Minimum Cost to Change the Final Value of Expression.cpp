class Solution {
public:
	int calc(int start, int end)
	{
		return 0;
	}
	int minOperationsToFlip(string expression) {
		int N = expression.size();
		vector<int> S, D;
		S.push_back(-1);
		D.push_back(-1);
		for (char c : expression)
		{
			if (c == '(')
			{
				S.push_back(-1);
				D.push_back(-1);
			}
			if (c == ')')
			{
				int t = S.back();
				int x = D.back();
				S.pop_back();
				D.pop_back();
				if (S.back() == -1)
				{
					S.back() = t;
					D.back() = x;
				}
				else
				{
					S.push_back(t);
					D.push_back(x);
				}
			}
			if (c == '0')
			{
				S.push_back(0);
				D.push_back(1);
			}
			if (c == '1')
			{
				S.push_back(1);
				D.push_back(1);
			}
			if (c == '&')
				S.push_back(2);
			if (c == '|')
				S.push_back(3);
			if (S.back() == 0 || S.back() == 1)
			{
				int b = S.back();
				int x = D.back();
				S.pop_back();
				D.pop_back();
				if (S.back() == 2)
				{
					S.pop_back();
					if (S.back() == 0 && b == 0)
					{
						D.back() = 1 + min(D.back(), x);
					}
					else if (S.back() == 1 && b == 0)
					{
						D.back() = 1;
					}
					else if (S.back() == 0 && b == 1)
					{
						D.back() = 1;
					}
					else if (S.back() == 1 && b == 1)
					{
						D.back() = min(D.back(), x);
					}
					S.back() &= b;					
				}
				else if (S.back() == 3)
				{
					S.pop_back();
					if (S.back() == 0 && b == 0)
					{
						D.back() = min(D.back(), x);
					}
					else if (S.back() == 1 && b == 0)
					{
						D.back() = 1;
					}
					else if (S.back() == 0 && b == 1)
					{
						D.back() = 1;
					}
					else if (S.back() == 1 && b == 1)
					{
						D.back() = 1 + min(D.back(), x);
					}
					S.back() |= b;
				}
				else
				{
					S.push_back(b);
					D.push_back(x);
				}
			}
		}
		return D.back();
	}
};