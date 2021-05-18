class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(),nums.end());
        int error = 1000000;
        int ans;
        int low_pointer, high_pointer;
        int three_sum;
        for(int i=0;i<nums.size()-2;i++){
            low_pointer = i+1;
            high_pointer = nums.size()-1;
            while(high_pointer>low_pointer){
                three_sum = nums[i] + nums[low_pointer] + nums[high_pointer];
                if(abs(target-three_sum)<error){
                    error = abs(target-three_sum);
                    ans = three_sum;
                }
                if(three_sum > target)
                    high_pointer -= 1;
                else if(three_sum<target)
                    low_pointer += 1;
                else
                    return target;
            }
        }
        return ans;
    }
};