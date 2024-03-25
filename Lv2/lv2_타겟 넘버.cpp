#include <string>
#include <vector>
#include <iostream>

//재귀로 깊이 우선 탐색
//마지막 노드까지의 합이 target과 같다면 1을 반환
int RecursiveDFS(const std::vector<int>& numbers, int target, int index, int sum)
{
    if (index == numbers.size())
    {
        if (sum == target) return 1;
        else return 0;
    }

    return RecursiveDFS(numbers, target, index + 1, sum + numbers[index]) + RecursiveDFS(numbers, target, index + 1, sum - numbers[index]);
}


int solution(std::vector<int> numbers, int target) 
{
    return RecursiveDFS(numbers, target, 0, 0);
}

int main()
{
    std::cout << solution({ 4, 1, 2, 1}, 4) << std::endl;
}