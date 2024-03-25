#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

//n�� �Ҽ����� Ȯ���ϴ� �Լ�
bool isPrime(long long n)
{
    if (n < 2) return false;

    for (int i = 2; i <= std::sqrt(n); i++)
    {
        if (n % i == 0) return false;
    }

    return true;
}

int solution(int n, int k)
{
    int answer = 0;

    //n�� k����(string)�� ��ȯ
    std::string kNum = "";
    while (n >= 1)
    { 
        kNum += std::to_string(n % k);
        n /= k;
    }
    std::reverse(kNum.begin(), kNum.end());

    //kNum���� ���ǿ� �´� ��(pNum)�� ã�� �Ҽ� �Ǻ�
    std::string pNum = "";
    for (int i = 0; i < kNum.size(); i++)
    {
        if (kNum[i] == '0' && !pNum.empty())
        {
            if (isPrime(stoll(pNum))) answer++;

            pNum = "";
        }
        else pNum += kNum[i];
    }

    //�ݺ��� ��ġ�� �������� ���� ���� �ִ��� üũ
    if (!pNum.empty() && isPrime(stoll(pNum))) answer++;

    return answer;
}

int main()
{
    std::cout << solution(437674, 3) << std::endl;
}