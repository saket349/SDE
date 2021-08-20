void zigZag(int a[], int n) {
	    // code here
	    bool m = true;
	    for(int i=0;i<n-1;i++){
	        if(m){
	            if(a[i]>a[i+1]) swap(a[i], a[i+1]);
	        }else{
	            if(a[i]<a[i+1]) swap(a[i], a[i+1]);
	        }
	        m ^= true;
	    }
	}
