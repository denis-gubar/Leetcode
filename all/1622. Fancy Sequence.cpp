class Fancy {
public:
	int power(int x, int n)
	{
		if (n == 1)
			return x;
		long long result = x;
		long long extra = 1;
		while (n > 1)
		{
			if (n % 2)
			{
				extra *= result;
				extra %= MOD;
			}
			result *= result;
			result %= MOD;
			n /= 2;
		}
		return result * extra % MOD;
	}
	int div(int x)
	{
		return power(x, MOD - 2);
	}

	int const MOD = 1'000'000'007;
	Fancy() {
		delta.push_back(0);
		k.push_back(1);
	}

	void append(int val) {
		data.push_back(val);
		delta.push_back(delta.back());
		k.push_back(k.back());
	}

	void addAll(int inc) {
		if (data.empty())
			return;
		delta.back() += inc;
		delta.back() %= MOD;
	}

	void multAll(int m) {
		if (data.empty())
			return;
		delta.back() *= m;
		delta.back() %= MOD;
		k.back() *= m;
		k.back() %= MOD;
	}

	int getIndex(int idx) {
		if (idx >= data.size())
			return -1;
		long long result = data[idx];
		long long K = k.back() * div(k[idx]) % MOD;
		long long D = (delta.back() - K * delta[idx] + 1LL * MOD * MOD) % MOD;
		result *= K;
		result %= MOD;
		result += D;
		result %= MOD;
		return result;
	}

	vector<int> index;
	vector<long long> delta;
	vector<long long> k;
	vector<int> data;
};