// concept same as that of kth element of two sorted array
// merged aaray is formed of some elements of arr1 and some elements of arr2
int findMidSum(int arr1[], int arr2[], int n) {
            // code here 
            if(n==1) return (arr1[0] + arr2[0]);
            int low = 0 ;
            int high = n;
            while(low <= high){
                int mid1 = (low + high)/2;
                int mid2 = n - mid1;
                int left1 = (mid1-1 < 0) ? INT_MIN : arr1[mid1-1];
                int left2 = (mid2-1 < 0) ? INT_MIN : arr2[mid2-1];
                int right1 = (mid1 >= n) ? INT_MAX : arr1[mid1];
                int right2 = (mid2 >= n) ? INT_MAX : arr2[mid2];
                if(left1 <= right2 && left2 <= right1) return (max(left1, left2) + min(right1, right2));
                if(left1 > right2) high = mid1 - 1;
                if(left2 > right1) low = mid1 + 1;
            } 
            return 0;
    }
