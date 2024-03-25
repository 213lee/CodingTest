#include <string>
#include <vector>
#include <cmath>
#include <iostream>


//���� Ž��(���)�� �̿��� ��� ����(���)���� ������ �� ã��
//visit[] : �ش� ������ �湮�ߴ��� ���� �湮�ߴٸ� true, ��� ���� �� ���ƿ����� false
//answer  : ���� ����, ���������� ���� �ʱ� ���� ���۷����� �� ����
void recursiveSearch(const std::vector<std::vector<int>>& dungeons, std::vector<bool>& visit, int k, int result, int& answer)
{
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (!visit[i] && k >= dungeons[i][0])
        {
            visit[i] = true;
            recursiveSearch(dungeons, visit, k - dungeons[i][1], result+1, answer);
            visit[i] = false;
        }
    }
    answer = std::max(result, answer);
}

//k : ���� ������ �Ƿε�
int solution(int k, std::vector<std::vector<int>> dungeons) {
    int answer = 0;
    std::vector<bool> visit;
    visit.assign(dungeons.size(), false);

    recursiveSearch(dungeons, visit, k, 0, answer);
    
    return answer;
}

int main()
{
    std::cout << solution(80, { {80,20}, {50,40}, {30,10}}) << std::endl;
}