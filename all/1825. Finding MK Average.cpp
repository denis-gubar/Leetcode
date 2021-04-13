class MKAverage {
public:
	MKAverage(int m, int k): sum(0), m(m), k(k), pos(0), Q(vector<int>(m)) {

	}

	void add(int num)
	{
		if (L.size() == k)
		{
			auto it = prev(L.end());
			if (*it > num)
			{
				int newNum = *it;
				L.erase(it);
				L.insert(num);
				add(newNum);
				return;
			}
		}
		else
		{
			L.insert(num);
            return;
		}
		if (R.size() == k)
		{
			auto it = R.begin();
			if (*it < num)
			{
				int newNum = *it;
				R.erase(it);
				R.insert(num);
				add(newNum);
				return;
			}
		}
		else
		{
			R.insert(num);
            return;
		}
		if (S.size() == m - 2 * k)
		{
			auto it = prev(S.end());
			if (*it > num)
			{
				int newNum = *it;
				sum -= newNum;
				S.erase(it);
				sum += num;
				S.insert(num);
				add(newNum);
				return;
			}
		}
		else
		{
			sum += num;
			S.insert(num);
            return;
		}
	}

	void addElement(int num) {
		int& x = Q[pos % m];
		if (pos >= m)
		{
			auto it = S.find(x);
			if (it == S.end())
			{
				it = L.find(x);
				if (it == L.end())
				{
					it = R.find(x);
					R.erase(it);
					it = prev(S.end());
					int newNum = *it;
                    sum -= newNum;
					S.erase(it);
					R.insert(newNum);
				}
				else
				{
					L.erase(it);
					it = S.begin();
					int newNum = *it;
                    sum -= newNum;
					S.erase(it);
					L.insert(newNum);
				}
			}
			else
			{
				sum -= x;
				S.erase(it);
			}
		}
		x = num;
		++pos;
		add(num);
	}

	int calculateMKAverage() {
		if (S.size() < m - 2 * k)
			return -1;
		return sum / (m - 2 * k);
	}
	multiset<int> S;
	multiset<int> L;
	multiset<int> R;
	vector<int> Q;
	long long sum;
	int m;
	int k;
	int pos;
};



/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */