#include <string>
#include <vector>

#define MOD 1000000007

int solution(int n) {
    int answer;

    /*int* Arr = new int[n];

    Arr[0] = 1;
    Arr[1] = 2;*/

    int a = 1;
    int b = 2;

    //������ ���̰� n�� �� n X 2�� ���簢���� ��� ä��� ����� ���� n - 1�� ��, n - 2�� �� ����� �հ� ����.
    for (int i = 2; i < n; i++)
    {
        answer = a + b % MOD;
        a = b;
        b = answer;
        /*int a = Arr[i - 1] + Arr[i - 2];

        Arr[i] = a < MOD ? a : a - MOD;*/
    }

    //answer = Arr[n - 1];
    //delete[] Arr;

    return answer;
}

int main()
{
    printf("%d", solution(5));
}