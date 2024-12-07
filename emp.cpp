
/*=================================================================================*/
/*  @File        : main.cpp                                                        */
/*  @Description : the employee system by cpp programming                          */
/*  @Author      : Mustafa khaled Elkhokh                                          */
/*  @Date        : 4/12/2024                                                       */
/*  @mail        : mustafaelkhokhy@gmil.com                                        */
/*=================================================================================*/
#include <iostream>
#include <string>
using namespace std;
// emploees project
class Employee { // static class 
private:
//data of employees
    int Id;
    string Name;
    int Age;
    double Salary;
    char Gender;

public:
//insertion method of employees
// لاضافة وتخزين الموظفين
    void FillEmployee() { 
        cout << "Enter ID: ";
        cin >> Id;
        cout << "Enter Name: ";
        cin >> Name;
        cout << "Enter Age: ";
        cin >> Age;
        cout << "Enter Salary: ";
        cin >> Salary;
        cout << "Enter Gender (M/F): ";
        cin >> Gender;
    }
    // searching or display employee 
    // بعد تخزين الداتا لكل موظف لعرضها عند الاستدعاء
    void PrintEmployee() const {
        cout << "\nEmployee ID: " << Id;
        cout << "\nName: " << Name;
        cout << "\nAge: " << Age;
        cout << "\nSalary: " << Salary;
        cout << "\nGender: " << Gender;
        cout << "\n-----------------------";
    }
    //عند الحاجة لتغير المرتب للموظف يتم استدعاء تلك الفانكشن
    void UpdateSalary(double newSalary) {
        Salary = newSalary;
        cout << "Salary Updated Successfully!\n";
    }
    int GetAge() const { return Age; } // 
    string GetName() const { return Name; }
};
class EmployeeManager {
private:
    Employee employees[1000]; 
    int Length; 
public:
    EmployeeManager()
    {
        Length = 0;
    }
    void AddNewEmployee() {
        if (Length >= 1000) {
            cout << "Employee list is full!\n";
            return;
        }
        employees[Length].FillEmployee();
        Length++;
        cout << "Employee Added Successfully!\n";
    }
    void PrintAllEmployees() const {
        if (Length == 0) {
            cout << "No employees to display!\n";
            return;
        }
        for (int i = 0; i < Length; i++) {
            employees[i].PrintEmployee();
        }
    }

    void UpdateSalaryById() {
        //Price adjustment method by name
        string name;
        double newSalary;
        cout << "Enter Employee Name to update salary: ";
        cin >> name;
        cout << "Enter New Salary: ";
        cin >> newSalary;

        for (int i = 0; i < Length; i++) {
            if (employees[i].GetName() == name) {
                employees[i].UpdateSalary(newSalary);
                return;
            }
        }
        cout << "Employee with name " << name << " not found!\n";
    }


    void DeleteByAge() {
        int startAge, endAge;
        cout << "Enter Age Range to Delete (start and end): ";
        cin >> startAge >> endAge;

        for (int i = 0; i < Length;) {
            if (employees[i].GetAge() > startAge && employees[i].GetAge() < endAge) {
                for (int j = i; j < Length - 1; j++) {
                    employees[j] = employees[j + 1];
                }
                Length--;
            }
            else {
                i++;
            }
        }
        cout << "Employees within the specified age range have been deleted.\n";
    }
/* when you start the program the first function will show */
    void StartProgram() {
        int choice;
        //It will appear at least once.
        do { 
            cout << "\nChoose an operation:\n";
            cout << "(1) Add New Employee\n";
            cout << "(2) Print All Employees\n";
            cout << "(3) Update Salary by Name\n";
            cout << "(4) Delete by Age\n";
            cout << "(5) Exit\n";
            cin >> choice;

            switch (choice) {
            case 1:
                AddNewEmployee();
                break;
            case 2:
                PrintAllEmployees();
                break;
            case 3:
                UpdateSalaryById();
                break;
            case 4:
                DeleteByAge();
                break;
            case 5:
                cout << "Thank you for using the program!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
                break;
            }
        } while (choice != 5);
    }
};
int main() {
    EmployeeManager manager;
    manager.StartProgram();
    return 0;
}
