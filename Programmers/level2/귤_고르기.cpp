// 귤 고르기 
// https://school.programmers.co.kr/learn/courses/30/lessons/138476

#include <string>
#include <vector>
#include <algorithm>
#include <map> 

using namespace std;

int solution(int k, vector<int> tangerine) 
{
    int answer = 0;
    map<int, int> sizes;
    
    for (int size : tangerine)
    {
       	if (sizes.find(size) == sizes.end()) { sizes[size] = 1; }
        else { sizes[size] += 1; }
    }
    
    vector<pair<int, int>> temp(sizes.begin(), sizes.end());
    
    sort(temp.begin(), temp.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    
    int i = temp.size() - 1;
    while (k > 0) 
    {
        k -= temp[i--].second;
        answer++;
    }
    
    return answer;
}