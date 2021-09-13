/*
Q剑53: 寻找缺失的数
思路1：遍历，逐个对比
注意：最后一个元素的情况
tips：C++11 中可以使用xxx.size()获取数组大小
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i=0; i<nums.size();i++)
        {
            if(nums[i]!=i)return i;
        }
        return nums.size();
    }
};

/*
Q剑53: 寻找缺失的数
思路2：二分查找(中间位置索引与值一致时说明问题出在右侧，需要将左边界右移，小于值时说明左侧值缺失，需要将有边界左移)
注意：首个元素是否为0
tips：有序数组，且寻找确定的数值，可以采用二分法，返回条件可以从左边界/右边界/或中间值确认
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int mid;
        if(nums[0]!=0)return 0;
        int n = nums.size();
        int left = 0,right = n - 1;
        while(left <= right)
        {
            mid = (left + right)>>1;
            if(nums[mid]>mid)
            {
                right = mid - 1;
            }
            if(nums[mid]==mid)
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
