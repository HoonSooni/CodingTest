// 제일 작은 수 제거하기
// https://school.programmers.co.kr/learn/courses/30/lessons/12935

#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    pair<int, int> smallest = {INT_MAX, -1};
    
    for (int i = 0; i < arr.size(); ++i)
    {
        if (smallest.first > arr[i]) 
        { 
            smallest.first = arr[i]; 
            smallest.second = i;
        }
    }
    
    arr.erase(arr.begin() + smallest.second);
    
    return !arr.empty() ? arr : vector<int>{-1};
}