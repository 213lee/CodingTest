//#include <string>
//#include <vector>
//#include <stdio.h>
//
////#include <iostream>
////#include <string>
////#include <vector>
////
////using namespace std;
////int d[30];
////int solution(string skill, vector<string> skill_trees) {
////    int answer = 0;
////    for (string& s : skill_trees) {
////        int i = 0;
////        for (char& c : s) {
////            int pos = skill.find(c);
////            if (pos != -1)
////                d[i++] = pos;
////        }
////        bool ok = true;
////        for (int k = 0; k < i; k++) {
////            //if(d[k] != skill[k]-'A')
////            if (d[k] != k)
////                ok = false;
////        }
////
////        if (ok) answer += 1;
////        //if(ok) cout << s << ' ';
////    }
////    return answer;
////}
//
//int solution(std::string skill, std::vector<std::string> skill_trees)
//{
//    int answer = 0;
//
//    std::string tmpSkill;
//    bool possible;
//    for (std::string tree : skill_trees)
//    {
//        tmpSkill = skill;
//        possible = true;
//        for (int i = 0; i < tree.size(); i++)
//        {
//            //���ེų�� ��
//            if (tmpSkill.find(tree[i]) != std::string::npos)
//            {
//                //���ེų vector�� ù��° ���̶�� ����. -> ������ ��ų�� ���ٸ� ���� �� ��ų ����.
//                if (tmpSkill[0] == tree[i]) tmpSkill.erase(tmpSkill.begin());
//                else
//                {
//                    possible = false;
//                    break;
//                }
//            }
//        }
//        if (possible) answer++;
//    }
//    printf("%d", answer);
//    return answer;
//}
//
//int main()
//{
//    std::string skill = "CBD";
//    std::vector<std::string> skill_trees = { "BACDE", "CBADF", "AECB", "BDA" };
//    solution(skill, skill_trees);
//}
//
