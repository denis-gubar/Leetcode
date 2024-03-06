#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> result, A, B;
        int N = nums.size();
        A.reserve(N);
        B.reserve(N);
        result.reserve(N);
        ordered_set<pair<int, int>> SA, SB;
        for (int i = 0; i < N; ++i)
        {
            int const x = nums[i];
            if (A.empty())
            {
                A.push_back(x); SA.insert({ -x, -i });
            }
            else if (B.empty())
            {
                B.push_back(x); SB.insert({ -x, -i });
            }
            else
            {
                int a = SA.order_of_key({ -x, -i });
                int b = SB.order_of_key({ -x, -i });
                if (a > b || a == b && A.size() <= B.size())
                {
                    A.push_back(x); SA.insert({ -x, -i });
                }
                else
                {
                    B.push_back(x); SB.insert({ -x, -i });
                }
            }
        }
        copy(A.begin(), A.end(), back_inserter(result));
        copy(B.begin(), B.end(), back_inserter(result));
        return result;
    }
};
