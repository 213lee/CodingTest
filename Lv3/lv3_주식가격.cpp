#include <string>
#include <vector>
#include <stack>
#include <iostream>

/*2�� for������ ������ �������� �Ⱓ�� ����� Ǯ��*/
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

/*Stack�� ����� Ǯ��*/
std::vector<int> solution(std::vector<int> prices)
{
    std::vector<int> answer(prices.size());     //Stack�� ����� �ε����� ������ �ٷ� ���� �����ϱ� ���� size�� �°� �ʱ�ȭ
    std::stack<int> ansStack;                   //�ε����� ������ Stack
    int size = answer.size();
    for (int i = 0; i < size; i++)
    {
        //Stack�� top�� price���� ũ�ٸ� == �ֽ� ������ �϶�.
        while (!ansStack.empty() && prices[ansStack.top()] > prices[i])
        {
            answer[ansStack.top()] = i - ansStack.top();    //i - ansStack = ������ �������� ���� �Ⱓ
            ansStack.pop();
        }
        
        ansStack.push(i);   //�������� �ֽ� ������ Stack Push
    }
    
    //Stack�� ���� �ִ� �ε��� == ���������� ������ �϶����� ���� �ε���
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