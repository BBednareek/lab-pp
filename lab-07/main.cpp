#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

struct Point{
    int x_pos;
    int y_pos;
};

struct Line {
    Point point1;
    Point point2;
};

struct Circle{
    Point center;
    double radius;
};

struct Rectangle{
    Point bottom_left;
    Point top_right;
};

struct IntersectRes{
    Rectangle resRect;
    bool hasIntersect;
};

struct Student {
    std::string name;
    std::string surname;
    char sex{};
    std::string pesel;
    std::string idx_nr;
};


double distance(Point point1, Point point2){
    return sqrt(pow((point2.x_pos - point1.x_pos),2) + pow((point2.y_pos - point1.y_pos), 2));
}

double length_Line(Line line){
    return distance(line.point1, line.point2);
}

//Iloczyn skalarny dwoch wektorow

int dotProduct(Point vec1, Point vec2){
    return vec1.x_pos * vec2.x_pos + vec1.y_pos * vec2.y_pos;
}

bool areOrthogonal(Line line1, Line line2){
    Point vec1 = {line1.point2.x_pos - line1.point1.x_pos,
                  line1.point2.y_pos - line1.point1.y_pos};

    Point vec2 = {line2.point2.x_pos - line2.point1.x_pos,
                  line2.point2.y_pos - line2.point1.y_pos};

    //Iloczyn == 0 ? true : false
    return dotProduct(vec1, vec2) == 0;
}

double point_pos(Circle circle, Point point){
    double distance = sqrt(pow(point.x_pos - circle.center.x_pos, 2) + pow(point.y_pos - circle.center.y_pos, 2));

    if (distance < circle.radius)
        //Wewnatrz
        return ((circle.radius - distance) / circle.radius);
    else if (distance == circle.radius)
        //Na okregu
        return 1;
    else
        //Na zewnatz
        return distance;
}

//Obwod najwiekszego okregu
double maxCircleCircumference(const std::vector<Circle>& circles){
    if(circles.empty())
        return 0.0;

    double maxCircumference = 0.0;

    for(const Circle& circle: circles) {
        double circumference = 2 * M_PI * circle.radius;

        if(circumference > maxCircumference)
            maxCircumference = circumference;
    }

    return maxCircumference;
}


IntersectRes intersect(Rectangle rect1, Rectangle rect2){
    IntersectRes res{};

    res.resRect.bottom_left.x_pos = std::max(rect1.bottom_left.x_pos, rect2.bottom_left.x_pos);
    res.resRect.bottom_left.x_pos = std::max(rect1.bottom_left.y_pos, rect2.bottom_left.y_pos);
    res.resRect.bottom_left.x_pos = std::min(rect1.top_right.x_pos, rect2.top_right.x_pos);
    res.resRect.bottom_left.x_pos = std::min(rect1.top_right.x_pos, rect2.top_right.x_pos);

    if (res.resRect.bottom_left.x_pos >= res.resRect.top_right.x_pos || res.resRect.bottom_left.y_pos >= res.resRect.top_right.y_pos)
       res.hasIntersect = false;
    else
        res.hasIntersect = true;

    return res;
}

Student read_student_data(){
    Student student;

    std::cout << "Enter student name: ";
    std::cin >> student.name;
    std::cout << "Enter student surname: ";
    std::cin >> student.surname;
    std::cout << "Enter student sex (M/F): ";
    std::cin >> student.sex;
    std::cout << "Enter student PESEL: ";
    std::cin >> student.pesel;
    std::cout << "Enter student index number: ";
    std::cin >> student.idx_nr;

    return student;
}

void display_student(const Student& student) {
    std::cout << "Name: " << student.name << std::endl;
    std::cout << "Surname: " << student.surname << std::endl;
    std::cout << "Sex: " << student.sex << std::endl;
    std::cout << "PESEL: " << student.pesel << std::endl;
    std::cout << "Index number: " << student.idx_nr << std::endl;
}

std::vector<Student> fill_students() {
    std::vector<Student> students;

    students.push_back({ "Jan", "Kowalski", 'M', "12345678901", "S12345" });
    students.push_back({ "Anna", "Nowak", 'K', "98765432109", "S67890" });
    students.push_back({ "Piotr", "Nowicki", 'M', "45678901234", "S24680" });

    return students;
}

void display_all_students(const std::vector<Student>& students){
    for (const Student& student: students)
        display_student(student);
}

int find_student(const std::vector<Student>& students, const std::string& searchedIdx){
    for(int i = 0; i < students.size(); ++i)
        if (students[i].idx_nr == searchedIdx)
            return i;
    return -1;
}

bool add_student(std::vector<Student>& students, const Student& newStudent){
    try {
        students.push_back(newStudent);
        return true;
    } catch (const std::exception& e){
        std::cerr << "Error while adding new student: " << e.what() << std::endl;
        return false;
    }
}

void remove_student(std::vector<Student>& students, const std::string& idxRem) {
    students.erase(std::remove_if(students.begin(), students.end(),
                                  [&](const Student& student) { return student.idx_nr == idxRem; }), students.end());
}

void load_students(std::vector<Student>& students, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error with opening file: " << filename << std::endl;
        return;
    }

    students.clear(); // Czyszczenie istniejących danych
    std::string line;
    while (std::getline(file, line)) {
        Student student;
        std::istringstream iss(line);
        iss >> student.name >> student.surname >> student.sex >> student.pesel >> student.idx_nr;
        students.push_back(student);
    }

    file.close();
}

int main() {
    Student s;
    s = read_student_data();
    display_student(s);

    std::vector<Student> students = fill_students();

    for(const Student& student : students)
        display_student(student);

    std::cout << std::endl;
    return 0;
}
