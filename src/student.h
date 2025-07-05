#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
public:
    Student(std::string name, int id, int age);

    std::string getName() const;
    int getId() const;
    int getAge() const;

private:
    std::string name;
    int id;
    int age;
};

class StudentRegistry {
public:
    void addStudent(const Student& student);
    Student getStudentById(int id) const;
    int getTotalStudents() const;

private:
    std::vector<Student> students;
};

#endif
