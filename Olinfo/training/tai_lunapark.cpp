// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int par;
    int size = 1;
    int peso = 0;
    Node(int a){
        par = a;
    }
};
struct DSU{
    vector<Node> dsu;
    vector<int> archi;
    
    DSU(int n): dsu(n, Node(0)) {
        for(int i=0; i<n; i++){
            dsu[i].par = i;
        }
    }
    void onion(int a, int b, int arco){
        int parA = find(a), parB = find(b);
        if(parA == parB) return;
        archi.push_back(arco);
        if(dsu[parA].peso < dsu[parB].peso){
            swap(parA, parB);
        }
        dsu[parB].par = parA;
        dsu[parA].peso += dsu[parB].peso + arco;
        dsu[parA].size += dsu[parA].size;
    }
    int find(int a){
        return (dsu[a].par == a)? a : dsu[a].par = find(dsu[a].par);
    }
};
struct Arco{
    int begin;
    int end;
    int peso;
};
int progetta(int N, int M, int K, vector<int> &A, vector<int> &B, vector<int> &W){
    vector<Arco>gr(M);
    for(int i=0; i<M; i++){
        gr[i] = {A[i] - 1, B[i] - 1, W[i]};
    }
    sort(gr.begin(), gr.end(), [&](Arco a, Arco b) -> bool { return a.peso > b.peso; });
    DSU dsu = DSU(N);
    for(int i=0; i<M; i++){
        dsu.onion(gr[i].begin, gr[i].end, gr[i].peso);
    }
    int sum = 0;
    sort(dsu.archi.begin(), dsu.archi.end());
    for(int i=K-1; i<dsu.archi.size(); i++){
        sum += dsu.archi[i];
    }
    return sum;
}
#ifndef EVAL
int main(){
	int N, M, K;
	cin>>N>>M>>K;
	vector<int> A(M), B(M), W(M);
	for(int i=0;i<M;i++)
		cin>>A[i]>>B[i]>>W[i];
	int score=progetta(N,M,K,A,B,W);
	cout<<score<<endl;
	return 0;
}
#endif