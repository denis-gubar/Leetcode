static long long F[100'001][17];
class Solution {
public:
	template<class T, class comp = less<T>>
	struct lazy_pq : public priority_queue<T, vector<T>, comp>
	{
		using base_type = priority_queue<T, vector<T>, comp>;
		void clean()
		{
			while (!empty())
			{
				if (auto it = for_removal.find(base_type::top()); it != for_removal.end())
				{
					for_removal.erase(it);
					base_type::pop();
				}
				else
					break;
			}
		}
		void push(T const& v)
		{
			total += v;
			if (auto it = for_removal.find(v); it == for_removal.end())
			{
				base_type::push(v);
				clean();
			}
			else
				for_removal.erase(it);
		}
		size_t size()
		{
			return base_type::size() - for_removal.size();
		}
		bool empty()
		{
			return size() == 0;
		}
		void pop()
		{
			total -= base_type::top();
			base_type::pop();
			clean();
		}
		void remove(T const& v)
		{
			total -= v;
			for_removal.insert(v);
		}
		long long total;
		unordered_multiset<T> for_removal;
	};
	vector<long long> distanceToMedianSlidingWindow(vector<int>& nums, int k) {
		lazy_pq<int> LO;
		lazy_pq<int, greater<int>> HI;
		int const N = nums.size();
		vector<long long> result;
		result.reserve(N - k + 1);
		auto balance = [&]()
			{
				while (LO.size() < HI.size())
				{
					LO.push(HI.top());
					HI.pop();
				}
				while (LO.size() > HI.size() + 1)
				{
					HI.push(LO.top());
					LO.pop();
				}
			};
		auto add = [&](int n)
			{
				LO.push(n);
				HI.push(LO.top());
				LO.pop();
				balance();
			};
		auto remove = [&](int n)
			{
				if (!LO.empty() && LO.top() >= n)
				{
					LO.remove(n);
					return;
				}
				HI.remove(n);
				balance();
			};
		auto get_distance_to_median = [&LO, &HI]() -> long long
			{
				if (LO.size() >= HI.size())
					return (1LL * LO.top() * LO.size() - LO.total) + (HI.total - 1LL * LO.top() * HI.size());
				return (1LL * HI.top() * LO.size() - LO.total) + (HI.total - 1LL * HI.top() * HI.size());
			};
		for (int i = 0; i < k; ++i)
			add(nums[i]);
		result.push_back(get_distance_to_median());
		for (int i = k; i < N; ++i)
		{
			remove(nums[i - k]);
			add(nums[i]);
			result.push_back(get_distance_to_median());
		}
		return result;
	}
    long long minOperations(vector<int>& nums, int X, int K) {
        long long result = 0;
        int const N = nums.size();
		vector<long long> W = distanceToMedianSlidingWindow(nums, X);
		memset(F, 60, sizeof(F));
		long long const INF = F[0][0];
		F[0][0] = 0;
		auto update = [](long long& x, long long value)
			{
				if (x > value)
					x = value;
			};
		for (int i = 0; i < N; ++i)
			for (int j = 0; j <= K; ++j)
			{
				if (F[i][j] == INF)
					break;
				update(F[i + 1][j], F[i][j]);
				if (i + X <= N && j < K)
					update(F[i + X][j + 1], F[i][j] + W[i]);
			}
        return F[N][K];
    }
};
