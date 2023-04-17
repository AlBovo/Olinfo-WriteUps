// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<long long> calcola(int T, int M, vector<long long> S, vector<long long> P){
    vector<pair<long long, long long>> tot(S.size());
    vector<long long> tot1(S.size());
    tot[0].first = 0; tot[0].second= S[0]; tot1[0] = 0;
    for(int i=1; i<S.size(); i++){
        tot[i].first = tot[i-1].first + (S[i] * i); 
        tot1[i] = tot[i].first;
        tot[i].second= tot[i-1].second + S[i];
    }
    #ifndef EVAL
    for(auto i : tot){
        cout << i.first << " " << i.second << "\n";
    }
    #endif

    vector<long long> t;
    bool fatto;
    long long r, n, t1;
    for(auto i: P){
        int it = upper_bound(tot1.begin(), tot1.end(), i) - tot1.begin();
        fatto = false;
        r = i; n = 1;
        if(it > 0) {
        r -= tot[it-1].first;
        n *= tot[it-1].second;
        }
        else n=0;
        for(long long x=it; x<T; x++){
                if(r <= 0 || x > r){
                    fatto = true;
                    t.push_back(n);
                    break;
                }
                else{
                    if(S[x] * x <= r){
                        n += S[x];
                        r -= S[x] * x;
                    }
                    else{
                        t1 = r / x;
                        r -= x * t1;
                        n += t1;
                    }
                }
            }
            if(!fatto){
                t.push_back(n);
            }
    }
    
        return t;
    }

#ifndef EVAL
int main() {
  ios::sync_with_stdio(false);
  // se preferisci leggere e scrivere da file ti basta decommentare le seguenti
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w",stdout);

  int T, M;
  cin >> T >> M;

  vector<long long> S(T), P(M);

  for (long long &x : S)
    cin >> x;
  for (long long &x : P)
    cin >> x;

  auto R = calcola(T, M, S, P);

  for (long long x : R)
    cout << x << ' ';
  cout << endl;

  return 0;
  }
#endif