class Solution {
private: 
    vector<string> v_s;
    void recursiveP(string s, int left_count, int right_count, int n){
        if(s.size()==2*n){
            v_s.push_back(s);
            return;
        }
        if(left_count)
            recursiveP(s+"(", left_count-1, right_count, n);
        if(right_count && (right_count>left_count))
            recursiveP(s+")", left_count, right_count-1, n);
    }
public:
    vector<string> generateParenthesis(int n) {
        v_s.clear();
        recursiveP("", n, n, n);
        return v_s;
    }
};
