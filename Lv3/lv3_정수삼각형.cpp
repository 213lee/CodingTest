#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int solution(std::vector<std::vector<int>> triangle) {
    int answer = 0;

    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            //가장자리 인덱스 (0 = j, size - 1 = j - 1) 예외처리
            if (j <= 0) triangle[i][j] += triangle[i - 1][j];
            else if(j >= triangle[i].size() - 1) triangle[i][j] += triangle[i - 1][j - 1];
            else
            {
                //triangle[i - 1][j - 1 or j] 최댓값을 선택해 더하여 값 갱신
                triangle[i][j] += triangle[i - 1][j - 1] >= triangle[i - 1][j] ? triangle[i - 1][j - 1] : triangle[i - 1][j];
            }
        }
    }
    //마지막 벡터의 최댓값을 선택해 return
    return *max_element(triangle[triangle.size() -1].begin(), triangle[triangle.size() - 1].end());
}


int main()
{
    std::cout << solution({{ 7 }, { 3, 8 }, { 8, 1, 0 }, { 2, 7, 4, 4 }, { 4, 5, 2, 6, 5 }}) << std::endl;
}


