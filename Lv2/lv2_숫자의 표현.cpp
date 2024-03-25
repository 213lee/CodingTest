/*
���� ����

Finn�� ���� ���а��ο� ���� �ֽ��ϴ�. ���� ���θ� �ϴ� Finn�� �ڿ��� n�� ������ �ڿ������ ǥ�� �ϴ� ����� ��������� ����� �˰� �Ǿ����ϴ�. ������� 15�� ������ ���� 4������ ǥ�� �� �� �ֽ��ϴ�.

    1 + 2 + 3 + 4 + 5 = 15
    4 + 5 + 6 = 15
    7 + 8 = 15
    15 = 15

�ڿ��� n�� �Ű������� �־��� ��, ���ӵ� �ڿ������ n�� ǥ���ϴ� ����� ���� return�ϴ� solution�� �ϼ����ּ���.
���ѻ���

    n�� 10,000 ������ �ڿ��� �Դϴ�.

����� ��
n 	result
15 	4
*/

#include <iostream>
#include <string>
#include <vector>

void recursive(int num, int target, int& sum, int& count)
{
    if (sum >= target)
    {
        if(sum == target) count++;
        sum = 0;
        return;
    }
    else
    {
        sum += num;
        recursive(num + 1, target, sum, count);
    }
}

int solution(int n) {
    int answer = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++) recursive(i, n, sum, answer);
    return answer;
}

int main()
{
    std::cout << solution(15) << std::endl;
}