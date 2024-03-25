/*
* 
* �� ���� �ּҰ����(Least Common Multiple)�� �Էµ� �� ���� ��� �� ������ �Ǵ� ���� ���� ���ڸ� �ǹ��մϴ�. 
���� ��� 2�� 7�� �ּҰ������ 14�� �˴ϴ�. ���Ǹ� Ȯ���ؼ�, n���� ���� �ּҰ������ n ���� ������ ��� �� ������ �Ǵ� ���� ���� ���ڰ� �˴ϴ�.
n���� ���ڸ� ���� �迭 arr�� �ԷµǾ��� �� �� ������ �ּҰ������ ��ȯ�ϴ� �Լ�, solution�� �ϼ��� �ּ���.

���� ����
arr�� ���� 1�̻�, 15������ �迭�Դϴ�.
arr�� ���Ҵ� 100 ������ �ڿ����Դϴ�.

����� ��
arr				result
[2,6,8,14] 		168
[1,2,3] 		6

*/


/*
* ù��° �ۼ��� ���
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
        //n�� ���μ�����
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

        //���μ� ���� �ִ� ��� map�� �ִ� ����
        for (pair<int, int> k : tmpPrimeFactor)
        {
            if (primeFactorMap.find(k.first) == primeFactorMap.end()
                || primeFactorMap[k.first] < k.second)
            {
                primeFactorMap[k.first] = k.second;
            }
        }
    }

    //���μ� ���� �ִ� ��� first^second�� �� ���
    for (pair<int, int> k : primeFactorMap)
    {
        answer *= pow(k.first, k.second);
    }

    return answer;
}

*/

#include<iostream>
#include<vector>

//�� ���� �ִ�����(GCD)�� ��ͷ� ���ϴ� �Լ�
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
    //arr�� �տ������� �ּҰ������ ���س�����.
	for (int i = 1; i < size; i++)
	{
        //a, b�� �ּҰ����(LCM) = a * b / a, b�� �ִ�����(GCD)
		LCM = LCM * arr[i] / GCD(LCM, arr[i]);
	}

	return LCM;
}

int main()
{

}