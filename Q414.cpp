class Solution {
public:
    int thirdMax(vector<int>& nums) {
        const long INF = -2147483649;
        long a,b,c;
        a = INF;
        b = INF;
        c=  INF;
        for(int x:nums)
        {
            if(x==a||x==b||x==c)continue;
            if(x>a)
            {
                c=b;
                b=a;
                a=x;
            }
            else if(x>b)
            {
                c=b;
                b=x;
            }
            else if(x>c){
                c=x;
            }
        }
        if(c==INF)return a;
        else return c;
    }
};