class Solution {
public:
    vector<vector<int>> ans;
    void recursivePermute(vector<int> a,vector<int> rest){
        if(rest.size()==0){
            ans.push_back(a);
            return;
        }
        vector<int> a_1;
        vector<int> rest_1;
        for(int i=0;i<rest.size();i++){
            a_1=a;
            rest_1=rest;
            a_1.push_back(rest_1[i]);
            rest_1.erase(rest_1.begin()+i);
            recursivePermute(a_1, rest_1);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> a;
        a.clear();
        ans.clear();
        recursivePermute(a, nums);
        return ans;
    }
};