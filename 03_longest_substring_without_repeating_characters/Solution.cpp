class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max=0;
        int count=0;
        bool b[256]={false};
        int a[256]={-1};
        int value;
        for(int i=0;i<s.length();i++){
            if(!b[s[i]]){
                count+=1;
                b[s[i]]=true;
                a[s[i]]=count;
            }
            else{
                if(count>max)
                    max=count;
                value = a[s[i]];
                count = count-value+1;
                for(int j=0;j<256;j++){
                    if(a[j]!=-1){
                        if(a[j]>value){
                            a[j]-=(value);
                        }
                        else if(a[j]==value){
                            a[j]=count;
                        }
                        else{
                            a[j]=-1;
                            b[j]=false;
                        }
                    }
                }
            }
        }
        if(count>max)
            max=count;
        return max;
    }
};
