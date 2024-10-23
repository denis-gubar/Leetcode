class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> result(5);
        double& minimum = result[0];
        double& maximum = result[1];
        double& mean = result[2];
        double& median = result[3];
        double& mode = result[4];
        long long total = 0;
        int sum = 0;
        minimum = -1.0;
        maximum = -1.0;
        int best = 0;
        for (int i = 0; i < 256; ++i)
            if (count[i] > 0)
            {
                total += 1LL * i * count[i];
                sum += count[i];
                if (minimum < 0)
                    minimum = i;
                maximum = i;
                if (count[best] < count[i])
                    best = i;
            }
        if (sum % 2 == 1)
        {
            for (int i = 0, current = 0; i < 256; ++i)
                if (count[i] > 0)
                {
                    current += count[i];
                    if (current >= sum / 2 + 1)
                    {
                        median = i;
                        break;
                    }
                }
        }
        else
        {
            for (int i = 0, current = 0; i < 256; ++i)
                if (count[i] > 0)
                {
                    current += count[i];
                    if (current > sum / 2)
                    {
                        median = i;
                        break;
                    }
                    else if (current == sum / 2)
                    {
                        median = 0.5 * i;
                        for(int j = i + 1; j < 256; ++j)
                            if (count[j] > 0)
                            {
                                median += 0.5 * j;
                                break;
                            }
                        break;
                    }
                }
        }
        mean = 1.0 * total / sum;
        mode = best;
        return result;
    }
};
