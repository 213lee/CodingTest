#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<std::vector<int>> land)
{
    int answer = 0;
    int rowEnd = land.size() - 1;
    //두번째 행부터 마지막 행까지(row + 1) 각 열이 가질 수 있는 최대값을 계산해 저장
    for (int row = 0; row < rowEnd; row++)
    {
        land[row + 1][0] += std::max(land[row][1], std::max(land[row][2], land[row][3]));
        land[row + 1][1] += std::max(land[row][0], std::max(land[row][2], land[row][3]));
        land[row + 1][2] += std::max(land[row][0], std::max(land[row][1], land[row][3]));
        land[row + 1][3] += std::max(land[row][0], std::max(land[row][1], land[row][2]));
    }
    //마지막 행의 최대 값은 최고점
    answer = *max_element(land[rowEnd].begin(), land[rowEnd].end());

    std::cout << answer << std::endl;

    return answer;
}


int main()
{
    std::vector<std::vector<int>> land = { {1,2,3,5},{5,6,7,8},{4,3,2,1} };

    solution(land);
}