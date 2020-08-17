class Solution {
public:
    int myAtoi(string str){
        int length = str.length();
        int sign = 1;
        if(length==0)
            return 0;
        long int cum = 0;
        int i = 0;
        while(str[i]==' ' && i<length){
            i++;
        }
        if(i==length)
            return 0;
        if(str[i]=='-'){
            i++;
            sign = -1;
        }
        else if(str[i]=='+')
            i++;
        while(i<length){
            if(isdigit(str[i])){
                cum = cum*10 + str[i]-'0';
            }
            else
                return sign*cum;
            if(cum>=INT_MAX && sign==1){
                return INT_MAX;
            }
            else if(cum>INT_MAX && sign==-1)
                return INT_MIN;
            i++;
        }
        return sign*cum;
    }
};
