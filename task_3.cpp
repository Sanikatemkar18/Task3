#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    double grade;
};

int main() {
    std::vector<Student> students;
    std::string name;
    double grade;

    std::cout << "Enter student names and their corresponding grades. Type 'exit' for name to stop.\n";

    while (true) {
        std::cout << "Enter student name: ";
        std::cin >> name;

        if (name == "exit") {
            break;
        }

        std::cout << "Enter grade: ";
        std::cin >> grade;

        students.push_back({name, grade});
    }

    // Calculate average grade
    double totalGrade = 0.0;
    for (const auto& student : students) {
        totalGrade += student.grade;
    }
    double averageGrade = totalGrade / students.size();

    // Find the highest and lowest grades
    double highestGrade = std::numeric_limits<double>::min();
    double lowestGrade = std::numeric_limits<double>::max();
    for (const auto& student : students) {
        highestGrade = std::max(highestGrade, student.grade);
        lowestGrade = std::min(lowestGrade, student.grade);
    }

    std::cout << "\n----- Grades Summary -----\n";
    for (const auto& student : students) {
        std::cout << "Name: " << student.name << ", Grade: " << student.grade << "\n";
    }
    std::cout << "Average Grade: " << averageGrade << "\n";
    std::cout << "Highest Grade: " << highestGrade << "\n";
    std::cout << "Lowest Grade: " << lowestGrade << "\n";

    return 0;
}
