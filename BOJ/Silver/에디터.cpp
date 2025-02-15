// 1406. 에디터
// https://www.acmicpc.net/problem/1406

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    list<char> str;
    int operationNum = 0;
    
    string input;
    cin >> input;
    
    for (char letter : input) {
        str.push_back(letter);
    }
    
    cin >> operationNum;
    
    list<char>::iterator cursor = str.end();
    while (operationNum--) {
        char operation;
        cin >> operation;
        
        if (operation == 'P') {
            char letter;
            cin >> letter;
            
            str.insert(cursor, letter);
        } else if (operation == 'B') {
            if (cursor != str.begin()) {
                cursor--;
                cursor = str.erase(cursor);
            }
        } else if (operation == 'D') {
            if (cursor != str.end()) { cursor++; }
        } else {
            if (cursor != str.begin()) { cursor--; }
        }
    }
    
    for (char letter : str) {
        cout << letter;
    }
    return 0;
}
