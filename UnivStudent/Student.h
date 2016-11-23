//
//  Student.h
//  UnivStudent


#include <string>
#include "Subject.h"

#ifndef Student_h
#define Student_h

class Student
{
private:
  unsigned int ID;      // 학번
  std::string name;     // 이름
  Subject* subarr;      // 수강한 과목들
  unsigned int sumsisu; // 수강한 과목 시수 총합 (수강한 학점)
  double GPA;           // GPA
  
public:
  Student();
  ~Student();
  void addSubject();    // 수강한 과목 추가
  void Print();         // 학생 정보를 출력
};

#endif /* Student_h */
