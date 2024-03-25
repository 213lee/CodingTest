#include <string>
#include <vector>
#include <map>
#include <iostream>

#define RANGE 9

int solution(std::vector<std::string> want, std::vector<int> number, std::vector<std::string> discount) {
    int answer = 0;

    std::map<std::string, int> wantNumber;
    for (int i = 0; i < want.size(); i++)
    {
        wantNumber[want[i]] = number[i];
    }

    for (int i = 0; i < discount.size() - RANGE; i++)
    {
        std::map<std::string, int> compareMap = wantNumber;
        int compareIdx = i;
        int lastIdx = i + RANGE;
        for (compareIdx;  compareIdx <= lastIdx; compareIdx++)
        {
            if (!compareMap[discount[compareIdx]]) break;
            
            compareMap[discount[compareIdx]]--;
        }
        if (compareIdx == lastIdx + 1) answer++;
    }
    std::cout << answer;
    return answer;
}

int main()
{
    std::vector<std::string> discount = { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" };
    std::vector<std::string> want = { "banana", "apple", "rice", "pork", "pot" };
    std::vector<int> number = { 3,2,2,2,1 };

    solution(want, number, discount);
}