class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //width is always 1
        // i think u have to keep track of the lowest height, 
         
        int maxarea = 0;
        int poppedarea;
        int poppedindex;
        stack<vector<int>> stk;

        heights.push_back(0);

        for (int i = 0; i < heights.size(); ++i){
            if (stk.empty()){
                stk.push({i, heights[i]});
            } else {
                if (heights[i] >= stk.top()[1]){
                    stk.push({i, heights[i]});
                } else {
                    while (!(stk.empty()) && heights[i] < stk.top()[1]){
                        poppedindex = stk.top()[0];
                        poppedarea = stk.top()[1] * (i - poppedindex);
            
                        if (poppedarea > maxarea){
                            maxarea = poppedarea;
                        }
                        stk.pop();
                    }
                    stk.push({poppedindex, heights[i]});
                }
            }
        }

        int maxindex = stk.top()[0];
        int poppedheight;
       
        return maxarea;
    }
};
