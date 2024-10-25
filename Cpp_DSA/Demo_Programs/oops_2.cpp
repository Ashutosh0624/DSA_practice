#include<iostream>
#include<string>
using namespace std;
class PersonType{
    public:
        void print() const;
        void setName(string fname, string lname);
        string getFname() const;
        string getLname() const;
        PersonType() {}
        PersonType(string fname, string lname)
            : fname{fname},
              lname{lname} {}
    private:
        string fname;
        string lname;
};

void PersonType::print() const{
    cout<<"First name : "<<fname<<"   "<<"Second name :"<<lname<<endl;
}

string PersonType::getFname() const{
    return fname;
}

string PersonType::getLname() const{
    return lname;
}

void PersonType::setName(string fname, string lname)
{
    this->fname = fname;
    this->lname = lname;
}

int main()
{
    PersonType p1{"Ashutosh", "Tiwari"};
    p1.print();
    cout<<"First name : "<<p1.getFname()<<endl;
    cout<<"Second name : "<<p1.getLname()<<endl;
    p1.setName("Ashish", "Tiwari");
    p1.print();
    return 0; 
}