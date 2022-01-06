- [question link](https://leetcode.com/problems/car-pooling/)
- this is a array difference question

```
There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trip[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.
```

```cpp
bool carPooling(vector<vector<int>>& trips, int capacity) {
        int from=0,to=0,tcp=0;
        vector<int> dis(maxDistance,0);
        for(int i=0; i<trips.size(); i++){

            dis[trips[i][1]] += trips[i][0];  // from 
            dis[trips[i][2]] += -trips[i][0]; // to
        }
        tcp=0;
        for(int i=0; i<maxDistance; i++){
            tcp += dis[i];
            if(tcp > capacity)
                return false;
        }
        return true;
        }
```
