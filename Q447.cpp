class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res=0;
        unordered_map<int, int> dis;
        if(points.size()<=2)return 0;
        for(int i=0;i<points.size();i++){
            dis.clear();
            for(int j=0;j<points.size();j++){
                int distance = (points[i][0]-points[j][0])*(points[i][0]-points[j][0]) + (points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
                dis[distance]++;
            }
            for(auto& [_,n]:dis){
                res += n*(n-1);
            }
        }
        return res;
    }
};