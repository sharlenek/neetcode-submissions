class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        # do i pop the stack
        #   so pop every number thats smaller but how do i keep track of the index
        #pairs with index? 
        stack = []
        result = [0]*len(temperatures)

        for i in range(len(temperatures)):

            while stack and temperatures[stack[-1]] < temperatures[i]:
                index = stack.pop()
                result[index] = i - index

            stack.append(i)

        return result
                
            
            


            





        