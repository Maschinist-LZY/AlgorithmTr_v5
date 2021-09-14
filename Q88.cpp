/*
思路：
从后往前比较，从后往前插入
三个指针：current指向当前插入的位置，m指向数组1的待比较元素，n指向数组2的待比较元素
注意：数组为空的情况
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int current = m + n - 1;
        while(current>=0)
        {
            if(n==0)return;
            if(m<1){
                nums1[current] = nums2[n-1];
                current--;
                n--;
                continue;
            }
            if(nums1[m-1] < nums2[n-1]){
                nums1[current] = nums2[n-1];
                n--;
            }
            else{
                nums1[current] = nums1[m-1];
                m--;
            }
            current--;

        }
    }
};