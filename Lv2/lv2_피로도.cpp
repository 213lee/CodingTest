#include <string>
#include <vector>
#include <cmath>
#include <iostream>


//완전 탐색(재귀)을 이용해 모든 순서(경우)에서 던전의 수 찾기
//visit[] : 해당 던전을 방문했는지 여부 방문했다면 true, 재귀 종료 후 돌아왔을때 false
//answer  : 최종 정답, 전역변수를 쓰지 않기 위해 레퍼런스로 값 수정
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

//k : 현재 가지는 피로도
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