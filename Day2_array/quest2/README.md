<h1>Pascal Triangle </h1>
<p><b>Pascal Triangle</b> is a triangular array of the binomial coefficients. Write a function that takes an integer value n as input and prints first n lines of the Pascal’s triangle. Following are the first 6 rows of Pascal’s Triangle.
</p><br>
<h3>Question can be asked like print first five rows of pascal triangle or print seventh row only or print fifth row third element </h3>
<u>
  <li>For finding the value at nth row nd mth column, formula is --------- <sup>n-1</sup>C<sub>m-1</sub>  :panda_face: {time complexity O(N)}</li>
  <li> Now for printing nth row all elements we can use the above formula use it for all elements(nth row means it will have n elements), but the time complexity in worst case will be then O(N<sup>2</sup>). Optimsed approach code is given above {time complexity = O(n),  auxiliary space complexity = O(n)}</li>
  <li>rth element is given by Π<sub>e = 2 </sub> <sup>r</sup>(n-(e-1))</li>
</u>
<br><br>
<p> Problem Statement link : <a href="https://leetcode.com/problems/pascals-triangle/solution/" target="_blank">Go</a></p>
