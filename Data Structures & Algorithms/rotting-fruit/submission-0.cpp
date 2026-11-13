class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0;
        //track every rotten orange
        queue<pair<int, int>> rotten;
        int fresh = 0;
        for (int r = 0; r < grid.size(); ++r){
            for (int c = 0; c < grid[0].size(); ++c){
                if (grid[r][c] == 2){
                    rotten.push({r, c});
                }
                if (grid[r][c] == 1){
                    fresh++;
                }
            }
        }

        while (!rotten.empty() && fresh > 0){
            int size = rotten.size();

            for (int i = 0; i < size; ++i){
                int r = rotten.front().first;
                int c = rotten.front().second;
                rotten.pop();

                // check its neightbors
                vector<int> rowdir = {1, -1, 0, 0};
                vector<int> coldir = {0, 0, 1, -1};

                for (int d = 0; d < 4; ++d){
                    int newr = r + rowdir[d];
                    int newc = c + coldir[d];

                    if (newr >= 0 && newr < grid.size() && newc >= 0 && newc <
                    grid[0].size()){
                        if (grid[newr][newc] == 1){
                            rotten.push({newr, newc});
                            grid[newr][newc] = 2;
                            fresh--;
                        }
                    }
                }

            }
            minutes++;

        }

        if (fresh > 0){
            return -1;
        }
        return minutes;
    }

 
};
