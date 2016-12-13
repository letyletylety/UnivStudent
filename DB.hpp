//
//  DBController.hpp
//  UnivStudent
//

#include "Student.h"
#include "Subject.h"

#define SIZE 1000

class DB
{
public:
  int numOfStudent;
  Student AllStudent[SIZE];
  
  DB();
  ~DB();
  void InitDB(int numberOfStudents); // 데이터베이스 초기화
  void CreateRandomStudent(Student &A); // 학생 A를 초기화
  
  void AddStudent(std::string name);    // 신입생 추가
  void SearchDB(unsigned int ID);       // ID로 검색
  
  void PrintDB(); // 전체 학생 정보를 출력
};

