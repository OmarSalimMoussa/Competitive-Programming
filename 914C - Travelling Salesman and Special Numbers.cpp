#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define over LONG_LONG_MAX
ll inf = 1LL << 60;
ll mod = 1000000007;
double pi = acos(-1.0);

using namespace std;
string s;
int C[1010][1010];
int p[1010];
void binomialCoeff(int n, int k){
  int i, j;
  for (i = 0; i <= n; i++){
    for (j = 0; j <= min(i, k); j++){
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = (C[i-1][j-1]%mod + C[i-1][j]%mod)%mod;
    }
  }
}
int find_msb(int pos){
  for(int i=pos; i<s.length() ; i++) if(s[i] == '1') return i;
  return -1;
}

ll f(int pos, int k, int msb){
  if(msb < pos) msb = find_msb(pos);
  if(k-1 > s.length() - msb - 1 || msb == -1) return 0;
  else return (C[s.length() - msb - 1][k] + f(msb+1, k-1,msb))%mod;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int k;
  cin >> s >> k;
  binomialCoeff(1001,1001);
  for(int i=1 ; i<=1000 ; i++){
    int x = i;
    while(x != 1){
      p[i]++;
      x = __builtin_popcount(x);
    }
    p[i]++;
  }
  ll ans = 0;
  int acc = 0;
  for(int i=0 ; i<s.length() ; i++){
    acc += (s[i] == '1');
  }
  for(int i=1 ; i<=1000 ; i++){
    if(p[i] == k) ans+=(f(0, i, 0) + (acc >= i && i != 1))%mod;
  }
  if(k == 0) cout << 1;
  else if(s == "1") cout << 0;
  else cout << ans%mod;
  return 0;
}
