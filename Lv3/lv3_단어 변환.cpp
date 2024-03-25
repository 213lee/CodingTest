#include <string>
#include <vector>
#include <cmath>
#include <iostream>

//두 단어가 변환이 가능한지 여부 체크(한자리만 다른 경우) 메서드
bool CheckWords(const std::string& a, const std::string& b)
{
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i]) count++;
    }

    if (count > 1) return false;

    return true;
}

//방문한 노드 수를 체크하는 메서드
int CountLevel(const std::vector<bool>& visit)
{
    int count = 0;
    for (bool v : visit) if (v) count++;
    return count;
}

//조건에 맞는 노드(인덱스)를 방문해 가능한 경우에서 방문한 노드 수로 최소값 찾는 재귀 메서드
void DFS(const std::vector<std::string>& words, std::vector<bool>& visit, int& answer, std::string curWord, const std::string& target)
{
    if (curWord == target)
    {
        int count = CountLevel(visit);
        if (answer == 0) answer = count;
        else answer = std::min(answer, count);
    }

    for (int i = 0; i < words.size(); i++)
    {
        if (!visit[i] && CheckWords(curWord, words[i]))
        {
            visit[i] = true;
            DFS(words, visit, answer, words[i], target);
            visit[i] = false;
        }
    }
}

int solution(std::string begin, std::string target, std::vector<std::string> words) {
    int answer = 0;

    std::vector<bool> visit(words.size(), false);

    DFS(words, visit, answer, begin, target);

    return answer;
}


int main()
{
    std::string begin = "hit";
    std::string target = "cog";
    
    std::vector<std::string> words = { "hot", "dot", "dog", "lot", "log", "cog"};

    std::cout << solution(begin, target, words);
}