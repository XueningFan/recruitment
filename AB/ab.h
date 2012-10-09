#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

typedef struct AddressNode{
    string person_name;
    string person_moblie_number;
    string person_address;
    struct AddressNode *next;
}AN,*ANList;

class AddressBook{
    int address_node_count;
    AN *L;
    AN *head;
public:
    string addressHelp();
    string addressInitial();
    string addressQuit();
    string addressShow();
    string addressAdd(AN q);
    string addressSearch(string command,string command2);
    string addressDelete(string command,string command2);
    AddressBook(){};
    ~AddressBook(){};
};

string AddressBook::addressInitial()
{
    address_node_count=0;
    AN *p;
    L=new AN;
    L->next=NULL;
    head=L;
 
    ifstream inputfile("addressbook.txt",ios::in);
    if(!inputfile)
    {
        cout<<"open error!"<<endl;
    }
    p=new AN;

    while(inputfile>>p->person_name>>p->person_moblie_number>>p->person_address)
    {
        p->next=L->next;
        L->next=p;
        L=p;
        this->address_node_count++;
        p=new AN;
    }

    inputfile.close();
    return "happy";
}
string AddressBook::addressShow()
{
    stringstream conv;
    string str;
    ANList p;
    p=head;
    while(p->next!=NULL)
    {
        cout<<p->next->person_name<<" "<<p->next->person_moblie_number<<" "<<p->next->person_address<<endl;
        conv<<p->next->person_name<<" "<<p->next->person_moblie_number<<" "<<p->next->person_address<<endl;
        str=conv.str();
        p=p->next;
    }    
    //cout<<conv.str();
    str=conv.str();
    return str;
}
string AddressBook::addressQuit()
{
    if(address_node_count==0)
    {
        return "node_num is zero!";
    }

    ofstream outputfile("addressbook.txt",ios::out);
    if(!outputfile)
    {
        cout<<"open error!"<<endl;
        return "open error!";
    }

    ANList p;
    p=head;
    cout<<address_node_count<<endl;

    while(p->next!=NULL)
    {
        AN *q;
        cout<<p->next->person_name<<" "<<p->next->person_moblie_number<<" "<<p->next->person_address<<endl;
        outputfile<<p->next->person_name<<" "<<p->next->person_moblie_number<<" "<<p->next->person_address<<endl;
        q=p;
        p=p->next;
        delete q;
    }
    outputfile.close();
    return "quit finished\n";
}

string AddressBook::addressHelp()
{
    cout<<"help..."<<endl;
    return "help...\n";
}

string AddressBook::addressAdd(AN q)
{
    AN *p;
    p=new AN;

    p->person_name=q.person_name;
    p->person_moblie_number=q.person_moblie_number;
    p->person_address=q.person_address;
    cout<<p->person_name<<" "<<p->person_moblie_number<<" "<<p->person_address<<endl;

    p->next=L->next;
    L->next=p;
    L=p;
    addressShow();
    address_node_count++;

    return "address entry added\n";
}

string AddressBook::addressSearch(string command,string command2)
{
    stringstream conv;
    string str;
    ANList p;
    p=head;

    if(command=="name")
    {
        if(address_node_count==0)
        {
            str="no record\n";
            return str;
        }
        while(p->next!=NULL)
        {
            if(command2==p->next->person_name)
            {
                cout<<p->next->person_name<<" "<<p->next->person_moblie_number<<" "<<p->next->person_address<<endl;
                conv<<p->next->person_name<<" "<<p->next->person_moblie_number<<" "<<p->next->person_address<<endl;
            }
            p=p->next;
        }
    }
    else if(command=="moblie")
    {
        if(address_node_count==0)
        {
            str="no record\n";
            return str;
        }
        while(p->next!=NULL)
        {
            if(command2==p->next->person_moblie_number)
            {
                cout<<p->next->person_name<<" "<<p->next->person_moblie_number<<" "<<p->next->person_address<<endl;
                conv<<p->next->person_name<<" "<<p->next->person_moblie_number<<" "<<p->next->person_address<<endl;
            }
            p=p->next;
        }
    }
    else if(command=="address")
    {
        if(this->address_node_count==0)
        {
            str="no record\n";
            return str;
        }
        while(p->next!=NULL)
        {
            if(command2==p->next->person_address)
            {
                cout<<p->next->person_name<<" "<<p->next->person_moblie_number<<" "<<p->next->person_address<<endl;
                conv<<p->next->person_name<<" "<<p->next->person_moblie_number<<" "<<p->next->person_address<<endl;
            }
            p=p->next;
        }
    }
    else
    {
        cout<<"wrong command !\n"<<endl;
        conv<<"wrong command !\n"<<endl;
    }
    str=conv.str();
    return str;
}

string AddressBook::addressDelete(string command,string command2)
{
    stringstream conv;
    string str;
    ANList p;
    p=head;

    if(command=="name")
    {
        if(address_node_count==0)
        {
            str="no record\n";
            return str;
        }
        while(p->next!=NULL)
        {
            if(command2==p->next->person_name)
            {
                AN *q=new AN;
                q=p->next;
                cout<<p->next->person_name<<" "<<p->next->person_moblie_number<<" "<<p->next->person_address<<endl;
                conv<<p->next->person_name<<" "<<p->next->person_moblie_number<<" "<<p->next->person_address<<endl;
                p->next=p->next->next;
                delete q;
                address_node_count--;
                continue;                
            }
            p=p->next;
        }
    }
    else if(command=="moblie")
    {
        if(address_node_count==0)
        {
            str="no record\n";
            return str;
        }
        while(p->next!=NULL)
        {
            if(command2==p->next->person_moblie_number)
            {
                AN *q=new AN;
                q=p->next;
                cout<<p->next->person_name<<" "<<p->next->person_moblie_number<<" "<<p->next->person_address<<endl;
                conv<<p->next->person_name<<" "<<p->next->person_moblie_number<<" "<<p->next->person_address<<endl;
                p->next=p->next->next;
                delete q;
                address_node_count--;
                continue;   
            }
            p=p->next;
        }
    }
    else if(command=="address")
    {
        if(this->address_node_count==0)
        {
            str="no record\n";
            return str;
        }
        while(p->next!=NULL)
        {
            if(command2==p->next->person_address)
            {
                AN *q=new AN;
                q=p->next;
                cout<<p->next->person_name<<" "<<p->next->person_moblie_number<<" "<<p->next->person_address<<endl;
                conv<<p->next->person_name<<" "<<p->next->person_moblie_number<<" "<<p->next->person_address<<endl;
                p->next=p->next->next;
                delete q;
                address_node_count--;
                continue;   
            }
            p=p->next;
        }
    }
    else
    {
        cout<<"wrong command !\n"<<endl;
        conv<<"wrong command !\n"<<endl;
    }
    str=conv.str();
    return str;
}
