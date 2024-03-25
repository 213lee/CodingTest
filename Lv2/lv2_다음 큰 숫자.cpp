/*
�ڿ��� n�� �־����� ��, n�� ���� ū ���ڴ� ������ ���� ���� �մϴ�.

    ���� 1. n�� ���� ū ���ڴ� n���� ū �ڿ��� �Դϴ�.
    ���� 2. n�� ���� ū ���ڿ� n�� 2������ ��ȯ���� �� 1�� ������ �����ϴ�.
    ���� 3. n�� ���� ū ���ڴ� ���� 1, 2�� �����ϴ� �� �� ���� ���� �� �Դϴ�.

���� �� 78(1001110)�� ���� ū ���ڴ� 83(1010011)�Դϴ�.

�ڿ��� n�� �Ű������� �־��� ��, n�� ���� ū ���ڸ� return �ϴ� solution �Լ��� �ϼ����ּ���.
���� ����

    n�� 1,000,000 ������ �ڿ��� �Դϴ�.

����� ��
n 	result
78 	83
15 	23
*/

#include<iostream>
#include<bitset>


int BinaryOneCount(int n)
{
    int counter = 0;

    while (n > 0)
    {
        if (n % 2 != 0) counter++;
        n /= 2;
    }

    return counter;
}

int solution(int n) {

    //a. 2�������� 1�� ������ üũ�ϴ� �Լ��� ����ϴ� ���.
    //int nextNum = n + 1;
    //int oneCount = BinaryOneCount(n);
    //while (BinaryOneCount(nextNum) != oneCount) nextNum++;
    //return nextNum;

    //b. bitset ���̺귯���� ����� ���� ������ 1�� ������ Ȯ���ϴ� ���.
    int num = std::bitset<20>(n).count();

    while (num != std::bitset<20>(++n).count());

    return n;
}

int main()
{
    std::cout << solution(15) << std::endl;
}