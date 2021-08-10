#define p pair<int,int>
#define pp pair<double,pair<int,int>>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pp> mh;
        for(int i=0;i<points.size();i++)
        {
            mh.push({sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]),{points[i][0],points[i][1]}});
            if(mh.size()>k)
                mh.pop();
        }
        vector<vector<int>> res;
        while(mh.size()>0)
        {
            
            
            pp temp = mh.top();
            mh.pop();
            vector<int> temp2 = {temp.second.first,temp.second.second};
            res.push_back(temp2);
        }
        return res;
    }
};
