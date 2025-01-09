#include<bits/stdc++.h>
using namespace std;

struct trie {
	trie(bool v) : b(v), v(2, nullptr) {}
	bool b;
	vector<trie*>v;
};

trie t = trie(0);

int main(){
    int n, maxm, xorr; cin >> n;
    maxm = xorr = 0;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        int a; cin >> a;
        v[i] = a; xorr ^= a;

        trie* c = &t;
        int temp = xorr;
        for(int i=30; i>=0; i--){
            unsigned int bit = (xorr & (1 << i)) >> i;
            if(c->v[0] == nullptr && c->v[1] == nullptr)
                break;
            if(c->v[(~bit) & 1] != nullptr){
                temp ^= ((~bit) & 1) << i;
                c = c->v[(~bit) & 1];
            }
            else{
                temp ^= bit << i;
                c = c->v[bit];
            }
        }
        maxm = max(maxm, temp);

        c = &t;
        for(int b=30; b>=0; --b){
            unsigned int bit = (xorr & (1 << b)) >> b;
            if(c->v[bit] == nullptr){
                c->v[bit] = new trie(bit);
            }
            c = c->v[bit];
        }
    }
    cout << max(maxm, xorr);
    return 0;
}