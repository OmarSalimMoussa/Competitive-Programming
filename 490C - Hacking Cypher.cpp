#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define over LONG_LONG_MAX
ll inf = 1LL << 60;
ll mod = 1000000007;
double pi = acos(-1.0);

using namespace std;
int in[1000010];
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s;
  int a,b;
  cin >> s >> a >> b;
  int acc = 0;
  for(int i=0 ; i<s.length() ; i++){
    acc*=10;
    acc+=s[i]-'0';
    acc%=a;
    in[i] = (acc == 0);
  }
  int ex = 1;
  acc = 0;
  bool check = false;
  for(int i=s.length()-1 ; i>0 ; i--){
    acc+=ex*(s[i]-'0');
    if(s[i]-'0') check = true;
    acc%=b;
    ex*=10;
    ex%=b;
    if(!acc && in[i-1] && check){
      cout << "YES\n";
      cout << s.substr(0, i) << endl;
      cout << s.substr(i, s.length()-i+1);
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
