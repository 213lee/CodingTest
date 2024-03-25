#include <string>
#include <map>
#include <iostream>
#include <algorithm>

//string을 받아 문자열을 전처리하고 다중집합으로 사용할 맵을 return
std::map<std::string, int> StringToMultiSet(std::string str)
{
    //영문자만을 남기고 대문자를 소문자로 전처리
    std::transform(str.begin(), str.end(), str.begin(),::tolower);
    
    //다중집합을 허용하기 위해 counting에 사용할 map
    std::map<std::string, int> multipleSet;

    //문자가 모두 영문자라면 다중집합에 counting
    for (int i = 0; i < str.size() - 1; i++)
    {
        if (isalpha(str[i]) && isalpha(str[i + 1])) multipleSet[str.substr(i, 2)]++;
    }

    return multipleSet;
}

int solution(std::string str1, std::string str2) {
    
    std::map<std::string, int> str1Set = StringToMultiSet(str1);
    std::map<std::string, int> str2Set = StringToMultiSet(str2);

    int unionCount = 0;
    int intersectionCount = 0;

    if (str1Set.empty() && str2Set.empty()) return 65536;

    //Set1을 기준으로 Set2와 교집합, 차집합, 합집합 개수 구하기
    for (std::pair<std::string, int> p1 : str1Set)
    {
        std::map<std::string, int>::iterator p2_iter = str2Set.find(p1.first);
        if (p2_iter == str2Set.end())
        {
            unionCount += p1.second;
        }
        else
        {
            unionCount += p1.second > p2_iter->second ? p1.second : p2_iter->second;            //Union        = max(p1, p2)
            intersectionCount += p1.second < p2_iter->second ? p1.second : p2_iter->second;     //Intersection = min(p1, p2)
        }
    }

    //Set1에 대한 Set2의 차집합을 합집합에 추가
    for (std::pair<std::string, int> p2 : str2Set)
    {
        if (str1Set.find(p2.first) == str1Set.end())
        {
            unionCount += p2.second;
        }
    }

    return (double)intersectionCount / (double)unionCount * 65536;
}

int main()
{
    std::cout << solution("aa1+aa2", "151") << std::endl;
}