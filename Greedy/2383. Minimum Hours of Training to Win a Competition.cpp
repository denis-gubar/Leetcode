class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int result = 0;
        int N = energy.size();
        for (int i = 0; i < N; ++i)
        {
            int delta = max(0, energy[i] - initialEnergy + 1) + max(0, experience[i] - initialExperience + 1);
            result += delta;
            initialExperience += max(0, experience[i] - initialExperience + 1);
            initialEnergy += max(0, energy[i] - initialEnergy + 1);
            initialExperience += experience[i];
            initialEnergy -= energy[i];
        }
        return result;
    }
};
