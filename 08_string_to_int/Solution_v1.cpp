class Solution {
public:
    int myAtoi(string str) {
        if(str.length()==0)
            return 0;
        stringstream ss;
        int ans;
        int i=0;
        while(str[i]==' ' && i<str.length()){
            i++;
        }
        if(i==str.length())
            return 0;
        str.assign(str.begin()+i,str.end());
        ss<<str;
        ss>>ans;
        return ans;
    }
};
