class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        long long int num=0;
        for(int i=0;i< grid.size(); i++){
        	for(int j=0;j<grid[0].size();j++){
        		if(grid[i][j]=='1'){
        			num+=dfs(grid,i,j, grid.size(), grid[0].size());
        		}
        	}
        }
        return num;
    }

    int dfs(vector<vector<char>>& grid, int i, int j, int rows, int columns){
    	if(i< 0 || i>= rows || j<0 || j>=columns){
    		return 0;
    	}
    	else{
    		if(grid[i][j]=='1'){
	    		grid[i][j]='0';
	    		dfs(grid,i+1,j, rows, columns);
	    		dfs(grid,i-1,j, rows, columns);
	    		dfs(grid,i,j+1, rows, columns);
	    		dfs(grid,i,j-1, rows, columns);
    		}
    	}
        return 1;
        
    }
};