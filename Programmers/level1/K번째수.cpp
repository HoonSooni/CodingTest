// K번째수
// https://school.programmers.co.kr/learn/courses/30/lessons/42748

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;
    
    for (vector<int> command : commands)
    {
        int i = command[0] - 1;
        int j = command[1] - 1;
        int k = command[2] - 1;
        
        vector<int> subArray(j - i + 1);
        for (int l = 0; l < subArray.size(); ++l)
        {
            subArray[l] = array[i + l];
        }
        sort(subArray.begin(), subArray.end());
        
        answer.push_back(subArray[k]);
    }
    
    return answer;
}