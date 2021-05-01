class Solution {
public:
    int reverse(int x) {
        int m=1,answer=0;
        bool flag=false;
        while(x!=0)
        {
            if(answer> INT_MAX/10 || answer<INT_MIN/10)
                return 0;
            answer*=10;
            answer+=x%10;
            x/=10;
        }
        return answer;
    }
};