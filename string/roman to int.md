- We map the roman number to their interger value some of them are of lenght 2, while other of 1 
- So we start with taking subset of length of 2, if that subset is not in our map, then we know it must be length one roman value
~~~cpp
int romanToInt(string s) {
        unordered_map<string,int> mp = {{"I",1}, {"IV",4}, {"V",5}, {"IX",9}, {"X",10}, {"XL",40},  {"L",50}, {"XC",90}, {"C",100}, {"CD",400}, {"D",500}, {"CM",900}, {"M",1000}};
        
        int i = 0;
        int ans = 0;
        while(i<s.size()){
            string t = s.substr(i,2);
            if(mp.find(t)==mp.end()){
                t = s.substr(i,1);
                ans = ans + mp[t];
                i++;
                continue;
            }
            ans = ans + mp[t];
            i=i+2;
        }
        return ans;
    }
~~~
