// Punti: 100.0
#include<bits/stdc++.h>
#pragma GCC optimize("O2")

void fastscan(int &number){
    int c;
    number = 0;
    c = std::getchar();
    for (; (c>47 && c<58); c=std::getchar())
        number = number *10 + c - 48;
}

int main(){
    int n, m, a, b; fastscan(n); fastscan(m);
    std::vector<std::vector<int>>v(n);
    for(int i=0; i<m; i++){
        fastscan(a); fastscan(b);
        v[a].push_back(b);
    }
    std::vector<bool>vis(n, false);
    std::vector<bool>vis2(n, false);
    std::queue<int>q;
    q.push(0);
    vis[0] = true;
    while(!q.empty()){
        auto pos = q.front();
        q.pop();
        for(int &i:v[pos]){
            if(vis2[i]){
                continue;
            }
            for(int &e:v[i]){
                if(!vis[e]){
                    vis[e] = true;
                    q.push(e);
                }
            }
            vis2[i] = true;
        }
    }
    int tot = 0;
    for(int i:vis){
        tot += i;
    }
    std::cout << tot;
    return 0;
}