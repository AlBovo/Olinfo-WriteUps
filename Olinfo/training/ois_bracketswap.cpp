// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    string s; cin >> s;

    stack<int> st;
    for (int i = 0; i < N; ++i)
        if (s[i] == '(')
            st.push(i);

    vector<pair<int, int>> sol;

    int cnt = 0;
    for (int i = 0; i < N; ++i){
        if (cnt == 0 && s[i] == ')'){
            s[st.top()] = ')';
            sol.push_back({i, st.top()});
            st.pop();
            ++cnt;
        }
        else if (s[i] == '(')
            ++cnt;
        else
            --cnt;
    }

    cout << sol.size() << endl;
    for (auto i : sol)
        cout << i.first << " " << i.second << '\n';
}