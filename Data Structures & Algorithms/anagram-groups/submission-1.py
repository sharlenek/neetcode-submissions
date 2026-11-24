class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashmap = {}

        for s in strs:
            frequency = [0]*26
            for char in s:
                frequency[ord(char) - ord('a')]+=1

            key = tuple(frequency)

            if key not in hashmap:
                hashmap[key] = []

            hashmap[key].append(s)

        result = []
        for h in hashmap.values():
            result.append(h)
        return result

        