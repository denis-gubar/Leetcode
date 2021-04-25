template <class Container>
struct counter_inserter
{
	counter_inserter(Container& cont): container(addressof(cont))
	{		
	}

	counter_inserter& operator=(typename Container::key_type const& val)
	{
		++(*container)[val];
		return *this;
	}

	counter_inserter& operator*()
	{
		return *this;
	}

	counter_inserter& operator++()
	{
		return *this;
	}

	counter_inserter& operator++(int)
	{
		return *this;
	}
protected:
	Container* container = nullptr;
};

class Solution {
public:
	int leastBricks(vector<vector<int>>& wall) {
		int N = wall.size();
		int result = N;
		unordered_map<int, int> M;
		for (int i = 0; i < N; ++i)
			partial_sum(wall[i].begin(), prev(wall[i].end()), counter_inserter(M));
		int best = 0;
		for (auto [key, value] : M)
			if (value > best)
                best = value;
		return result - best;
	}
};