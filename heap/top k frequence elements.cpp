// implement is same as k largest elements, only instead of element here we have frequency
// so keep freq array, and push pair in queue

vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>  mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
        int cnt=0;
        for(auto it = mp.begin(); it!=mp.end();it++){
            cnt++;
            q.push({it->second, it->first});
            if(cnt>k){
                q.pop();
                cnt--;
            }
        }
        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
