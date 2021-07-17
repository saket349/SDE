> Input: arr[] = {1, 9, 3, 10, 4, 20, 2}
> Output: 4
> Explanation: 
> The subsequence 1, 3, 4, 2 is the longest 
> subsequence of consecutive elements
### Steps -
- Step 1:  We mark the given element element of array as 1 (which means that particular value is present in hash-table or not)
- Step 2: Here we iterate again and for every index we see if the one lesser than value at that index is present in hash- table or not, if true then we move to next index without doing anything, and if condition fails, we know that if there is some consecutive sequence which includes this element then lowest element of that sequence is this value only
- Step 3: So we starts with this value and see if val+1 exists or not, and if exist then we look for val + 2 , and so on..
- Step 4: By this we get length of the sequence, and then move to next index and search for other possible sequence
- Step 5: Finally we return the maximum of all lenghts 

```
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<long long,int> mp;
        int m = 0;
        
		//  step 1: storing in hash-table
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=1;
        }
        int k;
		
		// step2:  iteration
        for(int i=0;i<nums.size();i++){
            k =1;
			
			// look for smallest value
            if(mp[nums[i] - 1]==0){
                int l = 1;
				
				//step 3: find lenght of sequence
                while(true){
                    if(mp[nums[i]+l]) k++;
                    else break;
                    l++;
                }
            }
            
			// stores maximum lenght
            m = max(m,k);
        }
		
		// return global maximum
        return m;
    }
};
```

## (worst case) time complexity: O(3n)
## extra space complexity: O(n)
