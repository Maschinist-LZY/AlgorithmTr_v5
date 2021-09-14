/*
思路：哈希表(unordered_map)存储键值映射，值->索引，动态数组完成插入删除
复习要点:unordered_map的声明，存储方式，值的查询(find end)，删除方式为将要删除的值的索引与最末尾值的索引对调,然后再删除(erase);
vector增加新值(push_back),删除值(pop_back)
rand%(x)->0~(x-1)
*/

class RandomizedSet {
private:
    unordered_map<int, int> hash;
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hash.find(val) != hash.end())
        {
            return false;
        }
        hash[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hash.find(val) == hash.end())
        {
            return false;
        }
        int idx = hash[val];
        int last_num = nums.back();
        nums[idx] = last_num;
        hash[last_num] = idx;
        nums[nums.size() - 1] = val;
        hash.erase(val);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % (int)nums.size();
        return nums[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */