#define pi  pair<int, int> 
struct comp{
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        if(a.first==b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
};
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        priority_queue<pi, vector<pi>, comp > q;
        for(auto i = mp.begin(); i!=mp.end();i++){
            q.push({i->second, i->first});
        }
        vector<int> res;
        while(!q.empty()){
            int x = q.top().first;
            int y = q.top().second;
            while(x--){
                res.push_back(y);
            }
            q.pop();
        }
        return res;
    }
};
