#### Storing individual words of string
```cpp
string reverseWords(string s) {
        string a = "";int flag = 0;int l = -1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' ' && flag==0) {l=-1;continue;}
            else if(s[i]==' '){
                if(a!="")
                a = a + " " + s.substr(i+1,l-(i+1)+1);
                else a = a + s.substr(i+1,l-(i+1)+1);
                l=-1;
                flag = 0;
            }else if(flag==0){
                flag=1;
                l = i;
            }
        }
        if(l>=0)
            if(a!="")
                a=a+" "+s.substr(0,l+1);
            else
                a=a+s.substr(0,l+1);
        return a;
    }
```
