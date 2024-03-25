/*
자연수 n이 주어졌을 때, n의 다음 큰 숫자는 다음과 같이 정의 합니다.

    조건 1. n의 다음 큰 숫자는 n보다 큰 자연수 입니다.
    조건 2. n의 다음 큰 숫자와 n은 2진수로 변환했을 때 1의 갯수가 같습니다.
    조건 3. n의 다음 큰 숫자는 조건 1, 2를 만족하는 수 중 가장 작은 수 입니다.

예를 들어서 78(1001110)의 다음 큰 숫자는 83(1010011)입니다.

자연수 n이 매개변수로 주어질 때, n의 다음 큰 숫자를 return 하는 solution 함수를 완성해주세요.
제한 사항

    n은 1,000,000 이하의 자연수 입니다.

입출력 예
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

    //a. 2진수에서 1의 개수를 체크하는 함수를 사용하는 방법.
    //int nextNum = n + 1;
    //int oneCount = BinaryOneCount(n);
    //while (BinaryOneCount(nextNum) != oneCount) nextNum++;
    //return nextNum;

    //b. bitset 라이브러리를 사용해 다음 수에서 1의 개수를 확인하는 방법.
    int num = std::bitset<20>(n).count();

    while (num != std::bitset<20>(++n).count());

    return n;
}

int main()
{
    std::cout << solution(15) << std::endl;
}