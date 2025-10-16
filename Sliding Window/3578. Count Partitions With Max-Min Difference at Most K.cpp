static long long F[50'001];
static long long A[50'001];
static int const MOD = 1'000'000'007;
class Solution {
public:
    int countPartitions(vector<int>& nums, int K) {
        int const N = nums.size();
        int result = 0;
		deque<int> QA, QB;
		auto remove = [&nums, &QA, &QB](int pos)
			{
				while (!QA.empty() && QA.front() <= pos)
					QA.pop_front();
				while (!QB.empty() && QB.front() <= pos)
					QB.pop_front();
			};
		auto add = [&nums, &QA, &QB, &remove](int pos)
			{
				while (!QA.empty() && nums[QA.front()] <= nums[pos])
					QA.pop_front();
				while (!QA.empty() && nums[QA.back()] <= nums[pos])
					QA.pop_back();
				QA.push_back(pos);
				while (!QB.empty() && nums[QB.front()] >= nums[pos])
					QB.pop_front();
				while (!QB.empty() && nums[QB.back()] >= nums[pos])
					QB.pop_back();
				QB.push_back(pos);
			};
		int a = 0, b = 0;
		memset(F, 0, sizeof(F));
		A[0] = 0;
		F[0] = 1;
		while (b < N)
		{
			add(b);
			while (!QA.empty() && !QB.empty() && nums[QA.front()] - nums[QB.front()] > K)
				remove(a), ++a;
			A[b + 1] = A[b] + F[b];
			for (int j = a; j <= b; ++j)
				F[b + 1] = (A[b + 1] - A[a]) % MOD;
			++b;
		}
        return F[N];
    }
};
