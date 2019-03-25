#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define FAST ios::sync_with_stdio(false);cin.tie(0);

ll inf = 1LL << 60;
ll mod = 1000000007;

using namespace std;

class segment_tree{
private:
  struct node{
    int type, on;
  };
  vector<int> v, st;
  vector<node> lazy;
  void build(int p, int l, int r){
    lazy[p] = {0, 0};
    if(l == r){
      st[p] = v[l];
      return;
    }
    build(2*p, l, (l+r)/2);
    build(2*p+1, (l+r)/2+1, r);
    st[p] = st[2*p]+st[2*p+1];
  }
  void resolve(int p, int type){
    if(!lazy[2*p].on){
      lazy[2*p] = lazy[2*p+1] = {type, 1};
    }else if(lazy[2*p].type != 2 && type == 2){
      lazy[2*p] = lazy[2*p+1] = {1-lazy[2*p].type, 1};
    }else if(lazy[2*p].type == 2 && type == 2){
      lazy[2*p] = lazy[2*p+1] = {0, 0};
    }else{
      lazy[2*p] = lazy[2*p+1] = {type, 1};
    }
  }
  void push(int p, int l, int r, int type){
    lazy[p].type = type;
    if(lazy[p].type == 0){
      st[p] = r-l+1;
    }else if(lazy[p].type == 1){
      st[p] = 0;
    }else{
      st[p] = r-l+1-st[p];
    }
    if(l != r) resolve(p, type);
    lazy[p].on = 0;
  }
  void update(int p, int l, int r, int i, int j, int type){
    if(lazy[p].on){
      push(p, l, r, lazy[p].type);
    }
    if(l>j || r<i) return;
    if(l>=i && r<=j){
      push(p, l, r, type);
      return;
    }
    update(2*p, l, (l+r)/2, i, j, type);
    update(2*p+1, (l+r)/2+1, r, i, j, type);
    st[p] = st[2*p]+st[2*p+1];
  }
  int query(int p, int l, int r, int i, int j){
    if(lazy[p].on){
      push(p, l, r, lazy[p].type);
    }
    if(l>j || r<i) return 0;
    if(l>=i && r<=j) return st[p];
    return query(2*p, l, (l+r)/2, i, j) + query(2*p+1, (l+r)/2+1, r, i, j);
  }
public:
  segment_tree(vector<int>& a){
    v = a;
    st.resize(4*v.size()+1);
    lazy.resize(4*v.size()+1);
    build(1, 0, v.size()-1);
  }
  void set(int i, int j){
    update(1, 0, v.size()-1, i, j, 0);
  }
  void reset(int i, int j){
    update(1, 0, v.size()-1, i, j, 1);
  }
  void invert(int i, int j){
    update(1, 0, v.size()-1, i, j, 2);
  }
  int sum(int i, int j){
    return query(1, 0, v.size()-1, i, j);
  }
};

int main(){
  FAST;
  //freopen("in.in", "r", stdin);freopen("out.out", "w", stdout);
  int T, tc = 1;
  cin >> T;
  while(T--){
    cout << "Case " << tc++ << ":" << endl;
    int m, q;
    vector<int> a;
    cin >> m;
    while(m--){
      int t;
      string s;
      cin >> t >> s;
      for(int i=0 ; i<t ; i++){
        for(int j=0 ; j<s.length() ; j++){
          a.push_back(s[j]-'0');
        }
      }
    }
    segment_tree st(a);
    cin >> q;
    int question_count = 1;
    while(q--){
      string command;
      int i, j;
      cin >> command >> i >> j;
      if(command == "F"){
        st.set(i, j);
      }else if(command == "E"){
        st.reset(i, j);
      }else if(command == "I"){
        st.invert(i, j);
      }else{
        cout << "Q" << question_count++ << ": " << st.sum(i, j) << endl;
      }
    }
  }
  return 0;
}
