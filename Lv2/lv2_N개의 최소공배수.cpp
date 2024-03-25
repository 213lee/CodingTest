/*
* 
* 두 수의 최소공배수(Least Common Multiple)란 입력된 두 수의 배수 중 공통이 되는 가장 작은 숫자를 의미합니다. 
예를 들어 2와 7의 최소공배수는 14가 됩니다. 정의를 확장해서, n개의 수의 최소공배수는 n 개의 수들의 배수 중 공통이 되는 가장 작은 숫자가 됩니다.
n개의 숫자를 담은 배열 arr이 입력되었을 때 이 수들의 최소공배수를 반환하는 함수, solution을 완성해 주세요.

제한 사항
arr은 길이 1이상, 15이하인 배열입니다.
arr의 원소는 100 이하인 자연수입니다.

입출력 예
arr				result
[2,6,8,14] 		168
[1,2,3] 		6

*/


/*
* 첫번째 작성한 답안
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    map<int, int> primeFactorMap;

    for (int n : arr)
    {
        //n의 소인수분해
        map<int, int> tmpPrimeFactor;
        int x = 2;
        while (n != 1)
        {
            if (n % x == 0)
            {
                tmpPrimeFactor[x]++;
                n /= x;
            }
            else x++;
        }

        //소인수 분해 최댓값 결과 map에 최댓값 갱신
        for (pair<int, int> k : tmpPrimeFactor)
        {
            if (primeFactorMap.find(k.first) == primeFactorMap.end()
                || primeFactorMap[k.first] < k.second)
            {
                primeFactorMap[k.first] = k.second;
            }
        }
    }

    //소인수 분해 최댓값 결과 first^second의 곱 계산
    for (pair<int, int> k : primeFactorMap)
    {
        answer *= pow(k.first, k.second);
    }

    return answer;
}

*/

#include<iostream>
#include<vector>

//두 수의 최대공약수(GCD)를 재귀로 구하는 함수
int GCD(int a, int b)
{
	if (b > a)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}

	int remainder = a % b;

	if (remainder == 0)
	{
		return b;
	}
	else
	{
		return GCD(b, remainder);
	}
}


int solution(std::vector<int> arr)
{
	int size = arr.size();
	int LCM = arr[0];
    //arr의 앞에서부터 최소공배수를 구해나간다.
	for (int i = 1; i < size; i++)
	{
        //a, b의 최소공배수(LCM) = a * b / a, b의 최대공약수(GCD)
		LCM = LCM * arr[i] / GCD(LCM, arr[i]);
	}

	return LCM;
}

int main()
{

}