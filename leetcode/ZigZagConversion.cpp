class Solution {
public:
    string convert(string s, int numRows) {
        int i;
        string answer;
        int m=0;
        int n=(numRows-1)*2;
        if(n==0)
            n=1;
        for(i=n; i>=2; i-=2)
        {
            for(int j=m; j<s.length(); j+=n)
            {
                answer.append(1,s[j]);
                if(s.length()>j+i && i!=n)
                {
                    answer.append(1,s[j+i]);
                }
            }
            m++;
        }
        for(i=m; i<s.length(); i+=n)
        {
            answer.append(1,s[i]);
        }
        return answer;
    }
};