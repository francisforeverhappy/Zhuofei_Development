- [LeetCode](#leetcode)
  - [String and Math](#string-and-math)
  - [Bitwise operation](#bitwise-operation)
  - [Binary Tree Inorder Traversal](#binary-tree-inorder-traversal)
# LeetCode

## String and Math
- 8. String to Integer (atoi)  
Clear writing! Pay attention to the way to handle invalid input(++--1).
```
public static int myAtoi(String str) {
    if (str.isEmpty()) return 0;
    int sign = 1, base = 0, i = 0;
    while (str.charAt(i) == ' ')
        i++;
    if (str.charAt(i) == '-' || str.charAt(i) == '+')
        sign = str.charAt(i++) == '-' ? -1 : 1;
    while (i < str.length() && str.charAt(i) >= '0' && str.charAt(i) <= '9') {
        if (base > Integer.MAX_VALUE / 10 || (base == Integer.MAX_VALUE / 10 && str.charAt(i) - '0' > Integer.MAX_VALUE % 10)) {
            return (sign == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;
        }
        base = 10 * base + (str.charAt(i++) - '0');
    }
    return base * sign;
}
```

## Bitwise operation
- 29. Divide Two Integers  
[Bitwise operation Source](https://blog.csdn.net/xiaochunyong/article/details/7748713)
```
public class Solution {
    public int divide(int dividend, int divisor) {
		if(dividend==Integer.MIN_VALUE && divisor==-1) return Integer.MAX_VALUE;
        if(dividend > 0 && divisor > 0) return divideHelper(-dividend, -divisor);
        else if(dividend > 0) return -divideHelper(-dividend,divisor);
        else if(divisor > 0) return -divideHelper(dividend,-divisor);
        else return divideHelper(dividend, divisor);
    }
    
    private int divideHelper(int dividend, int divisor){
        // base case
        if(divisor < dividend) return 0;
        // get highest digit of divisor
        int cur = 0, res = 0;
        while((divisor << cur) >= dividend && divisor << cur < 0 && cur < 31) cur++;
        res = dividend - (divisor << cur-1);
        if(res > divisor) return 1 << cur-1;
        return (1 << cur-1)+divide(res, divisor);
    }
}
```

## Binary Tree Inorder Traversal
- 94. Binary Tree Inorder Traversal  
  Note: compare my answer with solution, I should formulate my thought firstly.