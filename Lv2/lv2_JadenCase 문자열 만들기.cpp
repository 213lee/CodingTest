/*
���� ����

JadenCase�� ��� �ܾ��� ù ���ڰ� �빮���̰�, �� ���� ���ĺ��� �ҹ����� ���ڿ��Դϴ�. ��, ù ���ڰ� ���ĺ��� �ƴ� ������ �̾����� ���ĺ��� �ҹ��ڷ� ���� �˴ϴ�. (ù ��° ����� �� ����)
���ڿ� s�� �־����� ��, s�� JadenCase�� �ٲ� ���ڿ��� �����ϴ� �Լ�, solution�� �ϼ����ּ���.
���� ����

    s�� ���� 1 �̻� 200 ������ ���ڿ��Դϴ�.
    s�� ���ĺ��� ����, ���鹮��(" ")�� �̷���� �ֽ��ϴ�.
        ���ڴ� �ܾ��� ù ���ڷθ� ���ɴϴ�.
        ���ڷθ� �̷���� �ܾ�� �����ϴ�.
        ���鹮�ڰ� �����ؼ� ���� �� �ֽ��ϴ�.

����� ��
s 	return
"3people unFollowed me" 	"3people Unfollowed Me"
"for the last week" 	"For The Last Week"

*/

#include<iostream>
#include<string>

std::string solution(std::string s)
{
    ////������ �ε�����  ' '�������� Ȯ���ϰ� toupper or tolower�ϱ� ���� 0��° �ε����� �ٷ� upperó��
    //s[0] = toupper(s[0]);
    //for (int i = 1; i < s.size(); i++)
    //{
    //    if (s[i - 1] == ' ')
    //    {
    //        s[i] = toupper(s[i]);
    //    }
    //    else
    //    {
    //        s[i] = tolower(s[i]);
    //    }
    //}

    //flag�� ����� Ǯ��
    bool flag = true;
    std::string answer;
    for (char c : s)
    {
        if (c == ' ')
        {
            flag = true;

        }
        else
        {
            c = flag ? toupper(c) : tolower(c);
            flag = false;
        }

        answer += c;

    }

    return answer;
}

int main()
{
    std::string input = "3People unFollowed me";
    char c = tolower('3');
    std::cout << solution(input) << std::endl;

    //printf("%s", solution(input));
}