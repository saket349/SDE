#### Steps:
- Calculate the hash value for the pattern
- Calculte the Hash for the 1st window in text
- Repeat the following-
- - If the Hash(pattern) == Hash(text) then match characters onr by one
- - Subtract leftmost (MSB) from the hash value of window
- - Shift the window by one character and add the new character

```cpp
```
