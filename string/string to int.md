```
example 1:
input : "-+45"
output:  0

example2:
input : "-45"
output : 45

example3:
input : "  4 56"
output : 4

example4:
input:  "-45+4"
output : -45

example5:
input : "12 abs"
output:  12

```

```cpp
int myAtoi(string s) {
        int l = 1;
        int ans = 0;
        int mn = -pow(2, 31);
        int mx =  pow(2, 31) - 1;
        bool f = false;
        for(auto i:s){
            
            if(i==' ') {if(f) break; continue; }
            if(i=='-') {if(f) break; f = true; l = -l; continue;}
            if(i=='+') {if(f) break; f = true; l =  l; continue;}
            if((i-'0')<0 || (i-'0')>9) break;
            int z = int(i-'0');
            f = true;
            if(l>0){
                if((mx/10 > ans) || (mx/10 == ans && z<=7)) ans = ans*10 + z;
                else ans = mx;
            }else{
                if((mn/10 < ans) || (mn/10 == ans && z<=8)) ans = ans*10 - z;
                else ans = mn;
            }
        }
        return ans;
    }
```
