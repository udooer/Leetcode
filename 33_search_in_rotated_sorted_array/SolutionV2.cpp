class Solution {
public:
    int search(vector<int>& nums, int target) {
        return helper(nums, 0, nums.size()-1, target);
    }
    int helper(vector<int>& nums, int l, int r, int target){
        if(r>=l){
             if(nums[l]>=nums[r]){
                if(target==nums[l])
                    return l;
                 else
                     return helper(nums, l+1, r, target);
            }
            int mid = (l+r)/2;
            if(target==nums[mid])
                return mid;
            if(target>nums[mid])
                return helper(nums, mid+1, r, target);
            else
                return helper(nums, l, mid-1, target);
        }
        return -1;
    }
};