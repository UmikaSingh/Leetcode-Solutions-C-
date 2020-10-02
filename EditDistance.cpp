class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(), n=word2.size(), i,j;
        
        vector<vector<int>> dp(2,vector<int>(n+1,0));
        
        //base case
        //1st row
        for(i=n-1;i>=0;i--)
            dp[m%2][i]=(n-i);
        
        //1st col
        
        //recursive soln
        //row wise
        for(i=m-1;i>=0;i--){
            dp[i%2][n]=(m-i);
            for(j=n-1;j>=0;j--){
                if(word1[i]==word2[j])
                    dp[i%2][j]=dp[(i+1)%2][j+1];
                else
                    dp[i%2][j]=1+min(dp[(i+1)%2][j+1], min(dp[(i+1)%2][j], dp[i%2][j+1]));
                
            }
        }
        return dp[0%2][0];
    }
};
