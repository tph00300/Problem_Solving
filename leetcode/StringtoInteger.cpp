class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int answer = 0;
        int where=0;
        while(i<s.length() && s[i]==' ')
            i++;
        if(s[i]=='-')
        {
            i++;
            where=-1;
        }
        else if(s[i]=='+')
        {
            where=1;
            i++;
        }
        else
            where=1;
        while(i<s.length() && s[i]>='0' && s[i]<='9')
        {
            if(answer>(INT_MAX-(s[i]-'0'))/10)
            {
                if(where==-1)
                    return INT_MIN;
                return INT_MAX;
            }
            answer*=10;
            answer+=(s[i]-'0');
            i++;
        }
        return answer*where;
    }
};