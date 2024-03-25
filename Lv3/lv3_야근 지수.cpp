#include <vector>
#include <queue>

long long solution(int n, std::vector<int> works) {
    long long answer = 0;

    //works�� �۾� ����� �켱���� ť�� ����.
    std::priority_queue<int> pq_works;
    for (int work : works)
    {
        pq_works.push(work);
    }

    //n�� 1�� ����ϸ鼭 �켱���� ť�� top(�ִ�)�� 1�� ���ҽ�Ų��.
    while (n > 0 && !pq_works.empty())
    {
        int top = pq_works.top();
        pq_works.pop();
        n--;
        if (top > 0) pq_works.push(top - 1);
    }

    //�켱���� ť�� ���� �׸���� ������ ���Ѵ�.
    while (!pq_works.empty())
    {
        answer += pq_works.top() * pq_works.top();
        pq_works.pop();
    }


    return answer;
}

int main()
{
    solution(4, { 4,3,3 });
}