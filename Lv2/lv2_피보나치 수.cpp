#include<iostream>
#include<vector>
/*
    피보나치 수

    문제 설명

    피보나치 수는 F(0) = 0, F(1) = 1일 때, 1 이상의 n에 대하여 F(n) = F(n-1) + F(n-2) 가 적용되는 수 입니다.

    예를들어

        F(2) = F(0) + F(1) = 0 + 1 = 1
        F(3) = F(1) + F(2) = 1 + 1 = 2
        F(4) = F(2) + F(3) = 1 + 2 = 3
        F(5) = F(3) + F(4) = 2 + 3 = 5

    와 같이 이어집니다.

    2 이상의 n이 입력되었을 때, n번째 피보나치 수를 1234567으로 나눈 나머지를 리턴하는 함수, solution을 완성해 주세요.
    제한 사항

        n은 2 이상 100,000 이하인 자연수입니다.

    입출력 예
    n 	return
    3 	2
    5 	5
    입출력 예 설명

    피보나치수는 0번째부터 0, 1, 1, 2, 3, 5, ... 와 같이 이어집니다.
*/

/*
* 첫번째 작성 답안
* DP
    #include <string>
    #include <vector>

    using namespace std;

    int solution(int n) {

        vector<int> vecFibonacci;
        vecFibonacci.push_back(0);      //F(0) = 0
        vecFibonacci.push_back(1);      //F(1) = 1

        for (int i = 2; i <= n; i++)
        {
            int sum = vecFibonacci[i - 2] + vecFibonacci[i - 1];
            if (sum >= 1234567) sum -= 1234567;
            vecFibonacci.push_back(sum);
        }

        return vecFibonacci[n];
    }
*/

/*
* 두번째 작성
* 재귀함수 (시간초과)
* 
    int Fibonacci(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }
        else
        {
            return Fibonacci(n - 1) + Fibonacci(n - 2);
        }
    }

    int solution(int n)
    {
        return Fibonacci(n) % 1234567;
    }

*/

int solution(int n)
{
    if (n < 2) return n;

    std::vector<int> vecFibonacci(n + 1);
    vecFibonacci[0] = 0;
    vecFibonacci[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        vecFibonacci[i] = (vecFibonacci[i - 1] + vecFibonacci[i - 2]) % 1234567;
    }

    return vecFibonacci[n] % 1234567;
}


int main()
{
	std::cout << solution(5) << std::endl;
}