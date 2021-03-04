#include<iostream>
using namespace std;


/*--abstraction--*/
class abstractEmployee{
    virtual void Askforpromotion() = 0;
};

class Employee:abstractEmployee{
private:
    string Company;
    int Age;

protected:
    string Name;

public:
    void setName(string name){//setter
        Name = name;
    }
    string getName(){//getter
        return Name;
    }
    void setCompany(string company){//setter
        Company = company;
    }
    string getCompany(){//getter
        return Company;
    }
    void setAge(int age){//setter
        if(age>=18)
        Age = age;
    }
    int getAge(){//getter
        return Age;
    }

    void InterduceYourSelf(){
        cout<<"Name = "<<Name<<endl;
        cout<<"companyname = "<<Company<<endl;
        cout<<"Age = "<<Age<<endl;
    }
    Employee(string name, string company, int age){
        Name =  name;
        Company = company;
        Age = age;
    }
    void Askforpromotion(){
        if(Age > 30)
            cout<<Name<<" got promoted" << endl;
        else
            cout<<Name<<" sorry!! no promotion"<<endl;
    }
/*--Polymorphism--*/
    virtual void Work(){
        cout<<Name<<" is checking email,testbacklog, performming tasks... "<<endl;
    }
};

/*--Inheritance--*/
class Developer:public Employee{
public:
    string FavProgrammingLanguage;
    Developer(string name, string company, int age, string favProgrammingLanguage)
        :Employee(name,company, age)
    {
        FavProgrammingLanguage = favProgrammingLanguage;
    }
    void fixBugg(){
        cout<<Name<<" fixed bug using "<<FavProgrammingLanguage<<endl;
    }
/*--Polymorphism--*/
    /*void Work(){
        cout<<Name<<" is writting... "<<FavProgrammingLanguage<<endl;
    }*/
};

class Teacher:public Employee{
public:
    string Subject;
    void prepareLesson(){
        cout<<Name<<" is preparing "<<Subject<<" lessons "<<endl;
    }
    Teacher(string name, string company, int age, string subject)
        :Employee(name,company, age)
    {
        Subject = subject;
    }
/*--Polymorphism--*/
    void Work(){
        cout<<Name<<" is teaching... "<<Subject<<endl;
    }
};

int main()
{
/*--constructrs--*/
    Employee employee1 = Employee("Rony", "code-for-code", 21);
/*--Class and objects--*/
    // employee1.Name = "Rony";
    // employee1.Company = "Code-for-code";
    // employee1.Age = 21;
    //employee1.InterduceYourSelf();

    Employee employee2 = Employee("Jhon", "Amazon", 35);
   // employee2.Name = "Jhon";
   // employee2.Company ="Amazon";
   // employee2.Age = 35;
   //employee2.InterduceYourSelf();

/*--encaptulations--*/
    //employee1.setAge(9);
    //cout<<employee2.getName()<<" is "<<employee2.getAge()<<" years old"<<endl;

    //employee1.Askforpromotion();
    //employee2.Askforpromotion();
/*--Inheritance--*/
    Developer d = Developer("sam", "facebook",26,"cpp");
    //d.fixBugg();
    //d.Askforpromotion();
    Teacher t = Teacher("jack", "code-school", 35, "history");
    //t.prepareLesson();
    //t.Askforpromotion();

    //the most common use of polymorphism is when a
    //parent class referance is used to refer to a child class object

/*--Polymorphism--*/
    //d.Work();
    //t.Work();

    Employee *e1 = &d;
    Employee *e2 = &t;

    e1->Work();
    e2->Work();
}


