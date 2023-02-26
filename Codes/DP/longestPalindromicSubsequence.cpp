
// ITERATIVE
// int Solution::solve(string A) {
//     int dp[1010][1010];
//     string B=A;
//     reverse(B.begin(),B.end());
//     int n = A.length();

//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=n;j++){
//             if(i==0 ||j==0){
//                 dp[i][j]=0;
//                 continue;
//             }
//             if(A[i-1]==B[j-1]){
//                 dp[i][j]=1+dp[i-1][j-1];
//             }else{
//                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//     }

//     return dp[n][n];
// }



// Space optimised Iterative
// int Solution::anytwo(string A) {
//     string B=A;
//     int n=A.size();
//     vector<int> dp(n+1,0);
//     for(int i=1;i<=n;i++){
//         vector<int> temp(n+1,0);
//         for(int j=0;j<=n;j++){
//             if(A[i-1]==B[j-1] && i!=j){
//                 temp[j]=1+dp[j-1];
//             }else{
//                 temp[j]=max(dp[j],temp[j-1]);
//             }
//         }
//         dp=temp;
//     }
//     if(dp[n]>1) return 1;
//     return 0;
// }
