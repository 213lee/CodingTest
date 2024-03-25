#include <string>
#include <vector>


std::vector<int> solution(int n, int s) {
    std::vector<int> answer;

    //최고의 집합이 존재하지 않는 경우
    if (n > s) return { -1 };

    int quotient = s / n;       //몫
    int remainder = s % n;      //나머지

    //곱이 최대가 되기 위해서는 원소의 편차가 가장 작아야 하므로
    //편차가 가장 작도록 몫과 나머지만큼 몫 + 1로 곱했을 때 가장 큰 값을 얻을 수 있음
    for (int i = 0; i < n; i++)
    {
        //n - remainder는 몫(quotient)의 값
        if (n - remainder <= i) answer.push_back(quotient + 1);
        else answer.push_back(quotient);
    }

    int avg{ quotient / 1 };

    return answer;
}

int main()
{
    solution(2, 9);
}