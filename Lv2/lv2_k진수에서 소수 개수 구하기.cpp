#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

//n이 소수인지 확인하는 함수
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

    //n을 k진수(string)로 변환
    std::string kNum = "";
    while (n >= 1)
    { 
        kNum += std::to_string(n % k);
        n /= k;
    }
    std::reverse(kNum.begin(), kNum.end());

    //kNum에서 조건에 맞는 수(pNum)를 찾아 소수 판별
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

    //반복을 마치고 마지막에 남은 수가 있는지 체크
    if (!pNum.empty() && isPrime(stoll(pNum))) answer++;

    return answer;
}

int main()
{
    std::cout << solution(437674, 3) << std::endl;
}