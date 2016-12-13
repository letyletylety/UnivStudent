//
//  Student.h
//  UnivStudent

#define GSIZE 17 // 과목 등급
#define SUBSIZE 50 // 최대 수강 과목

#include <string>
#include "Subject.h"

#ifndef Student_h
#define Student_h

class Student
{
public:
  unsigned int ID;      // 학번
  std::string name;     // 이름
  // Subject* subarr;      // 수강한 과목들
  
  // 비트마스크 (이미 수강한 과목인지 확인)
  unsigned int general;  // 교양
  unsigned long long int major;   // 전공

  Sugang AllSugang[50];
  
  unsigned int subcnt;  // 수강한 과목 수
  unsigned int sumsisu; // 수강한 과목 시수 총합 (수강한 학점)
  unsigned int year;    // 학년
  //double GPA;           // GPA
  int GPA;
  
public:
  Student();
  Student( std::string name ); // 새로운 학생을 추가
  //~Student();
  
  void SetYear(int y);
  
  Student &operator =(const Student &Other); // 대입 연산자
  
  void addSubject();    // 수강한 과목 추가
  
  void addRandomGeneralSubject();    // 교양 과목 랜덤하게 추가
  void addRandomCSESubject();        // 컴공 과목 랜덤하게 추가
  
  void Print();               // 학생 정보를 출력
  void PrintDetail();         // 학생 정보를 자세히 (수강 과목까지) 출력
};

#endif /* Student_h */
