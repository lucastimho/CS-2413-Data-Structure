// ======= Task 1 =======
// Complete the header files
#include <iostream>
using namespace std;
// === End of Task 1 ====

// ======= Task 2 =======
// Design and implement all member functions of the
// following two classes: Student and University.
// All member functions must be implemented outside
// the class definitions.
//
class Student
{
public:
  void set_SID(int x);   // It assigns x to SID.
  void prt_SID();        // It prints SID.
  void set_GPA(float y); // It assigns y to GPA.
  void prt_GPA();        // It prints GPA.
  void reset();          // It resets SID and GPA to -1.
  float get_GPA();       // It returns GPA.
  Student();             // Constructor. It initializes
                         // both SID and GPA to -1.

private:
  int SID;   // It holds a student's ID.
  float GPA; // It holds a student's GPA.
};

void Student::set_SID(int x) // Assigns x to SID
{
  SID = x;
}
void Student::prt_SID() // Prints SID
{
  cout << SID;
}
void Student::set_GPA(float y) // Assigns y GPA
{
  GPA = y;
}
void Student::prt_GPA() // Prints GPA
{
  cout << GPA;
}
void Student::reset() // Resets SID and GPA to -1
{
  SID = -1;
  GPA = -1;
}
float Student::get_GPA() // Returns GPA
{
  return GPA;
}
Student::Student() // Initializes SID and GPA to -1
{
  SID = -1;
  GPA = -1;
}

class University
{
public:
  void set_Stu(Student x[]); // It assigns x to Sooner.
  float GPA_Mean();          // It prints the mean GPA of the five students held by Sooner[5].
  float GPA_Max();           // It prints the max GPA of these five students.
  float GPA_Min();           // It prints the min GPA of these five students.
  University();              // Constructor. Initialize all student SID and GPA to -1.
                             // Note: The above three functions must be implemented by yourself
                             // and not called from existing mean, max or min functions.
private:
  Student Sooner[5]; // It holds the records of five students.
};

void University::set_Stu(Student x[]) // Assigns x to Sooner
{
  for (int i = 0; i < 5; i++)
  {
    Sooner[i] = x[i];
  }
}
float University::GPA_Mean() // Returns the mean GPA of of the five students held by Sooner[5]
{
  float sum = 0.0;
  float mean;
  for (int i = 0; i < 5; i++)
  {
    sum += Sooner[i].get_GPA();
  }
  mean = sum / 5;
  cout << mean;
  return 0.0;
}
float University::GPA_Max() // Returns the max GPA of the five students
{
  float max = Sooner[0].get_GPA();
  for (int i = 0; i < 5; i++)
  {
    if (Sooner[i].get_GPA() > max)
    {
      max = Sooner[i].get_GPA();
    }
  }
  cout << max;
  return 0.0;
}
float University::GPA_Min() // Returns the minimum GPA of the five students
{
  float min = Sooner[0].get_GPA();
  for (int i = 0; i < 5; i++)
  {
    if (Sooner[i].get_GPA() < min)
    {
      min = Sooner[i].get_GPA();
    }
  }
  cout << min;
  return 0.0;
}
University::University() // Initializes all students SID and GPA to -1
{
  for (int i = 0; i < 5; i++)
  {
    Sooner[i].set_SID(-1);
    Sooner[i].set_GPA(-1);
  }
}
// === End of Task 2 ====

int main()
{
  Student x[5];
  University OU;

  for (int i = 0; i < 5; i++)
  {
    x[i].prt_SID();
    cout << ' ';
    x[i].prt_GPA();
    cout << endl;
  }

  // ======= Task 3 =======
  // Write a program that takes the SID
  // and GPA of five students as input
  // and assign them to x[5].
  //
  // Format of the inputs should be (with space)
  // SID1 GPA1 SID2 GPA2 SID3 GPA3 SID4 GPA4 SID5 GPA5
  // int SIDs[5];
  // float GPAs[5];

  // cin >> SIDs[0] >> GPAs[0] >> SIDs[1] >> GPAs[1] >> SIDs[2] >> GPAs[2] >> SIDs[3] >> GPAs[3] >> SIDs[4] >> GPAs[4];

  // for (int i = 0; i < sizeof(x); i++)
  // {
  //   x[i].set_SID(SIDs[i]);
  //   x[i].set_GPA(GPAs[i]);
  // }
  // === End of Task 3 ====

  // ======= Test 3 =======
  // This tests your University class.
  OU.set_Stu(x);
  OU.GPA_Mean();
  cout << ' ';
  OU.GPA_Max();
  cout << ' ';
  OU.GPA_Min();
  cout << endl;
  // === End of Test 3 ====

  return 0;
}