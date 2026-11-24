class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        #heap of pairs?
        # make a hashmap first perhaps

        hashmap = defaultdict(int)
        for i in nums:
            hashmap[i]+=1

        heap = []
        for j in hashmap:
            heapq.heappush(heap, (hashmap[j], j))
            if len(heap) > k:
                heapq.heappop(heap)

        return [num for freq, num in heap]

        




        