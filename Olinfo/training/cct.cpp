#include<bits/stdc++.h>
using namespace std; 

ifstream fin("input.txt");
ofstream fout("output.txt");
int n, m;
vector<vector<int>>ve;
vector<int>v, c;

int trova(int pos, int car){
    if(pos == n-1){
        return car < m ? v[pos] : 0;
    }
    if(car < m){
        if(ve[pos][car] == -1){
            ve[pos][car] = trova(pos+1, car+c[pos])+v[pos];
        }
    }else{
        car = m;    
        if(ve[pos][car] == -1){
            ve[pos][car] = min(trova(pos+1, car+c[pos])+v[pos], trova(pos+1, 0));
        }
    }
    return ve[pos][car];
}

int main(){
    fin >> n >> m;
    v.resize(n); c.resize(n);
    ve.resize(n, vector<int>(m+1, -1));
    for(int &i:v){
        fin >> i;
    }
    for(int &i:c){
        fin >> i;
    }
    fout << trova(0, 0);
    return 0;
}