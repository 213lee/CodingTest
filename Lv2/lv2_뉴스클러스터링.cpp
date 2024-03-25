#include <string>
#include <map>
#include <iostream>
#include <algorithm>

//string�� �޾� ���ڿ��� ��ó���ϰ� ������������ ����� ���� return
std::map<std::string, int> StringToMultiSet(std::string str)
{
    //�����ڸ��� ����� �빮�ڸ� �ҹ��ڷ� ��ó��
    std::transform(str.begin(), str.end(), str.begin(),::tolower);
    
    //���������� ����ϱ� ���� counting�� ����� map
    std::map<std::string, int> multipleSet;

    //���ڰ� ��� �����ڶ�� �������տ� counting
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

    //Set1�� �������� Set2�� ������, ������, ������ ���� ���ϱ�
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

    //Set1�� ���� Set2�� �������� �����տ� �߰�
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