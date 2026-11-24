class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashmap = defaultdict(list)

        for s in strs:
            frequency = [0]*26
            for char in s:
                frequency[ord(char) - ord('a')]+=1

            key = tuple(frequency)
            hashmap[key].append(s)

        return list(hashmap.values())

        