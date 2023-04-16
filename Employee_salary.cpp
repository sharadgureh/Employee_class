/**
 * @file Employee.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-03-16
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
using namespace std;
class Employee
{
    string E_name;
    int E_id;

public:
    // contructor
    Employee(string name, int id)
    {
        E_name = name;
        E_id = id;
    }

    // acessor and mulator
    void setName(string name) { E_name = name; } // setter or mutator for name
    string getName() { return E_name; }          // Getter or accesser for name
    void setID(int id) { E_id = id; }            // setter or mutator for id
    int getID() { return E_id; }                 // Getter or accesser for id
};
class salary_base : public Employee
{
    int salary;
    string Joining;
    string Ending;

public:
    // constructor
    // this contructor call for parent class constructor with argument
    salary_base(string name = NULL, int id = 0, int salary = 0) : Employee(name, id)
    {
        this->salary = salary;
    }
    // getter or accesser for salary of salary_base employees
    int getSalary() { return salary; }
    // setter or mutator for salary of salary_base employees
    void setSalary(int salary) { this->salary = salary; }

    //    for joining date
    void setJoining(string join) { this->Joining = join; }
    string getJoining() { return Joining; }
    //  for ending date
    void setEnding(string End) { this->Ending = End; }
    string getending() { return Ending; }

    void show_info_salary_base()
    {
        cout << "The name of Employee is:-" << getName() << endl;
        cout << "The ID of Employee is :-" << getID() << endl;
        cout << "The joining date is :-" << getJoining() << endl;
        cout << "The ending date is :-" << getending() << endl;
        cout << "The salary of " << getName() << " is:-" << getSalary() << endl;
    }
};

class daily_base : public Employee
{
    int How_Many_Days;
    int Per_Days_pay;
    int total;

public:
    // constructor
    daily_base(string name = NULL, int id = 0, int days = 0, int pay_day = 0) : Employee(name, id)
    {
        How_Many_Days = days;
        Per_Days_pay = pay_day;
    }

    // set days
    void setHow_Many_Days(int day)
    {
        this->How_Many_Days = day;
    }

    // get day
    int getHow_Many_Days() { return How_Many_Days; }

    // set per day
    void setPer_day_pay(int pay) { this->Per_Days_pay = pay; }

    //  get total amount of dihadi
    int getTotal() { return total; }
    int Total_a() { return How_Many_Days * Per_Days_pay; }
    void show_info_daily_base()
    {
        cout << "the name of Employee is:-" << getName() << endl;
        cout << "the ID of Employee is :-" << getID() << endl;
        cout << "the day you work is :-" << How_Many_Days << endl;
        cout << "per day payout is :-" << Per_Days_pay << endl;
        cout << "total dihadi of  (Employee:-" << getName() << ") is :-" << Total_a() << endl;
    }
};

// main()

int main()
{
    system("cls");
    int select;
    char option;
again:
flag:

    cout << endl;
    do
    {
        cout << "***WELCOME***" << endl;
        cout << "***MAIN MENU***" << endl;
        cout << "***SELECT THE OPTION TO PERFORM ACTION***" << endl;
        cout << "***1-EMPLOYEE_ON_SALARY***" << endl;
        cout << "***2-EMPLOYEE_ON_DAILY_BASE***" << endl;
        cout << "_____________________________________________________________________________________" << endl;
        cin >> select;
        switch (select)
        {
        case 1:
        {
            string n1, join, end;
            char op1;
            int id, sal, select1;

            cout << "***Salary_Base_Employee***" << endl;
            cout << "***Enter The Details In Blow Order:" << endl;
            cout << "1-Employee_Name\n2-Employee_id\n3-Salary" << endl;

            cin >> n1 >> id >> sal;
            salary_base stud(n1, id, sal);
            do
            {
                cout << "***1-Enter the Joining Date***" << endl;
                cout << "***2-Enter the Ending Date***" << endl;
                cout << "***3-Show Details Of Employee***" << endl;
                cout << "__________________________________________________" << endl;
                cin >> select1;
                switch (select1)
                {
                case 1:
                    cin >> join;
                    stud.setJoining(join);
                    break;
                case 2:
                    cin >> end;
                    stud.setEnding(end);
                case 3:
                    stud.show_info_salary_base();
                    goto again;
                }

                cout << "Again ? (y/n):-";
                fflush(stdin);
                cin >> op1;
            } while (op1 == 'y' || op1 == 'n');
            break;
        }
        case 2:
            string n;
            char op2;
            int day, id2, per, per2, select2, d1;

            cout << "***Daily_Base_Employee***" << endl;
            cout << "***Enter The Details In Blow Order:" << endl;
            cout << "1-Employee_Name\n2-Employee_id\n3-How_Many_days\n4-Per_day_Amount" << endl;

            cin >> n >> id2 >> day >> per;
            daily_base s(n, id2, day, per);
            do
            {
                cout << "***1-Update a Number of day***" << endl;
                cout << "***2-Update a Amount of day***" << endl;
                cout << "***3-Show Details Of Employee***" << endl;
                cout << "__________________________________________________" << endl;
                cin >> select2;
                switch (select2)
                {
                case 1:
                    cout << "Enter the number of days:-";
                    cin >> d1;
                    s.setHow_Many_Days(d1);
                    break;
                case 2:
                    cout << "Enter the Amount :-";
                    cin >> per2;
                    s.setPer_day_pay(per2);
                case 3:
                    s.show_info_daily_base();
                    goto flag;
                }

                cout << "Again ? (y/n):-";
                fflush(stdin);
                cin >> op2;
            } while (op2 == 'y' || op2 == 'n');
            break;
        }
        cout << "again? (yes/no):-";
        fflush(stdin);
        cin >> option;
    } while (option == 'y' || option == 'n');

    return 0;
}