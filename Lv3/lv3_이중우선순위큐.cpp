#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>

std::vector<int> solution(std::vector<std::string> operations) {
    
    //���ĵ� ���¸� �����ϰ� �ߺ��� ����ϴ� multy set
    std::multiset<int> multiSet;
    
    for (std::string s : operations)
    {
        std::stringstream sstream(s);
        int num;

        //ù ��ɾ� I or D
        switch (sstream.get())
        {
        case 'I':
            sstream >> num;
            multiSet.insert(num);
            break;
        case 'D':
            if (multiSet.empty()) break;
            sstream >> num;
            //--end() : �ִ�, begin() : �ּ�
            if (num == 1) multiSet.erase(--multiSet.end());
            else multiSet.erase(multiSet.begin());
            break;
        }     
    }
    if (multiSet.empty()) return { 0, 0 };
    
    return { *(--multiSet.end()), *multiSet.begin() };
}

int main()
{
    solution({ "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" });
}