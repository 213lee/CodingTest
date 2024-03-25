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
            //�����ڸ� �ε��� (0 = j, size - 1 = j - 1) ����ó��
            if (j <= 0) triangle[i][j] += triangle[i - 1][j];
            else if(j >= triangle[i].size() - 1) triangle[i][j] += triangle[i - 1][j - 1];
            else
            {
                //triangle[i - 1][j - 1 or j] �ִ��� ������ ���Ͽ� �� ����
                triangle[i][j] += triangle[i - 1][j - 1] >= triangle[i - 1][j] ? triangle[i - 1][j - 1] : triangle[i - 1][j];
            }
        }
    }
    //������ ������ �ִ��� ������ return
    return *max_element(triangle[triangle.size() -1].begin(), triangle[triangle.size() - 1].end());
}


int main()
{
    std::cout << solution({{ 7 }, { 3, 8 }, { 8, 1, 0 }, { 2, 7, 4, 4 }, { 4, 5, 2, 6, 5 }}) << std::endl;
}


