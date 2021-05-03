class Solution {
private:
    vector<vector<int>> v_i;
    void recursiveS(vector<int> numbers, int label, int count){
        if(count==numbers.size()){
            vector<int> a;
            a.assign(numbers.begin(),numbers.begin()+label);
            v_i.push_back(a);
            return;
        }
        recursiveS(numbers, label, count+1);
        swap(numbers[label], numbers[count]);
        recursiveS(numbers, label+1, count+1);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        v_i.clear();
        recursiveS(nums, 0, 0);
        return v_i;
    }
};
