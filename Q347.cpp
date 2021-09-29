class Solution {
public:
    struct cmp
    {
        bool operator()(pair<int, int>& m, pair<int, int>& n){
            return m.second > n.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash_map;
        for(auto& x:nums){
            hash_map[x]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        for(auto& [i,j]:hash_map){
            if(q.size() == k){
                if(q.top().second < j){
                    q.pop();
                    q.emplace(i,j);
                }
            }
            else{
                q.emplace(i, j);
            }
        }
        vector<int> ret;
        while(!q.empty()){
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};



