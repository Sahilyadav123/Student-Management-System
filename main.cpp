#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>  // for system("cls")
using namespace std;

class Student {
    private:
        int rollno, age;
        string name;
    
    public:
        Student(int stdId, string stdName, int stdAge) {
            rollno = stdId;
            name = stdName;
            age = stdAge;
        }
    
        void setRollno(int stdId) {
            rollno = stdId;
        }
    
        int getRollno() const { // <-- Make this const
            return rollno;
        }
    
        void setName(string stdName) {
            name = stdName;
        }
    
        string getName() const { // <-- Make this const
            return name;
        }
    
        void setAge(int stdAge) {
            age = stdAge;
        }
    
        int getAge() const { // <-- Make this const
            return age;
        }
    
        void displayStudent() const { // <-- Make this const
            cout << "Roll No : " << rollno << endl;
            cout << "Name    : " << name << endl;
            cout << "Age     : " << age << endl;
        }
    };
    
// Add new student
void addNewStudent(vector<Student>& students) {
    int rollno, age;
    string name;

    cout << "Enter Rollno : ";
    cin >> rollno;

    for (const auto& student : students) {
        if (student.getRollno() == rollno) {
            cout << "\t\tStudent Already Exists" << endl;
            return;
        }
    }

    cin.ignore();
    cout << "Enter Name : ";
    getline(cin, name);

    cout << "Enter Age : ";
    cin >> age;

    students.push_back(Student(rollno, name, age));
    cout << "\t\tStudent Added Successfully!" << endl;
}

// Display all students
void DisplayAllStudent(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\t\tNo Student Found" << endl;
        return;
    }

    for (const auto& student : students) {
        student.displayStudent();
        cout << "--------------------------" << endl;
    }
}

// Search a student
void SearchStudent(const vector<Student>& students) {
    int rollno;
    cout << "\t\tEnter Rollno : ";
    cin >> rollno;

    for (const auto& student : students) {
        if (student.getRollno() == rollno) {
            cout << "\t\t-------- Student Found --------" << endl;
            student.displayStudent();
            return;
        }
    }

    cout << "\t\tStudent Not Found" << endl;
}

// Update student
void updateStudent(vector<Student>& students) {
    string sname;
    bool found = false;
    int choice;

    cin.ignore();
    cout << "\t\tEnter Name to Update Record : ";
    getline(cin, sname);

    for (auto& student : students) {
        if (student.getName() == sname) {
            found = true;
            cout << "\t\t--- Student Found ---" << endl;
            cout << "\t\t1. Update Rollno" << endl;
            cout << "\t\t2. Update Name" << endl;
            cout << "\t\t3. Update Age" << endl;
            cout << "\t\tEnter Your Choice : ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    int rno;
                    cout << "\t\tEnter New Rollno : ";
                    cin >> rno;
                    student.setRollno(rno);
                    break;
                }
                case 2: {
                    string newName;
                    cin.ignore();
                    cout << "\t\tEnter New Name : ";
                    getline(cin, newName);
                    student.setName(newName);
                    break;
                }
                case 3: {
                    int age;
                    cout << "\t\tEnter New Age : ";
                    cin >> age;
                    student.setAge(age);
                    break;
                }
                default:
                    cout << "\t\tInvalid Choice" << endl;
            }
            return;
        }
    }

    if (!found) {
        cout << "\t\tRecord Not Found" << endl;
    }
}

// Delete student
void deleteStudent(vector<Student>& students) {
    string name;
    cin.ignore();
    cout << "Enter Name to Delete : ";
    getline(cin, name);

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getName() == name) {
            students.erase(it);
            cout << "\t\tStudent Removed Successfully" << endl;
            return;
        }
    }

    cout << "\t\tStudent Not Found" << endl;
}

// Main Function
int main() {
    vector<Student> students;
    students.push_back(Student(1, "Ali", 35));
    char choice;

    do {
        // system("cls"); // Use only on Windows. Commented for portability.
        int op;
        cout << "\n\t\t--------------------------------" << endl;
        cout << "\t\t*** Student Management System ***" << endl;
        cout << "\t\t--------------------------------" << endl;
        cout << "\t\t1. Add New Student" << endl;
        cout << "\t\t2. Display All Students" << endl;
        cout << "\t\t3. Search Student" << endl;
        cout << "\t\t4. Update Student" << endl;
        cout << "\t\t5. Delete Student" << endl;
        cout << "\t\t6. Exit" << endl;
        cout << "\t\tEnter Your Choice : ";
        cin >> op;

        switch (op) {
            case 1:
                addNewStudent(students);
                break;
            case 2:
                DisplayAllStudent(students);
                break;
            case 3:
                SearchStudent(students);
                break;
            case 4:
                updateStudent(students);
                break;
            case 5:
                deleteStudent(students);
                break;
            case 6:
                cout << "\t\tExiting Program..." << endl;
                exit(0);
            default:
                cout << "\t\tInvalid Choice" << endl;
        }

        cout << "\t\tDo You Want to Continue [Y/N]? : ";
        cin >> choice;
        choice = tolower(choice);

    } while (choice == 'y');

    return 0;
}
