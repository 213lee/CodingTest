#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

int solution(std::vector<int> priorities, int location) 
{
    int answer = 0;
    std::queue<std::pair<int, int>> waitQueue; //WaitList(우선순위, 인덱스)를 Queue로 저장

    for (int loc = 0; loc < priorities.size(); loc++)
        waitQueue.push({ priorities[loc], loc });

    //우선순위 리스트를 내림차순으로 정렬하여 WaitList와 비교를 위해 사용
    std::sort(priorities.begin(), priorities.end(), std::greater<>());

    while (!waitQueue.empty())
    {
        //priorities[answer]는 현재 대기목록에서 가장 높은 우선순위
        if (waitQueue.front().first == priorities[answer])
        {
            answer++;
            //우선순위가 같은데 찾고자 하는 인덱스가 맞는지 확인
            if (waitQueue.front().second == location) return answer;
            else waitQueue.pop();
        }
        else
        {
            //우선순위가 낮다면 push
            waitQueue.push(waitQueue.front());
            waitQueue.pop();
        }
    }
    return answer;
}

int main()
{
    std::cout << solution({ 2, 1, 3, 2}, 2) << std::endl;
}