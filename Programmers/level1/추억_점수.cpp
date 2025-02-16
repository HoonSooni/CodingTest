// 추억 점수
// https://school.programmers.co.kr/learn/courses/30/lessons/176963

#include <iostream>
#include <vector>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int getYearning(vector<string>& nameList, vector<int>& yearningList, string targetName)
{
    for (int i = 0; i < nameList.size(); ++i)
    {
        if (nameList[i] == targetName) { return yearningList[i]; }
    }
    
    return 0;
}

vector<int> solution(vector<string> name,
                     vector<int> yearning,
                     vector<vector<string>> photos)
{
    vector<int> answer;
    
    for (vector<string> photo : photos)
    {
        int result = 0;
        for (string person : photo)
        {
            result += getYearning(name, yearning, person);
        }
        answer.push_back(result);
    }
    
    return answer;
}

/*
int main()
{
    vector<string> name = {"kali", "mari", "don"};
    vector<int> yearning = {11, 1, 55};
    vector<vector<string>> photos = {{"kali", "mari", "don"}, {"pony", "tom", "teddy"}, {"con", "mona", "don"}};
    
    for (int score : solution(name, yearning, photos))
    {
        cout << score << endl;
    }
         
    
    return 0;
}
*/
