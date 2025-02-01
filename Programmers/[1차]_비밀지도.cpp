// [1차] 비밀지도
// https://school.programmers.co.kr/learn/courses/30/lessons/17681

#include <iostream>
#include <vector>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string convertIntToMap(int num, int maxLength)
{
    string binary = "";
    
    while (num > 0)
    {
        int remainder = num % 2;
        binary += char(remainder == 1 ? '#' : ' ');
        num /= 2;
    }
    
    for (int size = binary.size(); size < maxLength; ++size)
    {
        binary += ' ';
    }
    
    reverse(binary.begin(), binary.end());
    
    return binary;
}

string performAndCalculation(string num1, string num2)
{
    string result = "";
    
    for (int i = 0; i < num1.size(); ++i)
    {
        if (num1[i] == '#' || num2[i] == '#') { result += '#'; }
        else { result += ' '; }
    }
    
    return result;
}

void printStrs(vector<string> strs)
{
    for (string str : strs)
    {
        cout << str << endl;
    }
    cout << endl;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;
    
    // converting integers into binary string
    vector<string> convertedArr1;
    for (int num : arr1)
    {
        convertedArr1.push_back(convertIntToMap(num, n));
    }
    
    // converting and performing and calculation
    for (int i = 0; i < arr1.size(); ++i)
    {
        string convertedNum = convertIntToMap(arr2[i], n);
        answer.push_back(performAndCalculation(convertedArr1[i], convertedNum));
    }

    return answer;
}

/*
int main()
{
    vector<int> vec1 = {46, 33, 33 ,22, 31, 50};
    vector<int> vec2 = {27, 56, 19, 14, 14, 10};
    vector<string> temp = solution(6, vec1, vec2);
    
    for (string row : temp)
    {
        cout << row << endl;
    }
    
    return 0;
}
*/
