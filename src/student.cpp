#include "student.h"
#include <stdexcept>

Student::Student(std::string name, int id, int age)
    : name(name), id(id), age(age) {}

std::string Student::getName() const {
    return name;
}

int Student::getId() const {
    return id;
}

int Student::getAge() const {
    return age;
}

void StudentRegistry::addStudent(const Student& student) {
    students.push_back(student);
}

Student StudentRegistry::getStudentById(int id) const {
    for (const auto& student : students) {
        if (student.getId() == id)
            return student;
    }
    throw std::runtime_error("Student not found");
}

int StudentRegistry::getTotalStudents() const {
    return students.size();
}
