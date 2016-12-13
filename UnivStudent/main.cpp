//
//  main.cpp
//  UnivStudent
/*
    과목
*/

#define TEST
#undef TEST

#define INITSIZE 200 // 초기에 생성해줄 학생수

#include <iostream>
#include <cstdio>
#include "rbtree.h"
#include "UI.hpp"
#include <string>

using namespace std;

DB db;

int main(int argc, const char * argv[])
{
  int user_choice = 0; // 유저가 선택한 메뉴
  
  UI ui;
  std::string ss;
  node *np;
  node tempNode;
  rbtree* IdTree = new rbtree();
  rbtree* GPATree = new rbtree();
  
  printf("*학생 정보 관리 프로그램*\n");
  puts("");
  puts("DB를 초기화 하는 중입니다.\n");
  
  db.InitDB(INITSIZE); // 200 명의 학생 정보를 랜덤하게 생성하여 초기화 한다.
  
  for (int i = 0; i < INITSIZE; i++) {
    IdTree->insertNode(i, db.AllStudent[i].ID);
    GPATree->insertNode(i, -db.AllStudent[i].GPA);
  }
  
  puts("DB가 초기화 되었습니다.\n");
  
  while (1)
  {
    ui.PrintMenu();
    
    scanf("%d", &user_choice);
    ui.screen_clear(10);
    switch (user_choice) {
      case 1:
        printf("1. 학생을 새로 추가하기 \n");
        printf("학생 이름을 입력하세요 : ");
        std::cin>>ss;
        db.AddStudent(ss); // 새로운 학생 추가
        IdTree->insertNode(db.numOfStudent, db.AllStudent[db.numOfStudent].ID);
        GPATree->insertNode(db.numOfStudent, -db.AllStudent[db.numOfStudent].GPA);
        db.numOfStudent++;
        puts("메뉴로 돌아가려면 아무 키나 누르세요");
        getchar();
        getchar();

        break;
      case 2:
        unsigned int ID;
        printf("2. 학생 정보를 검색하기 \n");
        printf("학생 ID를 입력하세요\n");
        scanf("%u",&ID);
        np = IdTree->search(ID);
        if(np == NULL)
          puts("없는 ID입니다.");
        else
          db.AllStudent[np->id].PrintDetail();
        
        //db.SearchDB(ID);
        puts("메뉴로 돌아가려면 아무 키나 누르세요");
        getchar();
        getchar();

        break;
      case 3:
        printf("3. 전체 학생 정보를 학번 순으로 출력하기 \n");
        puts("DB 전체 정보를 출력합니다.");
        puts("");
        puts("==================================================");
        puts("학번        이름      학년   수강과목 수  수강 학점    GPA");
        IdTree->show_all();
        puts("==================================================");
        puts("메뉴로 돌아가려면 아무 키나 누르세요");
        getchar();
        getchar();

        //db.PrintDB();
        break;
      case 4:
        puts("4. 전체 학생 정보를 GPA 순으로 출력하기 \n");
        puts("DB 전체 정보를 출력합니다.");
        puts("");
        puts("==================================================");
        puts("학번        이름      학년   수강과목 수  수강 학점    GPA");
        GPATree->show_all();
        puts("==================================================");
        puts("메뉴로 돌아가려면 아무 키나 누르세요");
        getchar();
        getchar();
        
      case 5:
        printf("5. 학생 정보를 삭제하기 \n");
        printf("학생 ID를 입력하세요\n");
        scanf("%u",&ID);
        np = IdTree->search(ID);
        if(np == NULL)
          puts("없는 ID입니다.");
        else
        {
          tempNode = *np;
          IdTree->deleteNode(tempNode.id, ID);
          GPATree->deleteNode(tempNode.id, -db.AllStudent[tempNode.id].GPA);
        }
        //db.SearchDB(ID);
        puts("메뉴로 돌아가려면 아무 키나 누르세요");
        getchar();
        getchar();
        break;
      case 0:
        return printf("0. 프로그램 종료 \n"), 0;
        break;
      default:
        puts("다시 입력하세요");
       //
    }
  }
  return 0;
}