#include <string>
#include <vector>

#define MAXROW 101
#define MAXCOL 101
#define WATER -1

int solution(int m, int n, std::vector<std::vector<int>> puddles) 
{
    int map[MAXROW][MAXCOL] = {};

    map[1][1] = 1;     //���� ��ġ (1, 1)�� 1�� ����
    for (int i = 0; i < puddles.size(); i++) map[puddles[i][0]][puddles[i][1]] = WATER;    //���� ��� ��ġ�� -1�� ��ŷ

    //���� ��ġ���� ������ ����� �� = ����(i - 1) + ��(j - 1) ����� ��
    for (int i = 1; i <= m; i++)
    {
        for (int j = i == 1 ? 2 : 1; j <= n; j++)
        {
            if (map[i][j] == WATER) continue;
            
            //int sum = (map[i - 1][j] == WATER ? 0 : map[i - 1][j]) + (map[i][j - 1] == WATER ? 0 : map[i][j - 1]);
            map[i][j] = ((map[i - 1][j] == WATER ? 0 : map[i - 1][j]) + (map[i][j - 1] == WATER ? 0 : map[i][j - 1])) % 1000000007;
        }
    }

    return map[m][n];
}

int main()
{
    std::vector<std::vector<int>> puddles = { {2,2} };

    printf("%d", solution(4, 3, puddles));
}