class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2 == 1)
            return {};
        vector<long long> result;
        long long total = 0;
        while (total < finalSum)
        {
            result.push_back((1LL + result.size()) * 2);
            total += result.back();
        }
        if (total > finalSum)
        {
			total -= result.back();
			result.pop_back();
            long long delta = finalSum - total;
            if (result.empty() || result.back() < delta)
                result.push_back(delta);
            else
                result.back() += delta;
        }
        return result;
    }
};
