#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){ // problema orrendo
    int t; fin >> t;
    for(int f=0; f<t; f++){
        string inp; fin >> inp;
        vector<vector<char>>v(1);
        pair<int,int> pos = {0, 0};
        for(int i=0; i<inp.size(); i++){
            if(inp[i] == '{' || inp[i] == '}') continue;
            if(inp[i] == '<' || inp[i] == '>' || inp[i] == '_' || inp[i] == '^'){
                if(inp[i] == '<'){
                    if(pos.second == 0) continue;
                    pos.second--;
                }
                else if(inp[i] == '>'){
                    if(pos.second >= v[pos.first].size()) continue;
                    pos.second++;
                }
                else if(inp[i] == '_'){
                    if(pos.first == v.size()-1){
                        v.push_back(vector<char>());
                    }
                    pos.first++;
                    pos.second = min((int)v[pos.first].size(), pos.second);
                }
                else{
                    if(pos.first == 0) continue;
                    pos.first--;
                    pos.second = min((int)v[pos.first].size(), pos.second);
                }
            }
            else{
                if(v[pos.first].size() == 0){
                    v[pos.first].push_back(inp[i]);
                }
                else{
                    v[pos.first].insert(v[pos.first].begin() + pos.second, inp[i]);
                }
                pos.second++;
            }
            /*
            cerr << "Case #" << f+1 << ": ";
            cerr << "[";
            for(int e=0; e<v.size(); e++){
                cerr << "[";
                for(auto fi:v[e]){
                    cerr << fi;
                }
                if(e < v.size()-1) cerr << "],";
                else cerr << "]";
            }
            cerr << "]\n";
            */
        }
        if(v.size() == 1){
            fout << "Case #" << f+1 << ": ";
            fout << "[";
            for(int e=0; e<v[0].size(); e++){
                if(e < v[0].size()-1) fout << v[0][e] << ",";
                else fout << v[0][e];
            }
            fout << "]\n";
        }
        else{
            fout << "Case #" << f+1 << ": ";
            fout << "[";
            for(int e=0; e<v.size(); e++){
                fout << "[";
                for(int fi=0; fi<v[e].size(); fi++){
                    if(fi < v[e].size()-1) fout << v[e][fi] <<  ",";
                    else fout << v[e][fi];
                }
                if(e < v.size()-1) fout << "],";
                else fout << "]";
            }
            fout << "]\n";
        }
    }
    return 0;
}