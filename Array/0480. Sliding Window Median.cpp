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
			base_type::pop();
			clean();
		}
		void remove(T const& v)
		{
			for_removal.insert(v);
		}
		unordered_multiset<T> for_removal;
	};
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		lazy_pq<int> LO;
		lazy_pq<int, greater<int>> HI;
		vector<double> result;
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
		auto get_median = [&]()
		{
			if (LO.size() == HI.size())
				return 0.5 * LO.top() + 0.5 * HI.top();
			if (LO.size() < HI.size())
				return 1.0 * HI.top();
			return 1.0 * LO.top();
		};
		for (int i = 0; i < k; ++i)
			add(nums[i]);
		result.push_back(get_median());
		for (int i = k; i < nums.size(); ++i)
		{
			remove(nums[i - k]);
			add(nums[i]);
			result.push_back(get_median());
		}
		return result;
	}
};