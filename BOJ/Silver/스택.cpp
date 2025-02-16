// 10828 스택
// https://www.acmicpc.net/problem/10828

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

const int s = 100005;
int st[s];
int pos = 0;

void push(int num) {
    st[pos++] = num;
}

void top() {
    if (pos > 0) { cout << st[pos - 1] << "\n"; }
    else { cout << -1 << "\n"; }
}

void pop() {
    top();
    if (pos > 0) { pos--; }
}

void size() {
    cout << pos << "\n";
}


void empty() {
    cout << (pos == 0) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int opNum = 0;
    cin >> opNum;
    
    while (opNum--) {
        string op;
        cin >> op;
        
        if (op == "push") {
            int num;
            cin >> num;
            push(num);
        }
        else if (op == "top") { top(); }
        else if (op == "empty") { empty(); }
        else if (op == "pop") { pop(); }
        else if (op == "size") { size(); }
    }
    
    return 0;
}
