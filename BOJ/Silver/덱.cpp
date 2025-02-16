// 10866 덱
// https://www.acmicpc.net/problem/10866

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

const int mx = 100000;
int dq[2 * mx + 1];
int top = mx, bottom = mx;

// bottom: 3
// top: 3
// 0 0 0  0  0 0 0

// push_back: dq[3], top = 4, bottom = 3
// push_front: dq[2], top = 4, bottom = 2
// pop_front: dq[bottom], top = 4, bottom = 3
// pop_back: dq[top],
void push_front(int num) {
    dq[--bottom] = num;
}
void push_back(int num) {
    dq[top++] = num;
}

void pop_front() {
    if (bottom == top) { cout << -1 << "\n"; }
    else { cout << dq[bottom++] << "\n"; }
}
void pop_back() {
    if (bottom == top) { cout << -1 << "\n"; }
    else { cout << dq[--top] << "\n"; }
}

void front() {
    if (bottom == top) { cout << -1 << "\n"; }
    else { cout << dq[bottom] << "\n"; }
}
void back() {
    if (bottom == top) { cout << -1 << "\n"; }
    else { cout << dq[top - 1] << "\n"; }
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
        
        if (op == "push_back") {
            int num; cin >> num;
            
            push_back(num);
        } else if (op == "push_front") {
            int num; cin >> num;
            
            push_front(num);
        } else if (op == "pop_back") { pop_back(); }
        else if (op == "pop_front") { pop_front(); }
        else if (op == "size") { size(); }
        else if (op == "front") { front(); }
        else if (op == "back") { back(); }
        else if (op == "empty") { empty(); }
    }
}
