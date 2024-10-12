class Solution {
public:
    int twoEggDrop(int n) {
        for(int result = 1; ; ++result)
            if (result * (result + 1) / 2 >= n)
                return result;
        return -1;
    }
};