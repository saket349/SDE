<h1>Merge Overlapping Subintervals </h1>
<u>
  <li>First approcah is by sorting(ask if sorted or not, if not then sort on the basis of first value), Then trverse for each value to see if any any other interval merges with it or not (merge condition interval[i][1] > interval[j][1] ) <br>{time complexity = O(NlogN) + O(N^2); Space complexity = O(N)}</li>
</u>
<br><br>
<p> Problem Statement link : <a href="https://leetcode.com/problems/merge-intervals/solution/" target="_blank">Go</a></p>
