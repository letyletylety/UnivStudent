//
//  UI.cpp
//  UnivStudent
//

#include "UI.hpp"


void UI::screen_clear(int line)
{
  while(line--)
    puts("");
}

void UI::Print(Sugang &A)              // 과목 정보 출력
{
  A.Print();
}
void UI::Print(Student &A)               // 학생 정보를 출력
{
  A.Print();
}
void UI::Print(DB &A)
{
  A.PrintDB();
}
void UI::PrintDetail(Student &A)         // 학생 정보를 자세히 (수강 과목까지) 출력
{
  A.PrintDetail();
}
void UI::printNode(node * n)             // 노드 데이터를 출력
{
  n->printNode(n);
}
void UI::printTree(rbtree *t)
{
  t->show_all();
}

void UI::PrintMenu(void)
{
  puts("");
  printf("=*=*=*=*=*=*= 메뉴를 선택하세요 =*=*=*=*=*=*=\n");
  printf("+     1. 학생을 새로 추가                  +\n");
  printf("+     2. 학생 정보를 검색                  +\n");
  printf("+     3. 전체 학생 정보를 ID 순으로 출력      +\n");
  printf("+     4. 전체 학생 정보를 GPA 순으로 출력     +\n");
  printf("+     0. 종료                            +\n");
  printf("=*=*=*=*=*=*= 메뉴를 선택하세요 =*=*=*=*=*=*=\n");
  puts("");
}
