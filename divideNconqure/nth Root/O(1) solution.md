```
int NthRoot(int n, int m)
	{
	    
        double p=((log10(m))/n);
        double q=ceil(pow(10,p));
        double u=floor(pow(10,p));
        long long r=pow(q,n);
        long long s=pow(u,n);
        if(r==m)
        return q;
        else if(s==m)
        return u;
        else
        return -1;
	} 
```
