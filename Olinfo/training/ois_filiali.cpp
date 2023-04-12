#include<bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int posti, N;
int arr[1000001];

bool trova(int dist){
    int k = 1, utlimo = arr[0];
    for(int i=0; i<N; i++){
        if(arr[i] - utlimo >= dist){
            utlimo = arr[i];
            k++;
        }
    }
    return k >= posti;
}

int main(){
    fin >> N >> posti;
    for(int i=0; i<N; i++) fin >> arr[i];
    int l=0, r = arr[N-1]-1, m = 0;
    while (l < r - 1){
        int m = (l + r) / 2;
        if (trova(m)){
            l = m;
        } 
        else{
            r = m;
        }
    }
    fout << l;
    return 0;
}