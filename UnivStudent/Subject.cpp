//
//  Subject.cpp
//  UnivStudent

#include "Subject.h"
#include <string>

const char G[][3]=
{
// 0   50   100  150   200  250    300   350   400   450
  "F", "F", "D", "D+", "C", "C+", "B", "B+", "A", "A+"
};

const char M[][10]=
{
  "교양", "전공"
};

// 랜덤한 과목을 만들때 사용하는 자료
// 교양과목 (25)
const Subject General[] = {
  {0, "Activity-Based Leadership", 2},
  {1, "Theory-Based Leadership", 2},
  {2, "English Presentation", 2},
  {3, "Advanced English Writing", 2},
  {4, "Business English", 2},
  {5, "Current English", 2},
  {6, "Debate in English", 2},
  {7, "English for Arts and Literature", 2},
  {8, "English for Law", 2},
  {9, "Cultures of Globalization", 2},
  {10, "European Society and Culture", 2},
  {11, "Globalization and China", 2},
  {12, "Human Rights and Equality in Modern Society", 2},
  {13, "Interdependent World and Global Perspectives", 2},
  {14, "The Social Life and Culture in the Spanish-Speaking Regions", 2},
  {15, "The Thoughts and Culture in the Area of Indian Civilization", 2},
  {16, "The Thoughts and Culture of Islamic World", 2},
  {17, "Understanding Central Asia and Mongol", 2},
  {18, "Civilization of Human and Land", 3},
  {19, "History of Japan", 3},
  {20, "Understanding of Japanese Culture", 3},
  {21, "Understanding Opera", 3},
  {22, "European Society and Culture", 2},
  {23, "Badminton", 1},
  {24, "Basketball", 1},
};

// CSE major(53)
const Subject CSE[] = {
  {0,"System Programming",3},
  {1,"Computer Engineering Experiment II : C++ Language",2},
  {2,"Basic Programming Languages",3},
  {3,"Algorithms",3},
  {4,"Database",3},
  {5,"Operating Systems",3},
  {6,"Computer Graphics",3},
  {7,"Information Theory",3},
  {8,"Artificial Intelligence ",3},
  {9,"Seminar in Computer Engineering",1},
  {10,"Practical Programming Languages", 3},
  {11,"Human Computer Interaction",3},
  {12,"Computer Engineering Experiment IV : UNIX",2},
  {13,"Convergence Capstone Design",3},
  {14,"Creative Engineering Design",3},
  {15,"Engineering Numerical Analysis",3},
  {16,"Logic Circuits",3},
  {17,"Data Structures", 3},
  {18,"Probability and Random Processes",3},
  {19,"Logic Design Laboratory",2},
  {20,"Introduction to Computer Engineering",2},
  // 12major end
  {21,"Introduction to Management of Technology",3},
  {22,"Interdisciplinary Capstone Design",2},
  {23,"Global Capstone Design",3},
  {24,"Microprocessor",3},
  {25,"Computer Architectures",3},
  {26,"Field Training Program II for School of Information and Communication",3},
  {27,"Field Training Program III for Information and Communication",4},
  {28,"Field Training Program IV for School of Information and Communication",5},
  {29,"Multimedia Engineering",3},
  {30,"Digital Systems",3},
  {31,"Computer Networks",3},
  {32,"Introduction to Robotics",3},
  {33,"Web Programming",3},
  {34,"IT-3S Capstone Design",3},
  {35,"Software Engineering",3},
  {36,"Field Training Program V for School of Information and Communication",9},
  {37,"Team Project I",3},
  {38,"Introduction to Open Source Software",3},
  {39,"Internet Service and Information Security",3},
  {40,"Compiler Design", 3},
  {41,"Introduction to Artificial Intelligence",3},
  {42,"Object-Oriented System Project",3},
  {43,"Problem Solving",3},
  {44,"Cryptography",3},
  {45,"Computer Engineering Experiment III : JAVA",2},
  {46,"Computer Core Lab I : Operating System",1},
  {47,"Computer Core Lab II : Computer Networks",1},
  {48,"Wireless Network",3},
  {49,"Data Communication",3},
  {50,"Microprocessor Laboratory",2},
  {51,"Operating System Project", 3},
  {52,"Multicore Computing",3},
};
/*
private:
Subject subj;         // 과목
unsigned int year;    // 수강년도 (4 digits)
unsigned int seme;    // 수강학기 (1~2)
double grade; // A+(4.5), A(4.0), B+(3.5), ...
*/

/*
Subject::~Subject()
{
  
}
*/

Sugang::Sugang()
{
  
}

Sugang::Sugang( unsigned sid,  unsigned int year, unsigned int seme, int grade) : year(year), seme(seme), grade(grade)
{
  if(sid >= 100) // 전공 과목인 경우
    subj = CSE[sid-100];
  else
    subj = General[sid];
}
/*
Sugang::~Sugang()
{
  
}
*/
const Subject& Sugang::GetSubject()
{
  return subj;
}

void Sugang::Print()  // 과목 정보 출력
{
  printf("%d년 %d학기 %70s %2s\n", this->year, this->seme, this->subj.name.c_str(), G[(this->grade)/50]);
}