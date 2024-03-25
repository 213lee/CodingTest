#include <string>
#include <vector>
#include <queue>
#include <iostream>

int solution(std::vector<int> scoville, int K) 
{
    int answer = 0;

    //priority Queue 초기화 방식 (자료형, 구현체, 비교연산자)
    std::priority_queue<int, std::vector<int>, std::greater<int>> pScoville(scoville.begin(), scoville.end());

    //Scoville이 2개 이상 존재하면서 최소 스코빌이 K이상일때까지 반복
    while (pScoville.size() > 1 && pScoville.top() < K)
    {
        int mixScoville = pScoville.top(); pScoville.pop();
        mixScoville += pScoville.top() * 2; pScoville.pop();
        pScoville.push(mixScoville);
        answer++;
    }

    //모두 섞어도 조건을 만족하지 못하는 경우.
    if (pScoville.size() <= 1 && pScoville.top() < K) answer = -1;

    std::cout << answer << std::endl;

    return answer;
}

int main()
{
    std::vector<int> scoville = { 1,2,3,9,10,12 };
    int k = 7;
    solution(scoville, 7);
}