#include <string>
#include <vector>
#include <map>

std::vector<int> solution(std::vector<std::string> name, std::vector<int> yearning, std::vector<std::vector<std::string>> photo) 
{
    std::vector<int> answer;
    std::map<std::string, int> nameScore;
    int score;

    //Map에 Key는 이름 Value는 그리움 점수로 캐싱
    for (int i = 0; i < name.size(); i++) nameScore[name[i]] = yearning[i];

    //photo 벡터를 순회하며 Map을 참조하여 각 사진의 점수 합산
    for (std::vector<std::string> v : photo)
    {
        score = 0;
        for (std::string s : v)
        {
            score += nameScore[s];
        }
        answer.push_back(score);
    }

    return answer;
}

int main()
{

}