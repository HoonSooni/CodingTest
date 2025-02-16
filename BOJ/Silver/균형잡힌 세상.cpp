// 4949. 균형잡힌 세상
// https://www.acmicpc.net/problem/4949

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while (true) {
        stack<char> pars;
        bool isPaired = true;
        string line;
        getline(cin, line);
        
        if (line == ".") { break; }
        
        for (const char l : line) {
            if (l == '(' || l == '[') { pars.push(l); }
            else if (l == ')') {
                if (pars.empty() || pars.top() != '(') {
                    isPaired = false; break;
                }
                pars.pop();
            } else if (l == ']') {
                if (pars.empty() || pars.top() != '[') {
                    isPaired = false; break;
                }
                pars.pop();
            }
        }
        
        if (!pars.empty()) { isPaired = false; }
        string yesorno = isPaired ? "yes" : "no";
        cout << yesorno << "\n";
    }
}
