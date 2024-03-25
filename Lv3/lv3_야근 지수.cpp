#include <vector>
#include <queue>

long long solution(int n, std::vector<int> works) {
    long long answer = 0;

    //works의 작업 목록을 우선순위 큐로 관리.
    std::priority_queue<int> pq_works;
    for (int work : works)
    {
        pq_works.push(work);
    }

    //n을 1씩 사용하면서 우선순위 큐의 top(최댓값)을 1씩 감소시킨다.
    while (n > 0 && !pq_works.empty())
    {
        int top = pq_works.top();
        pq_works.pop();
        n--;
        if (top > 0) pq_works.push(top - 1);
    }

    //우선순위 큐에 남은 항목들의 제곱을 더한다.
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