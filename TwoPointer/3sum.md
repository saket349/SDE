- find all unique triplet that sum up to given value
- TC: O(N<sup>2</sup>)  SC: O(1)

```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>> ans;
	
	// we first sort the array, which make it easier to iterate and get unique value
	// as we can simply skip value if nums[iterator] == nums[iterator - 1], as sorted
	sort(nums.begin(), nums.end());
	
	for(int i=0;i<n;i++){
		if(i>0 && nums[i]==nums[i-1]) continue;   // repeating condiiton (1)
		int l = i + 1;   // start pointer
		int r = n - 1;  // end pointer 
		while(l<r){
			if(l>i+1 && nums[l]==nums[l-1]) {     // repeating condiiton (2)
				l++; 
				continue;
			}
			if(r<n-1 && nums[r]==nums[r+1]){    // repeating condition (3)
				r--;
				continue;
			}
			if(nums[i]+nums[l]+nums[r]==0) {
				ans.push_back({nums[i], nums[l], nums[r]});
				l++; r--;
				continue;
			}
			if((nums[i]+nums[l]+nums[r])>0) r--;
			else l++;
		}
	}
	return ans;
}
```
