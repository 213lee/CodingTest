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

    //가로의 길이가 n일 때 n X 2의 직사각형을 모두 채우는 경우의 수는 n - 1일 때, n - 2일 때 경우의 합과 같다.
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