class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        n = len(text)
        mp = {}
        sett = {'b', 'a', 'l', 'o', 'n'}

        for i in range(n):
            if text[i] in sett:
                mp[text[i]] = mp.get(text[i], 0) + 1
        
        s = "balloon"
        m = len(text)//len(s)

        ans = 0
        for i in range(m):
            for j in range(len(s)):
                if s[j] in mp:
                    mp[s[j]] -= 1
                    if(mp[s[j]] == 0):
                        del mp[s[j]]
                else:
                    return ans
            ans += 1

        return ans