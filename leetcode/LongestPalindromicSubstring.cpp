class Solution {
public:
    string longestPalindrome(string s) {
        int i,j,k;
        int maxLength=0;
        string maxPalindrome;
        for(i=0; i<s.length(); i++)
        {
            for(j=i; j<s.length(); j++)
            {
                bool flag=false;
                for(k=i; k<=(i+j)/2; k++)
                {
                    if(s[k]!=s[j-(k-i)])
                    {
                        flag=true;
                        break;
                    }
                }
                if(flag==false)
                {
                    if(maxPalindrome.length()<j-i+1)
                        maxPalindrome=s.substr(i,j-i+1);
                }
            }
        }
        return maxPalindrome;
    }
};