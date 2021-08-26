class Solution {
public:
	bool isPossible(vector<int> target) {
		priority_queue<long long> Q;
		for (int x : target)
			Q.push(x);
		long long total = accumulate(target.begin(), target.end(), 0LL);
		while (!Q.empty())
		{
			long long x = Q.top(); Q.pop();
			if (x == 1)
				return true;
            if (Q.empty())
                return false;
			long long rest = total - x;
			long long delta = x - Q.top() - 1;
			long long newX = x - delta / rest * rest;
            if (x == newX)
                newX = x - rest;
			if (newX <= 0)
				return false;
			Q.push(newX);
			total += newX - x;
		}
		return false;
	}
};