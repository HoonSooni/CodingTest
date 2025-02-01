// 가장 가까운 같은 글자
// https://school.programmers.co.kr/learn/courses/30/lessons/142086

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) 
{
    vector<int> answer;
    unordered_map<char, int> track;
    
    for (int i = 0; i < s.size(); ++i)
    {
        const char temp = s[i];
        
        if (track.find(temp) == track.end())
        {
            track.insert({temp, i});
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(i - track[temp]);
            track[temp] = i;
        }
    }
    
    return answer;
}