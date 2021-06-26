- We make use of stack for solving this problem
- Basic idea is to store decreasing elements from last,
- and when ever we encounter any number which is more then last inserted values in stack then we delete those and insert our current number into stack
- For any number its next greater element is top element in the stack
```cpp
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	stack<int> s;
	vector<int> v;
	int n = nums2.size(); int m = nums1.size();
	if(n==0 || m==0) return v;
	unordered_map<int,int> mp;
	s.push(nums2[n-1]);
	mp[nums2[n-1]] = -1;
	for(int i=n-2;i>=0;i--){
		while(!s.empty() && s.top() <= nums2[i]){
			s.pop();
		}
		if(s.empty()) mp[nums2[i]] = -1;
		else mp[nums2[i]] = s.top();
		s.push(nums2[i]);
	}

	for(int i=0;i<m;i++){
		int x = mp[nums1[i]];
		v.push_back(x);
	}
	return v;
}
```
