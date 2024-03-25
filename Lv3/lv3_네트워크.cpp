#include <string>
#include <vector>
#include <iostream>

void recursiveDelete(int n, int row, std::vector<std::vector<int>>& computers)
{
    for (int col = 0; col < n; col++)
    {
        if (computers[row][col] != 0)
        {
            computers[row][col] = 0;
            recursiveDelete(n, col, computers);
        }
    }
}

int solution(int n, std::vector<std::vector<int>> computers)
{
    int answer = 0;

    //computers 2차원 행렬을 반복하면서 1인 (연결되어있는) 인덱스를 찾음.
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //인덱스를 찾으면 연결되어 있는 인덱스를 모두 0으로 지운다.
            if (computers[row][col] != 0)
            {
                answer++;
                recursiveDelete(n, col, computers);
            }
        }
    }

    return answer;
}

int main()
{
    std::cout << solution(3, { {1, 1, 0},  {1, 1, 1},  {0, 1, 1} }) << std::endl;
}