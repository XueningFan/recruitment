#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>
#include "ab.h"

using namespace std;

int main(int argc,char *argv[])
{
    std::cout << "running....\n";
    try
    {
        ServerSocket server(30000);
        while(true)
        {
            ServerSocket new_sock;
            server.accept(new_sock);
            try
            {                    
                AddressBook AB;
                AB.addressInitial();
                while(true)
                {
                    
                    std::string command;
                    std::string data;
                    new_sock>>command;                  

                    if(command=="!quit")
                    {
                        data=AB.addressQuit();
                        new_sock<<data;
                        break;
                    }
                    else if(command=="!help")
                    {
                        data=AB.addressHelp();
                        new_sock<<data;
                    }
                    else if(command=="show")
                    {
                        data=AB.addressShow();
                        new_sock<<data;
                    }
                    else if(command=="add")
                    {
                        AN p;
                        new_sock<<"name: ";
                        new_sock>>p.person_name;
                        new_sock<<"moblie: ";
                        new_sock>>p.person_moblie_number;
                        new_sock<<"address: ";
                        new_sock>>p.person_address;                                             
                        new_sock<<AB.addressAdd(p);
                    }
                    else if(command=="search")
                    {
                        std::string command2,command3;
                        new_sock<<"by (name|moblie|address): ";
                        new_sock>>command2;
                        if(command2=="name")
                        {
                            new_sock<<"name: ";
                            new_sock>>command3;
                        }
                        else if(command2=="moblie")
                        {
                            new_sock<<"moblie: ";
                            new_sock>>command3;
                        }
                        else if(command2=="address")
                        {
                            new_sock<<"address: ";
                            new_sock>>command3;
                        }                                            
                        new_sock<<AB.addressSearch(command2,command3);
                    }
                    else if(command=="remove")
                    {
                        std::string command2,command3;
                        new_sock<<"by (name|moblie|address): ";
                        new_sock>>command2;
                        if(command2=="name")
                        {
                            new_sock<<"name: ";
                            new_sock>>command3;
                        }
                        else if(command2=="moblie")
                        {
                            new_sock<<"moblie: ";
                            new_sock>>command3;
                        }
                        else if(command2=="address")
                        {
                            new_sock<<"address: ";
                            new_sock>>command3;
                        }                                            
                        new_sock<<AB.addressDelete(command2,command3);
                    }
                    else
                    {
                        data="wrong input\n";
                        new_sock<<data;
                    }
                }
            }
            catch ( SocketException& ) {}
        }
    }
    catch ( SocketException& e )
    {
        std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }
    return 0;
}

