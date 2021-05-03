class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //拆到只剩一個即為最大值
        if(nums.size()==1)
            return nums.at(0);
        vector<int> temp;
        int m1,m2,m3,m4;
        int number=nums.size()/2;
        
        temp.assign(nums.begin(), nums.begin()+number);
        m1 = maxSubArray(temp);
        temp.assign(nums.begin()+number, nums.end());
        m2 = maxSubArray(temp);
        int max = -2147483647;
        int sum = 0;
        for(int i=number-1;i>=0;i--){
            sum+=nums.at(i);
            if(sum>max)
                max = sum;
        }
        m3 = max;
        max = -2147483647;
        sum = 0;
        for(int i=number;i<nums.size();i++){
            sum+=nums[i];
            if(sum>max)
                max = sum;
        }
        m4 = max;
        max = m1;
        if(m2>max)
            max = m2;
        if((m3+m4)>max)
            max = m3+m4;
        return max;
    }
};