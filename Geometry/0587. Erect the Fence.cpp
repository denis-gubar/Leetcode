class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>> points;
        
        sort(trees.begin(), trees.end(), [](auto& a, auto& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            } else {
                return a[0] < b[0];
            }
        });
        
        int n = trees.size();
        
        for (int i = 0; i < n; ++i) {
            while (points.size() >= 2 
                   && orientation(points[points.size() - 2], points[points.size() - 1], trees[i]) > 0) {
                points.pop_back();
            }
            
            points.push_back(trees[i]);
        }
        
        points.pop_back();
        for (int i = n - 1; i >= 0; --i) {
            while (points.size() >= 2 
                   && orientation(points[points.size() - 2], points[points.size() - 1], trees[i]) > 0) {
                points.pop_back();
            }
            
            points.push_back(trees[i]);
        }
        
        sort(points.begin(), points.end());
        
        vector<vector<int>> ans;
        
        for (auto& p : points) {
            if (ans.size() > 0 && p == ans.back()) {
                continue;
            }
            
            ans.push_back(p);
        }
        
        return ans;
    }
    
    int orientation(vector<int>& p, vector<int>& q, vector<int>& r) {
        return (r[1] - p[1]) * (q[0] - p[0]) - (q[1] - p[1]) * (r[0] - p[0]);
    }
};