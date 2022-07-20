#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <vector>
#include <utility>
#include <map>

#include "time-table-generator/days.h"
#include "time-table-generator/sections.h"

class Teacher
{
public:
    Teacher();
    ~Teacher();

    void setName(std::string name);
    void setPhone(std::string phone);
    void setEmail(std::string email);
    void addFreePeriod(Days day, int period);
    void addCourse(std::string course, bool is_science);
    void addSection(Sections section);
    void setNumStudents(Sections section, std::string course, int num);
    void print();

    std::string getName();
    std::string getPhone();
    std::string getEmail();
    std::vector<int> getFreePeriods();
    int getNumStudents(Sections section, std::string course);

    // Vector of courses with name and if science of not
    std::vector<std::pair<std::string, bool> > courses;

    // Function to remove a free period because a class has been fixed
    void removeFreePeriod(int period);

private:
    std::string name;
    std::string phone;
    std::string email;
    std::vector<int> free_periods;
    std::vector<Sections> sections;

    // Num students for a particular section and course
    std::map<Sections, std::map<std::string, int>> num_students;
    int num_students_k1;
    int num_students_k2;
    int num_students_k3;
};

#endif // TEACHER_H