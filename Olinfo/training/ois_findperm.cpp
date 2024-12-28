// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int n;
    cin>>n;
    vector<int> res(n, 0);
    vector<int> toCheck(n);
    vector<bool> checked(n+1);
    for(int i=1; i<=n; i++) toCheck[i-1] = i;
    for(int i=0; i<ceil(log2(n)); i++){
        int pos;
        for(int j=0; j<toCheck.size();j++){
            int a = toCheck[j];
            cout<<"? "<< a <<  " " << a<<endl;
            int r;
            cin>>r;
            if(r==i){
                pos = a;
                break; 
            }
        }
        toCheck.clear();
        for(int k = 1; k<n+1; k++){
            cout<<"? "<< pos <<  " " << k<<endl;
            int r;
            cin>>r;
            if(r==i) {
                res[k-1]+=pow(2,i);
                checked[k] = true;
            }
            else{
                if(!checked[k])toCheck.push_back(k);
            }
        }
    }
    cout<<"! ";
    for(int u:res) cout<<u<<" ";
    cout<<endl;
}