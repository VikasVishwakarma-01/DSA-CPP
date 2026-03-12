class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        n = x
        r = 0
        while n > 0:
            d = n % 10
            r = r * 10
            r = r + d
            n = n // 10
        
        if r == x:
            return True
        return False   