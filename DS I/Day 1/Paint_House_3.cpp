class Solution {
public:
    int dp[102][102][22];
    int solve(vector<vector<int>>& cost, vector<int>& houses, int target, int i, int prev){
        if(i < 0 || target < 0) return target == 0?0:INT_MAX/2;
        if(dp[i][target][prev]!=-1) return dp[i][target][prev];
        
        int res = INT_MAX/2;
        int t = target;
        if(houses[i] != 0)
        {
            t = (houses[i] != prev)? target -1: target;  
            res = solve(cost, houses, t, i-1, houses[i]);
        }
        else
        {
            for(int c = 1; c <= cost[i].size(); ++c){
                t = (c != prev) ? target -1: target;
                res = min( res, cost[i][c-1] + solve(cost, houses, t,  i-1, c));
            }
        }
        return dp[i][target][prev] = res;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        auto ans = solve(cost, houses, target, m-1, 0); 
        return ans >= INT_MAX/2?-1:ans;
    }
};