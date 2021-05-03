class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            auto hash_key = hash_table.find(target-nums.at(i));
            if (hash_key!=hash_table.end())
            {
                std::vector<int> res = {hash_key->second, i};
                return res;
            }
            else{
                hash_table[nums.at(i)] = i;
            }
        }
        std::vector<int> res = {};
        return res;
    }
private:
    std::unordered_map<int, int> hash_table;
};