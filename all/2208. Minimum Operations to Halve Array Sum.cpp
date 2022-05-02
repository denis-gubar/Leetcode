class Solution {
public:
    int halveArray(vector<int>& nums) {
        int N = nums.size();
		auto comp = [](pair<long long, long long> a, pair<long long, long long> b) {
			return a.first * b.second < a.second * b.first;
		};
		priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, decltype(comp)> PQ(comp);
		long long total = 0;
		for (long long x : nums)
		{
			PQ.push({ x, 1LL });
			total += x;
		}
		pair<long long, long long> sum{ 0LL, 1LL };
		int result = 0;
		while (comp(sum, { total, 2LL }))
		{
			auto P = PQ.top(); PQ.pop();			
			if (P.first % 2 == 0)
				P.first /= 2;
			else
				P.second *= 2;
			PQ.push(P);
			while (sum.second < P.second)
			{
				sum.first *= 2;
				sum.second *= 2;
			}
			while (P.second < sum.second)
			{
				P.first *= 2;
				P.second *= 2;
			}
			sum.first += P.first;
			++result;
		}
		return result;
    }
};
