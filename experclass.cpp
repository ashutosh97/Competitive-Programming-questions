#include<iostream>
using namespace std;
class utkarsh
{
    private:
    int roll;
    string sec;
    string name;
    public:
    utkarsh(int r,string s,string n)
    {
       roll=r;
       sec=s;
       name=n;
    }
    utkarsh (utkarsh &r)
    {
        roll=r.roll;
        sec=r.sec;
        name=r.name;
    }
    int setRoll(int r)
    {
        if(r>0)
        {
           roll=r;
        }
        else
        {
         r=1;
        }
        return r;  
    }
    string setSec(string s)
    {
        
        return s;
        
    }
    int getRoll(){return roll;}
    string getSec(){return sec;}
    string getName(){return name;}    
    string display()
    {
       return name;

    }

    int Roll()
    {
        return roll;
    }

    string SECTION()
    {
        return sec;
    }
};
int main()
{
    utkarsh r2(1906449,"B20","utkarsh");
    cout<<"name and sec "<< r2.display()<<endl;
    cout<<"roll "<<r2.Roll()<<endl;
    cout<<"sec is "<<r2.SECTION()<<endl;

    return 0;
}