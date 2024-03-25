/*
0과 1로 이루어진 어떤 문자열 x에 대한 이진 변환을 다음과 같이 정의합니다.

    x의 모든 0을 제거합니다.
    x의 길이를 c라고 하면, x를 "c를 2진법으로 표현한 문자열"로 바꿉니다.

예를 들어, x = "0111010"이라면, x에 이진 변환을 가하면 x = "0111010" -> "1111" -> "100" 이 됩니다.

0과 1로 이루어진 문자열 s가 매개변수로 주어집니다. s가 "1"이 될 때까지 계속해서 s에 이진 변환을 가했을 때, 이진 변환의 횟수와 변환 과정에서 제거된 모든 0의 개수를 각각 배열에 담아 return 하도록 solution 함수를 완성해주세요.
제한사항

    s의 길이는 1 이상 150,000 이하입니다.
    s에는 '1'이 최소 하나 이상 포함되어 있습니다.

입출력 예
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