//
//  Subject.h
//  UnivStudent

#include <string>

#ifndef Subject_h
#define Subject_h

class Subject           // 학생이 수강한 과목 클래스
{
private:
  unsigned int sid;     // 학수번호
  std::string name;     // 과목명
  unsigned int year;    // 수강년도 (4 digits)
  unsigned int seme;    // 수강학기 (1~2)
  unsigned int sisu;    // 시수
  double grade; // A+(4.5), A(4.0), B+(3.5), ...
  
public:
  Subject( unsigned int sid, std::string name, unsigned int year, unsigned int seme, unsigned int sisu,double grade);
  Subject(int random);  // 랜덤 생성자
  ~Subject();
  void Print();         // 과목 정보 출력
};

#endif /* Subject_h */
