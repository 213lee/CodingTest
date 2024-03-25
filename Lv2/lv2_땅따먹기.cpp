#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<std::vector<int>> land)
{
    int answer = 0;
    int rowEnd = land.size() - 1;
    //�ι�° ����� ������ �����(row + 1) �� ���� ���� �� �ִ� �ִ밪�� ����� ����
    for (int row = 0; row < rowEnd; row++)
    {
        land[row + 1][0] += std::max(land[row][1], std::max(land[row][2], land[row][3]));
        land[row + 1][1] += std::max(land[row][0], std::max(land[row][2], land[row][3]));
        land[row + 1][2] += std::max(land[row][0], std::max(land[row][1], land[row][3]));
        land[row + 1][3] += std::max(land[row][0], std::max(land[row][1], land[row][2]));
    }
    //������ ���� �ִ� ���� �ְ���
    answer = *max_element(land[rowEnd].begin(), land[rowEnd].end());

    std::cout << answer << std::endl;

    return answer;
}


int main()
{
    std::vector<std::vector<int>> land = { {1,2,3,5},{5,6,7,8},{4,3,2,1} };

    solution(land);
}