#include<iostream>
#include<vector>
/*
    �Ǻ���ġ ��

    ���� ����

    �Ǻ���ġ ���� F(0) = 0, F(1) = 1�� ��, 1 �̻��� n�� ���Ͽ� F(n) = F(n-1) + F(n-2) �� ����Ǵ� �� �Դϴ�.

    �������

        F(2) = F(0) + F(1) = 0 + 1 = 1
        F(3) = F(1) + F(2) = 1 + 1 = 2
        F(4) = F(2) + F(3) = 1 + 2 = 3
        F(5) = F(3) + F(4) = 2 + 3 = 5

    �� ���� �̾����ϴ�.

    2 �̻��� n�� �ԷµǾ��� ��, n��° �Ǻ���ġ ���� 1234567���� ���� �������� �����ϴ� �Լ�, solution�� �ϼ��� �ּ���.
    ���� ����

        n�� 2 �̻� 100,000 ������ �ڿ����Դϴ�.

    ����� ��
    n 	return
    3 	2
    5 	5
    ����� �� ����

    �Ǻ���ġ���� 0��°���� 0, 1, 1, 2, 3, 5, ... �� ���� �̾����ϴ�.
*/

/*
* ù��° �ۼ� ���
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
* �ι�° �ۼ�
* ����Լ� (�ð��ʰ�)
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