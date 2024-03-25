/*
0�� 1�� �̷���� � ���ڿ� x�� ���� ���� ��ȯ�� ������ ���� �����մϴ�.

    x�� ��� 0�� �����մϴ�.
    x�� ���̸� c��� �ϸ�, x�� "c�� 2�������� ǥ���� ���ڿ�"�� �ٲߴϴ�.

���� ���, x = "0111010"�̶��, x�� ���� ��ȯ�� ���ϸ� x = "0111010" -> "1111" -> "100" �� �˴ϴ�.

0�� 1�� �̷���� ���ڿ� s�� �Ű������� �־����ϴ�. s�� "1"�� �� ������ ����ؼ� s�� ���� ��ȯ�� ������ ��, ���� ��ȯ�� Ƚ���� ��ȯ �������� ���ŵ� ��� 0�� ������ ���� �迭�� ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.
���ѻ���

    s�� ���̴� 1 �̻� 150,000 �����Դϴ�.
    s���� '1'�� �ּ� �ϳ� �̻� ���ԵǾ� �ֽ��ϴ�.

����� ��
s 	result
"110010101001" 	[3,8]
"01110" 	[3,3]
"1111111" 	[4,1]
*/

#include<iostream>
#include<vector>

std::string binConversion(int len)
{
    std::string binStr;

    while (len > 0)
    {
        binStr += len % 2 + '0';
        len /= 2;
    }
    std::reverse(binStr.begin(), binStr.end());
    return binStr;
}

std::vector<int> solution(std::string s)
{
    std::vector<int> answer;
    int cnt = 0;
    int zero = 0;
    int strLen = s.length();
    while (strLen > 1)
    {
        cnt++;
        
        int len = count(s.begin(), s.end(), '1');
        zero += strLen - len;
        
        s = binConversion(len);
        strLen = s.length();
    }
    
    return { cnt, zero };
}

int main()
{
    std::string s = "110010101001";

    solution(s);

    s.erase(remove(s.begin(), s.end(), '0'), s.end());

    //std::cout << s << std::endl;

    //std::cout << binConversion(s.length()) << std::endl;
}