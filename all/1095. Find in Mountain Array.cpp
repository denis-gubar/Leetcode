class Solution {
public:
	int get(MountainArray& mountainArr, int i, unordered_map<int, int>& F)
	{
		if (F.find(i) == F.end())
			F[i] = mountainArr.get(i);
		return F[i];
	}
	int findInMountainArray(int target, MountainArray& mountainArr) {
		unordered_map<int, int> F;
		int N = mountainArr.length();
		int a = 0, b = N - 1;
		auto calc = [this, target, &F, &mountainArr](int i)
		{
			return get(mountainArr, i, F);
		};
		while (a + 2 < b)
		{
			int m = (a + b) / 2;
			if (calc(m) < calc(m + 1))
				a = m;
			else
				b = m + 1;
		}
		int mount = a + 1;
		if (calc(mount) == target)
			return mount;
		if (calc(mount) < target)
			return -1;
		a = -1, b = mount;
		while (a + 1 < b)
		{
			int m = (a + b) / 2;
			if (calc(m) == target)
				return m;
			if (calc(m) < target)
				a = m;
			else
				b = m;
		}
		a = mount, b = N;
		while (a + 1 < b)
		{
			int m = (a + b) / 2;
			if (calc(m) == target)
				return m;
			if (calc(m) > target)
				a = m;
			else
				b = m;
		}
		return -1;
	}
};