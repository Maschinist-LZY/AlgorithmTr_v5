/*
Q414: 寻找第三大的数
思路：遍历，分别保存第一，第二大，第三大的数
注意：边界条件的时候可以根据提示的信息，设置最小值
tips：C++11 中循环可以直接遍历一个可以迭代的数据结构，声明一个变量，迭代冒号后面的数据结构里的每一个元素
*/
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