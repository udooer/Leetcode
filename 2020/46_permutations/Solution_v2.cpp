class Solution {
private:
    vector<vector<int>> ans;
    void recursivePermute(vector<int> a, int pointer){
        if(pointer == a.size()-1){
            ans.push_back(a);
            return;
        }
        for(int i=pointer;i<a.size();i++){
            swap(a[pointer], a[i]);
            recursivePermute(a, pointer+1);
            swap(a[pointer], a[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums){
        ans.clear();
        recursivePermute(nums, 0);
        return ans;
    }
};