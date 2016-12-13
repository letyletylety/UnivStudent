//
//  UI.hpp
//  UnivStudent
//

#ifndef UI_hpp
#define UI_hpp

#include <stdio.h>
#include "Subject.h"
#include "Student.h"
#include "rbtree.h"

class UI
{
  
  // interface
public:
  void Print(Sugang &A);               // 과목 정보 출력
  void Print(Student &A);               // 학생 정보를 출력
  void Print(DB &A);
  void PrintDetail(Student &A);         // 학생 정보를 자세히 (수강 과목까지) 출력
  void printNode(node * n);             // 노드 데이터를 출력
  void printTree(rbtree *t);
  void screen_clear(int line = 50);     // 화면 비우기
  
  void PrintMenu(void);
};

#endif /* UI_hpp */