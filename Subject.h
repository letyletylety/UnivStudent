//
//  Subject.h
//  UnivStudent

#include <string>

#define GENERALSIZE 25
#define CSESIZE 53

#ifndef Subject_h
#define Subject_h

struct Subject
{
  unsigned int sid;
  std::string name;
  unsigned int sisu;
  
  //~Subject();
};

class Sugang           // 학생이 수강한 과목 클래스
{
private:
  Subject       subj;    // 과목
  unsigned int  year;    // 수강년도 (4 digits)
  unsigned int  seme;    // 수강학기 (1~2)
  int           grade;   // A+(4.5), A(4.0), B+(3.5), ...
  
public:
  Sugang();
  Sugang( unsigned sid,  unsigned int year, unsigned int seme, int grade);

  const Subject& GetSubject();
  
  void Print();         // 과목 정보 출력
};

#endif /* Subject_h */
