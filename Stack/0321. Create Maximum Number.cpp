class Solution {
public:
    vector<int> nums1, nums2;
    short N1, N2;
    vector<vector<vector<short>>> F;
    vector<vector<short>> A1, A2;
    vector<short> calc(short a, short b, short k)
    {
        vector<short>& result = F[a][b];
        if (result.empty())
        {
            result.resize(k);
            short& d = result[0];
            short na, nb;
            bool foundA = false, foundB = false;
            for (d = 9; ; --d)
            {
                if (auto it = lower_bound(A1[d].begin(), A1[d].end(), a); it != A1[d].end())
                {
                    na = *it + 1;
                    if (N1 - na + N2 - b + 1 >= k)
                        foundA = true;
                }
                if (auto it = lower_bound(A2[d].begin(), A2[d].end(), b); it != A2[d].end())
                {
                    nb = *it + 1;
                    if (N1 - a + N2 - nb + 1 >= k)
                        foundB = true;
                }
                if (!foundA && !foundB)
                    continue;
                if (k == 1 && (foundA || foundB))
                    break;
                vector<short> resultA, resultB;
                if (foundA)
                    resultA = calc(na, b, k - 1);
                if (foundB)
                    resultB = calc(a, nb, k - 1);
                if (resultA < resultB)
                    copy(resultB.begin(), resultB.end(), result.begin() + 1);
                else
                    copy(resultA.begin(), resultA.end(), result.begin() + 1);
                break;
            }
        }
        return result;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        N1 = nums1.size(), N2 = nums2.size();
        F = vector<vector<vector<short>>>(N1 + 1, vector<vector<short>>(N2 + 1));
        this->nums1 = nums1;
        this->nums2 = nums2;
        A1 = vector<vector<short>>(10);
        A2 = vector<vector<short>>(10);
        for (int i = 0; i < N1; ++i)
            A1[nums1[i]].push_back(i);
        for (int i = 0; i < N2; ++i)
            A2[nums2[i]].push_back(i);
        vector<int> result(k);
        vector<short> shortResult = calc(0, 0, k);
        for (int i = 0; i < k; ++i)
            result[i] = shortResult[i];
        return result;
    }
};
