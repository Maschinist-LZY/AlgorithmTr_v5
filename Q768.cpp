/*
思路：栈辅助寻找局部最大值（会补充，解释不完善）
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> newS;
        newS.push(arr[0]);
        int max=arr[0];
        int x = 1;
        while(x<arr.size()){
            if(arr[x]>=max)
            {
                newS.push(arr[x]);
                max = arr[x];
            }
            else{

            while(!newS.empty() && arr[x]<newS.top()){
                newS.pop();
            }
            newS.push(max);
            }
         x++;   
        }
        return newS.size();
    }
};