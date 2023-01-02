class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int N = words.size();
        for(int k = 0; k < N; ++k)        
            for(int d = -1; d <= 1; d += 2)
                if (target == words[(startIndex + d * k + N) % N])
                    return k;
        return -1;
    }
};
