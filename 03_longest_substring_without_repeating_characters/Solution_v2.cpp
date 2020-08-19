class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max=0;
        int count=0;
        int a[256]={0};
        int value;
        for(int i=0;i<s.length();i++){
            if(a[s[i]]==0){
                count+=1;
                a[s[i]]=count;
            }
            else{
                if(count>max)
                    max=count;
                value = a[s[i]];
                count = count-value+1;
                for(int j=0;j<256;j++){
                    if(a[j]!=0){
                        if(a[j]>value)
                            a[j]-=(value);
                        else if(a[j]==value)
                            a[j]=count;
                        else
                            a[j]=0;
                    }
                }
            }
        }
        if(count>max)
            max=count;
        return max;
    }
};
