/*
���� ����

¦���� �����ϱ��, ���ĺ� �ҹ��ڷ� �̷���� ���ڿ��� ������ �����մϴ�. ���� ���ڿ����� ���� ���ĺ��� 2�� �پ� �ִ� ¦�� ã���ϴ�.
�״���, �� ���� ������ ��, �յڷ� ���ڿ��� �̾� ���Դϴ�. �� ������ �ݺ��ؼ� ���ڿ��� ��� �����Ѵٸ� ¦���� �����ϱⰡ ����˴ϴ�.
���ڿ� S�� �־����� ��, ¦���� �����ϱ⸦ ���������� ������ �� �ִ��� ��ȯ�ϴ� �Լ��� �ϼ��� �ּ���. ���������� ������ �� ������ 1��, �ƴ� ��� 0�� �������ָ� �˴ϴ�.

���� ���, ���ڿ� S = baabaa ���

b aa baa �� bb aa �� aa ��

�� ������ ���ڿ��� ��� ������ �� �����Ƿ� 1�� ��ȯ�մϴ�.
���ѻ���

    ���ڿ��� ���� : 1,000,000������ �ڿ���
    ���ڿ��� ��� �ҹ��ڷ� �̷���� �ֽ��ϴ�.

����� ��
s 	result
baabaa 	1
cdcd 	0
����� �� ����

����� �� #1
���� ���ÿ� �����ϴ�.
����� �� #2
���ڿ��� ���������� ¦���� ������ �� �ִ� ���ڿ��� �� �̻� �������� �ʱ� ������ 0�� ��ȯ�մϴ�.
*/



#include<iostream>
#include<stack>

int solution(std::string s)
{
    std::stack<char> chStack;
    chStack.push(s[0]);

    for (int i = 1; i < s.size(); i++)
    {
        if (!chStack.empty() && s[i] == chStack.top())
        {
            chStack.pop();
        }
        else
        {
            chStack.push(s[i]);
        }
    }

    return chStack.empty();
}


int main()
{
    std::cout << solution("baabba");
}


/*
ù��° ���

#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{
    int answer = -1;

    string tmp;

    for (int i = 0; i < s.size(); i++)
    {
        if (!tmp.empty() && tmp.back() == s[i]) tmp.pop_back();
        else tmp.push_back(s[i]);
    }

    return tmp.empty();
}
*/


