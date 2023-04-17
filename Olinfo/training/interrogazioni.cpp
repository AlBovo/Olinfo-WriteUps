// Punti: 100.0
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int mini = INT_MAX-1, N, K; fin >> N >> K;
    int arr[N];

    for(int i=0; i<N; i++) fin >> arr[i];
    sort(arr, arr+N, greater<int>());

    for(int i=0; i<=N-K; i++)
    {
        mini = min(arr[i] - arr[i+K-1], mini);
    }

    fout << mini;
    return 0;
}