-  we break our inpurt into digits, and then we find next permutation of that digit array
-  if next permutation exist, our ans is integer we get from that permutation else -1
```cpp
int nextGreaterElement(int n) {
        vector<int> nums;
        int temp = n;
        int max = pow(2,31) - 1;
        cout<<max;
        while(temp){
            nums.push_back(temp%10);
            temp = temp/10;
        }
        // Now we will find next permutation for our sequence nums,  
        // if next permutation exist then return that, else return -1
        // if you want to use next_permutation, then you can  do that
        
        int k; bool flag = false; int ind; 
        // k stores the first decresing element from end
        // flag to know if next permuatutaion exist or not
        // ind to get index of just greater element of nums[k];
        
        // next permutation algorithm: step 1
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                k = i;
                for(int j=i-1;j>=0;j--){
                    if(nums[j]>nums[i]) ind = j;
                    else break;
                }
                swap(nums[k], nums[ind]);
                flag = true;
             break;   
            }
        }
        if(flag==false) return -1;     // failure: next permutation does not exist
        
        // success
        // next permutation algorithm: step 2
        for(int i=0;i<k;i++){          
            if(i>=(k-i-1)) break;
            swap(nums[i], nums[k-i-1]);
        }
        
        // now we have our next premutation
        // our next task is to get interger value using nums array
        long long l = 1;
        int m = 0;
        for(int i=0;i<nums.size();i++){
            if((max-(nums[i]*l))<m) return -1;     // as our ans should fit 32bit integer
            m = m + nums[i]*l; 
            l = l*10;
            if(l>max) break;                      // when we are over 32bit integer
        }
        return m;
    }
```
