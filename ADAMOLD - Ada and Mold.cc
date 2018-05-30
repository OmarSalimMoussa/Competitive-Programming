#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
ll inf = 1LL << 62;
ll mod = 1000000007;

using namespace std;

ll z[5001][5001];
ll dp[5001][5001];
int a[5001];
int n;

ll getsum(int i, int j){
  return (z[i][i] - z[j][i] - z[i][j] + z[j][j])/2;
}

void solve(int i, int lo, int hi, int left, int right){
  int mid = (lo+hi)/2, opt = left;
  dp[i][mid] = inf;
  ll val;
  for(int k=left ; k<=right ; k++){
    val = dp[i-1][k] + getsum(k-1, mid-1);
    if(val < dp[i][mid]){
      dp[i][mid] = val;
      opt = k;
    }
  }
  if(lo <= mid-1) solve(i, lo, mid-1, left, opt);
  if(hi >= mid+1) solve(i, mid+1, hi, opt, right);
}

int main(void){
  int k;
  scanf(" %i %i", &n, &k);
  for(int i=1 ; i<=n ; i++){
    scanf(" %i", &a[i]);
  }
  for(int i=1 ; i<=n ; i++){
    for(int j=1 ; j<=n ; j++){
      z[i][j] = a[i]^a[j];
      z[i][j] += z[i-1][j] + z[i][j-1] - z[i-1][j-1];
    }
  }
  for(int j=1 ; j<=n ; j++)
    dp[0][j] = getsum(j-1, n);
  for(int i=1 ; i <= k ; i++){
    solve(i, 1, n, 1, n);
  }
  cout << dp[k][1] << endl;
  return 0;
}
