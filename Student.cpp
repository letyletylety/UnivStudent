//
//  Student.cpp
//  UnivStudent
#include <time.h>
#include <cstdlib>
#include "Student.h"
//                   0         2         4         6          8    9     10   11   12
double grading[] = {450, 450, 450, 400, 400, 400, 350, 350, 350, 300, 300 , 300, 250, 200, 150 , 100, 0};

Student::Student()
{
  ID = 0;
  name = "noname";
  subcnt = 0;
  sumsisu = 0;
  GPA = 0.0;
  year = 1;
//  AllSugang = NULL;
  general = 0;
  major = 0;
}

Student::Student( std::string dlfma ) : name(dlfma)
{
  ID = 2017;
  ID *= 100;
  ID += 31;
  ID *= 10000;
  ID += rand() % 9999+1; // 17학번 신입생
  subcnt = 0;
  sumsisu = 0;
  GPA = 0.0;
  year = 1;              // 1학년
  
//  AllSugang = NULL;
  general = 0;
  major = 0;
}
/*
Student::~Student()
{
  for(int i = 0 ; i < subcnt ; i++)
  {
    AllSugang[i].~Sugang();
  }
  delete [] AllSugang;
}
*/
Student& Student::operator=(const Student &Other) // 학생 클래스 용 대입 연산자
{
  ID = Other.ID;
  name = Other.name;
  general = Other.general;
  major = Other.major;
  year = Other.year;
  if(this != &Other)
  {
    for(int i = 0 ; i < Other.subcnt; i++)
    {
      AllSugang[i] = Other.AllSugang[i];
    }
  }
 
  subcnt = Other.subcnt;
  sumsisu = Other.sumsisu;
  GPA = Other.GPA;
  return *this;
}

void Student::SetYear(int y)
{
  year = y;
}

void Student::addSubject()    // 수강한 과목 추가
{

}

void Student::addRandomGeneralSubject()    // 교양 과목 랜덤하게 추가
{
  int rr;
  
  do
  {
    rr = rand() % GENERALSIZE;
  }while((general & (1<<rr))); // 이미 수강한 과목인지 확인
  
  general |= (1u<<rr);                   // 수강한 과목 추가

  // 과목을 성공적으로 수강함
  // 2011310336
  int year = (ID / 1000000);
  int tt = rand();
  year += (tt % (2017 - year));
  double G = grading[rand() % 13];
  //Sugang::Sugang( unsigned sid,  unsigned int year, unsigned int seme, double grade)
  AllSugang[subcnt] = Sugang(rr, year, 2 - tt % 2, G);
  
  const Subject subj = AllSugang[subcnt].GetSubject();
  
  double curG = GPA * sumsisu;
  
  sumsisu += subj.sisu; // 수강한 과목 시수 총합 (수강한 학점)
  GPA = (curG + G * subj.sisu) / sumsisu;
}

void Student::addRandomCSESubject()    // 컴공 과목 랜덤하게 추가
{
  int rr;
  
  do
  {
    rr = rand() % CSESIZE;
  }while(major & (1ULL<<rr)); // 이미 수강한 과목인지 확인
  
  // 과목을 성공적으로 수강함
  major |= (1ULL<<rr); // 수강한 과목 추가

  // 과목을 성공적으로 수강함
  // 2011310336
  int year = (ID / 1000000);
  int tt = rand();
  year += (tt % (2017 - year));
  
  double G = grading[rand() % GSIZE];
  AllSugang[subcnt] = Sugang(100 + rr, year, 2 - tt % 2, G);
  
  const Subject subj = AllSugang[subcnt].GetSubject();
  
  double curG = GPA * sumsisu;
  
  sumsisu += subj.sisu; // 수강한 과목 시수 총합 (수강한 학점)
  GPA = (curG + G * subj.sisu) / sumsisu;
}

void Student::Print()         // 학생 정보를 출력
{
  //  puts("학번        이름      학년    수강과목 수   수강 학점  GPA");
  printf("%10d %s %6d %10d %8d %4d.%02d\n",this->ID, this->name.c_str(), this->year, this->subcnt, this->sumsisu, (this->GPA)/100, (this->GPA)%100);
}

void Student::PrintDetail()         // 학생 정보를 자세히 (수강 과목까지) 출력
{
  puts("\n\n=*=*=*=*=*==*=*=*=*=*==*=*=*=*=*==*=*=*=*=*==*=*=*=*=*==*=*=*=*=*==*=*=*=*=*==*=*=*=*=*=\n");
  puts("학번        이름      학년    수강과목 수   수강 학점  GPA");
  printf("%10d %s %6d %10d %8d %4d.%02d\n",this->ID, this->name.c_str(), this->year, this->subcnt, this->sumsisu, (this->GPA)/100, (this->GPA)%100);
  puts("");
  puts("수강년도 학기                                 과목명                                  학점");
  puts("----------------------------------------------------------------------------------------");
 //     2015년 2학기                                   Understanding Central Asia and Mongol B+
  for(int i = 0 ; i < subcnt ; i++)
  {
    AllSugang[i].Print();
  }
  puts("\n=*=*=*=*=*==*=*=*=*=*==*=*=*=*=*==*=*=*=*=*==*=*=*=*=*==*=*=*=*=*==*=*=*=*=*==*=*=*=*=*=\n");
}