// 부족한 금액 계산하기
// https://school.programmers.co.kr/learn/courses/30/lessons/82612

using namespace std;

long long solution(int price, int money, int count)
{
    long long totalPrice = price;
    
    for (int i = 2; i <= count; ++i)
    {
    	totalPrice += price * i;    
    }
    
    if (totalPrice <= money) return 0;
    else return totalPrice - money;
}