class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        #frequency array or hashmap
        frequency = defaultdict(int)

        left = 0
        length = 0
        for i in range(len(s)):
            frequency[s[i]]+=1
            while frequency[s[i]] > 1:
                frequency[s[left]]-=1
                left+=1
        
            if i-left+1 > length:
                length = i-left+1

        return length


        