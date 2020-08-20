class Solution {
private:
    vector<vector<int>> v_i;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int m;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            m = v_i.size();
            v_i.push_back({nums[i]});
            for(int j=0;j<m;j++){
                v = v_i[j];
                v.push_back(nums[i]);
                v_i.push_back(v);
            }
        }
        v_i.push_back({});
        return v_i;
    }
};
