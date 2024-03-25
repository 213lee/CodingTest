#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

int solution(std::vector<int> priorities, int location) 
{
    int answer = 0;
    std::queue<std::pair<int, int>> waitQueue; //WaitList(�켱����, �ε���)�� Queue�� ����

    for (int loc = 0; loc < priorities.size(); loc++)
        waitQueue.push({ priorities[loc], loc });

    //�켱���� ����Ʈ�� ������������ �����Ͽ� WaitList�� �񱳸� ���� ���
    std::sort(priorities.begin(), priorities.end(), std::greater<>());

    while (!waitQueue.empty())
    {
        //priorities[answer]�� ���� ����Ͽ��� ���� ���� �켱����
        if (waitQueue.front().first == priorities[answer])
        {
            answer++;
            //�켱������ ������ ã���� �ϴ� �ε����� �´��� Ȯ��
            if (waitQueue.front().second == location) return answer;
            else waitQueue.pop();
        }
        else
        {
            //�켱������ ���ٸ� push
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