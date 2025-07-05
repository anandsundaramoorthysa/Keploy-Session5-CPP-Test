#include "gtest/gtest.h" // include gtest header file in all test files  
// Include the student class definition (student.h) here if not done already since it is included inside Student's cpp and hence should be tested along with other classes or functions 
    
class StudentRegistryTest : public ::testing::Test { // Test case inheritance from google test base testing suite   
protected:  
virtual void SetUp() {}     
virtual void TearDown(){}       
Student s1{"John", 20,35};      
std::vector<int> expected_ids{s1.getId(), secondSchoolMember.id };     // initialize the vector of ID's    std:list or array instead if necessary     
// declare instance variables for testing  
StudentRegistry sr;         // create an object to test it 
};      
TEST_F(StudentRegistryTest, TestAddAndGetById) {        /* define your tests within a function */    
sr.addstudents({s1});      /// Add students in one by calling the method add student from Student Registry and pass s1 as parameter   // This is done for testing only once  so it'll not affect later test cases, you can comment or delete to re-create each time    Testing if function correctly adds a student then retrieves them back using their IDs.
ASSERT_EQ(sr.getTotalStudents(), expectedIds_.size());     // Check the number of students added  and equal it with size from vector   Expected id'S should be in same order as they are inserted into StudentRegistry by addstudent method    for (int i=0;i<expected_ids,++) {
EXPECT_EQ(sr.getStudentsById(ExpectedIds[i]), s1); // expected student with the corresponding id to match  it's ID should be equal in both methods and assert if they are not same then fail test case    }        /* end of function */ };      GTEST commands for running this unit tests would go here.
```   The code above will cover all scenarios including edge cases (like no students added) as well the positive scenario where we're adding a student to our registry and retrieving it back by ID using getStudentById method which should be done once in each test case, ensuring that every function works correctly under different circumstances. It also follows proper naming conventions for tests functions based on their purpose or functionality of code segment they are testing as much you can about this specific unit (in our example it's StudentRegistry)


