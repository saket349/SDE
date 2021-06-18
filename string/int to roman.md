- It similar to  
```cpp
string intToRoman(int num) {
        string roman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int integer[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int i = 0;
        string a = "";
        for(int i=0;i<13;i++){
            int n = num/integer[i];
            num = num%integer[i];
            while(n--){
                a=a+roman[i];
            }
        }
        return a;
    }
```
