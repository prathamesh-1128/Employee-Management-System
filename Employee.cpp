#include<iostream>
#include<string.h>
using namespace std;


typedef struct Employee
{
    int EID;
    char EName[20];
    char ECity[20];
    char EGender;
    int EAge;
    int ESalary;
    struct Employee *next;
}NODE,*PNODE;

class SinglyLL
{
    private:
    PNODE Head;
    int iSize;

    public:
             SinglyLL();
    void InsertFirst();
    void InsertLast();
    void Display();
    int Count();
    void InsertAtPos(int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void MaxSalary();
    int EAvgSalary();
    int EAvgAge();
    int CountByAge(int);
    void Update(int);  


};

SinglyLL::SinglyLL()
{
    Head=NULL;
    iSize=0;
}


inline int SinglyLL::Count()
{
   return iSize;
}

void SinglyLL::MaxSalary()
{
    PNODE temp=Head;
    PNODE temp2=NULL;
    int Salary=0;
    while(temp!=NULL)
    {
        if((temp->ESalary)>Salary)
        {
            Salary=temp->ESalary;
            temp2=temp;
        }

        temp=temp->next;
    }
    cout<<"Employee having Maximum Salary\n";
    cout<<"Employee ID:"<<temp2->EID<<"  "<<"Name:"<<temp2->EName<<"  ";
    cout<<"Working City:"<<temp2->ECity<<"  "<<"Gender:"<<temp2->EGender<<"  ";
    cout<<"Age:"<<temp2->EAge<<"  "<<"Salary:"<<temp2->ESalary<<"\n";
}

void SinglyLL::Display()
{
    PNODE temp=Head;

    while(temp !=NULL)
    {
        cout<<"Employee ID:"<<temp->EID<<"  "<<"Name:"<<temp->EName<<"  ";
        cout<<"Working City:"<<temp->ECity<<"  "<<"Gender:"<<temp->EGender<<"  ";
        cout<<"Age:"<<temp->EAge<<"  "<<"Salary:"<<temp->ESalary<<"\n";

        temp=temp->next;
        cout<<"\n";
    }
}


void SinglyLL::InsertFirst()
{
    PNODE newn=new NODE;
    newn->next=NULL;
    cout<<"Enter your ID\n";
    cin>>newn->EID;
    cout<<"Enter your Name\n";
    cin>>newn->EName;
    cout<<"Enter your City\n";
    cin>>newn->ECity;
    cout<<"Enter your Gender M:Male F:Female\n";
    cin>>newn->EGender;
    cout<<"Enter your Age\n";
    cin>>newn->EAge;
    cout<<"Enter your Salary\n";
    cin>>newn->ESalary;

    if(Head==NULL)
    {
        Head=newn;
    }

    else
    {
        newn->next=Head;
        Head=newn;
    }
    iSize++;
}

void SinglyLL::InsertLast()
{
     PNODE newn=new NODE;
    newn->next=NULL;
    cout<<"Enter your ID\n";
    cin>>newn->EID;
    cout<<"Enter your Name\n";
    cin>>newn->EName;
    cout<<"Enter your City\n";
    cin>>newn->ECity;
    cout<<"Enter your Gender M:Male F:Female\n";
    cin>>newn->EGender;
    cout<<"Enter your Age\n";
    cin>>newn->EAge;
    cout<<"Enter your Salary\n";
    cin>>newn->ESalary;

    if(Head==NULL)
    {
        Head=newn;
    }

    else
    {
        PNODE temp=Head;
        while(temp->next !=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
    iSize++;
    
}

void SinglyLL::InsertAtPos(int iPos)
{
    if((iPos<0) || (iPos>iSize+1))
    {
        return;
    }

    if(iPos==1)
    {
        InsertFirst();
    }

    else if(iPos==iSize+1)
    {
        InsertLast();
    }

    else
    {
        PNODE newn=new NODE;
    newn->next=NULL;
    cout<<"Enter your ID\n";
    cin>>newn->EID;
    cout<<"Enter your Name\n";
    cin>>newn->EName;
    cout<<"Enter your City\n";
    cin>>newn->ECity;
    cout<<"Enter your Gender M:Male F:Female\n";
    cin>>newn->EGender;
    cout<<"Enter your Age\n";
    cin>>newn->EAge;
    cout<<"Enter your Salary\n";
    cin>>newn->ESalary;
    PNODE temp=Head;

    for(int i=1;i<iPos-1;i++)
    {
        temp=temp->next;
    }

    newn->next=temp->next;
    temp->next=newn;
        iSize++;
    }
    
}

int SinglyLL::EAvgSalary()
{
    PNODE temp=Head;
    int iSum=0;

    while(temp!=NULL)
    {
        iSum=iSum+(temp->ESalary);

        temp=temp->next;
    }
    return(iSum/iSize);
}

int SinglyLL::EAvgAge()
{
    PNODE temp=Head;
    int iAge=0;
    while(temp!=NULL)
    {
        iAge=iAge+(temp->EAge);
        temp=temp->next;

    }
    return(iAge/iSize);
}

int SinglyLL::CountByAge(int Age) //Counting employess whose age is more than entered Age
{
    PNODE temp=Head;
    int iCnt=0;

    while(temp !=NULL)
    {
        if((temp->EAge)>=Age)
        {
            iCnt++;
        }
        temp=temp->next;
    }
    return iCnt;
}

void SinglyLL::Update(int ID)
{
    PNODE newn=new NODE;
    newn->next=NULL;
    int choice=0;
    PNODE temp=Head;
    
        cout<<"1:To update Salary\n";
        cout<<"2:To update City\n";
        cout<<"0:Stop\n";
        cout<<"Enter Choice\n";
        cin>>choice;

        switch(choice)
        {
        case 1:
        cout<<"Enter updated salary\n";
        cin>>newn->ESalary;
        break;

        case 2:
        cout<<"Enter new city name\n";
        cin>>newn->ECity;
        break;

        case 0:
        break;

        default:
        cout<<"Error\n";
        }

        while(temp!=NULL)
        {

            if((temp->EID==ID)&&(choice==1))
            {
                temp->ESalary=newn->ESalary;
                
            }

            else if((temp->EID==ID)&&(choice==2))
            {
                strcpy(temp->ECity,newn->ECity);
            }

            else
            {
                cout<<"Entered ID is not in List\n";
            }
            temp=temp->next;
        }

}

void SinglyLL::DeleteFirst()
{
    if(Head==NULL)
    {
        return;
    }

    else
    {
        PNODE temp=Head;
        Head=Head->next;
        delete temp;
    }
    iSize--;
    
}

void SinglyLL::DeleteLast()
{
    if(Head==NULL)
    {
        return;
    }

    PNODE temp=Head;
    while(temp->next->next !=NULL)
    {
        temp=temp->next;
    }

    delete temp->next;
    temp->next=NULL;
    iSize--;
}

void SinglyLL::DeleteAtPos(int iPos)
{
    if((iPos<0)||(iPos>iSize))
    {
        return;
    }

    if(iPos==1)
    {
        DeleteFirst();
    }

    else if(iPos==iSize)
    {
        DeleteLast();
    }

    else
    {
        PNODE temp=Head;
        PNODE temp2=NULL;
        for(int i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }

        temp2=temp->next;
        temp->next=temp2->next;
        delete temp2;
        iSize--;

    }
    
}


int main()
{
    SinglyLL obj;
    PNODE First=NULL;

    int choice=1,iPos=0,iRet=0,Age=0,ID=0;
    

    while(choice!=0)
    {
        cout<<"*******************\n";
        cout<<"Enter Choice\n\n";
        cout<<"1:Insert As fresher\n";
        cout<<"2:Enter as Experienced\n";
        cout<<"3:Enter as Intermidate\n";
        cout<<"4:Delete Fresher\n";
        cout<<"5:Delete Experienced\n";
        cout<<"6:Delete Intermidate\n";
        cout<<"7:Display Information of Employees\n";
        cout<<"8:Count of Employee\n";
        cout<<"9:Information of Employee with Maximum Salaray\n";
        cout<<"10:Average Salary in Company\n";
        cout<<"11:Average Age of Employees\n";
        cout<<"12:Display Age By Condition\n";
        cout<<"13:Update information\n";
        cout<<"0:Exit\n\n";
        cout<<"*******************\n";
        
        cin>>choice;

        switch(choice)
        {
            case 1:
            obj.InsertFirst();
            break;

            case 2:
            obj.InsertLast();
            break;

            case 3:
            cout<<"Enter Position\n";
            cin>>iPos;
            obj.InsertAtPos(iPos);
            break;

            case 4:
            obj.DeleteFirst();
            break;

            case 5:
            obj.DeleteLast();
            break;

            case 6:
            cout<<"Enter Position\n";
            cin>>iPos;
            obj.DeleteAtPos(iPos);
            break;

            case 7:
            obj.Display();
            break;

            case 8:
            cout<<"Count is:"<<obj.Count()<<"\n";
            break;

            case 9:
            obj.MaxSalary();
            break;

             case 10:
            iRet=obj.EAvgSalary();
            cout<<"Average Salary:"<<iRet<<"\n";
            break;

            case 11:
            iRet=obj.EAvgAge();
            cout<<"Average of Employess is:"<<iRet<<"\n";
            break;

            case 12:
            cout<<"Enter Age\n";
            cin>>Age;
            iRet=obj.CountByAge(Age);
            cout<<"Count of Employees which are having more age than "<<Age<<" is:"<<iRet<<"\n";
            break;

            case 13:
            cout<<"Enter Employee ID who's information you want to change\n";
            cin>>ID;
            obj.Update(ID);
            break;
            
            case 0:
            cout<<"Thanks\n";
            break;

            default:
            cout<<"Error\n";

        }
    }

    cout<<"*******************\n";
    return 0;
}
