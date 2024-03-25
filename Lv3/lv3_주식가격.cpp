#include <string>
#include <vector>
#include <stack>
#include <iostream>

/*2중 for문으로 각각의 시점에서 기간을 계산한 풀이*/
//std::vector<int> solution(std::vector<int> prices)
//{
//    std::vector<int> answer;
//    for (int i = 0; i < prices.size(); i++)
//    {
//        int ans = 0;
//        for (int j = i + 1; j < prices.size(); j++)
//        {
//            ans++;
//            if (prices[i] > prices[j]) break;
//        }
//        answer.push_back(ans);
//    }
//    return answer;
//}

/*Stack을 사용한 풀이*/
std::vector<int> solution(std::vector<int> prices)
{
    std::vector<int> answer(prices.size());     //Stack을 사용해 인덱스에 접근해 바로 값을 수정하기 위해 size에 맞게 초기화
    std::stack<int> ansStack;                   //인덱스를 가지는 Stack
    int size = answer.size();
    for (int i = 0; i < size; i++)
    {
        //Stack의 top이 price보다 크다면 == 주식 가격이 하락.
        while (!ansStack.empty() && prices[ansStack.top()] > prices[i])
        {
            answer[ansStack.top()] = i - ansStack.top();    //i - ansStack = 가격이 떨어지지 않은 기간
            ansStack.pop();
        }
        
        ansStack.push(i);   //현시점의 주식 가격을 Stack Push
    }
    
    //Stack의 남아 있는 인덱스 == 마지막까지 가격이 하락되지 않은 인덱스
    while (!ansStack.empty())
    {
        answer[ansStack.top()] = size - ansStack.top() - 1;
        ansStack.pop();
    }

    return answer;
}

void Print(const std::vector<int>& vec)
{
    for (int v : vec)
    {
        std::cout << v;
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> prices = { 1,2,3,2,3 };

    Print(solution(prices));
}