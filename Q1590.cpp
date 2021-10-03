class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        int res = 0;
        for(auto x:nums){
            sum += x;
        }
        long long target = sum % (long long)p;
        if(target == 0)return 0;

        unordered_map<long long, int> preSum;
        preSum[0] = -1;
        sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += (long long)nums[i];
            long long curmod = sum % (long long)p;
            preSum[curmod] = i;
            long long targetmod = curmod >= target ? (curmod - target) : (curmod - target + p);
            if(table.count(targetmod))
                res = min(res, i - table[targetmod]);
        }
        return res == nums.size() ? -1 : res;
    }
};