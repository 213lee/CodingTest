#include <string>
#include <vector>
#include <queue>
#include <iostream>

int solution(std::vector<int> scoville, int K) 
{
    int answer = 0;

    //priority Queue �ʱ�ȭ ��� (�ڷ���, ����ü, �񱳿�����)
    std::priority_queue<int, std::vector<int>, std::greater<int>> pScoville(scoville.begin(), scoville.end());

    //Scoville�� 2�� �̻� �����ϸ鼭 �ּ� ���ں��� K�̻��϶����� �ݺ�
    while (pScoville.size() > 1 && pScoville.top() < K)
    {
        int mixScoville = pScoville.top(); pScoville.pop();
        mixScoville += pScoville.top() * 2; pScoville.pop();
        pScoville.push(mixScoville);
        answer++;
    }

    //��� ��� ������ �������� ���ϴ� ���.
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