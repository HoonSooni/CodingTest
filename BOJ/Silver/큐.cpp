// 10845 큐
// https://www.acmicpc.net/problem/10845

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include <list>
#include <stack>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

const int mx = 100000;
int q[mx];
int top = 0, bottom = 0;

void push(int num) {
    q[top++] = num;
}

void pop() {
    if (bottom == top) { cout << -1 << "\n"; }
    else { cout << q[bottom++] << "\n"; }
}

void front() {
    if (bottom == top) { cout << -1 << "\n"; }
    else { cout << q[bottom] << "\n"; }
}

void back() {
    if (bottom == top) { cout << -1 << "\n"; }
    else { cout << q[top - 1] << "\n"; }
}

void size() {
    cout << top - bottom << "\n";
}

void empty() {
    if (bottom == top) { cout << 1 << "\n"; }
    else { cout << 0 << "\n"; }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int opNum;
    cin >> opNum;
    
    while (opNum--) {
        string op;
        cin >> op;
        
        if (op == "push") {
            int num; cin >> num;
            
            push(num);
        } else if (op == "pop") { pop(); }
        else if (op == "size") { size(); }
        else if (op == "front") { front(); }
        else if (op == "back") { back(); }
        else if (op == "empty") { empty(); }
    }
}
