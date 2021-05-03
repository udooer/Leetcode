class Solution {
private: 
    vector<string> v_s;
    void recursiveP(string s, int left_count, int right_count){
        if(!left_count){
            for(int i=0;i<right_count;i++)
                s+=")";
            v_s.push_back(s);
            return;
        }
        if(left_count)
            recursiveP(s+"(", left_count-1, right_count);
        if(right_count && (right_count>left_count))
            recursiveP(s+")", left_count, right_count-1);
    }
public:
    vector<string> generateParenthesis(int n) {
        v_s.clear();
        recursiveP("", n, n);
        return v_s;
    }
};
