#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
vector<float> gpt;

void gradepoint(int marks)
{

    if (marks >= 90 && marks < 100)
    {
        gpt.push_back(10);
    }

    else if (marks >= 80 && marks < 90)
    {
        gpt.push_back(9);
    }

    else if (marks >= 70 && marks < 80)
    {
        gpt.push_back(8);
    }

    else if (marks >= 60 && marks < 70)
    {
        gpt.push_back(7);
    }

    else if (marks >= 50 && marks < 60)
    {
        gpt.push_back(6);
    }

    else if (marks >= 45 && marks < 50)
    {
        gpt.push_back(5);
    }

    else if (marks >= 40 && marks < 45)
    {
        gpt.push_back(4);
    }

    else if (marks < 40)
    {
        gpt.push_back(0);
    }
    else if(marks > 100){
        gpt.push_back(0);
    }

   
}
float cg()
{
    float cg;
    cg = (gpt.at(0) * 5 + gpt.at(1) * 4 + gpt.at(2) * 3 + gpt.at(3) * 3 + gpt.at(4) * 2) / 17;
    return cg;
}

class Student
{
protected:
public:
    string first_name, last_name, roll;
    int  chem, icse, oops, math, pc;
    void set_name()
    {
        cout << "Enter the first name: ";
        cin >> first_name;

        cout<<"Enter the last name: ";
        cin>>last_name;
    }

    void set_roll()
    {
        cout << "Enter your roll number: ";
        cin >> roll;
    }
};

class Subject : public Student
{
public:
    void set_math()
    {
        cout << "Enter marks scored in Mathematics: ";
        cin >> math;
        gradepoint(math);
    }

    void set_chem()
    {
        cout << "Enter marks scored in Applied Chemistry: ";
        cin >> chem;
        gradepoint(chem);
    }

    void set_icse()
    {
        cout << "Enter marks scored in Introduction to Computer Science: ";
        cin >> icse;
        gradepoint(icse);
    }

    void set_oops()
    {
        cout << "Enter marks scored in Object Oriented Programming: ";
        cin >> oops;
        gradepoint(oops);
    }

    void set_pc()
    {
        cout << "Enter marks scored in Professional Communication: ";
        cin >> pc;
        gradepoint(pc);
    }
};

int main()
{
    char trigger = 'Y';
    while (trigger == 'Y')
    {
        Student s1;
        Subject sub;

        s1.set_name();
        s1.set_roll();

        sub.set_math();
        sub.set_chem();
        sub.set_icse();
        sub.set_oops();
        sub.set_pc();
         
        cout << "Your CGPA is: " << cg() <<endl;

       
        ofstream output("Result.txt", ios ::app);
        output<< "\n\n" << s1.first_name <<" "<<s1.last_name<< "\t\t" << s1.roll << "\t\t" << sub.math << "\t\t" << sub.chem << "\t\t" << sub.icse << "\t\t" << sub.oops << "\t\t" << sub.pc << "\t\t" << cg();
        output.close();
         cout<<"The Report card has been generated."<<endl;

        cout << "Do you want to calculate the result of another student? Y/N" << endl;
        cin >> trigger;
        
        gpt.clear();
    }

    return 0;
}