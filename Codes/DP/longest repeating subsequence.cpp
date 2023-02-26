// int Solution::anytwo(string A) {
//     string B=A;
//     int dp[1010][1010];
//     int n=A.size();
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=n;j++){
//             if(i==0||j==0){
//                 dp[i][j]=0;
//                 continue;
//             }
//             if(A[i-1]==B[j-1] && i!=j){
//                 dp[i][j]=1+dp[i-1][j-1];
//             }else{
//                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//     }
//     if(dp[n][n]>1) return 1;
//     return 0;
// }
