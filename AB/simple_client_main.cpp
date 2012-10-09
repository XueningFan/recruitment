#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>
using namespace std;
int main(int argc,char *argv[])
{
    try
    {
        ClientSocket client_socket("localhost",30000);
        std::string command;
        std::string reply;
        while(1)
        {
            try
            {
                std::cout<<"ab> ";
                std::cin>>command;
                client_socket<<command;
                client_socket>>reply;
                std::cout<<reply;                
                if(command=="!quit")
                {
                        break;
                }                
                else if(command=="add")
                {
                    std::cin>>command;//name
                    client_socket<<command;
                    client_socket>>reply;
                    std::cout<<reply;
                    std::cin>>command;//moblie
                    client_socket<<command;
                    client_socket>>reply;
                    std::cout<<reply;  
                    std::cin>>command;//address
                    client_socket<<command;
                    client_socket>>reply;
                    std::cout<<reply;   
                }
                else if(command=="search")
                {
                    std::cin>>command;//command
                    client_socket<<command;
                    client_socket>>reply;
                    std::cout<<reply;
                    std::cin>>command;//command2
                    client_socket<<command;
                    client_socket>>reply;
                    std::cout<<reply;   
                }
                else if(command=="remove")
                {
                    std::cin>>command;//command
                    client_socket<<command;
                    client_socket>>reply;
                    std::cout<<reply;
                    std::cin>>command;//command2
                    client_socket<<command;
                    client_socket>>reply;
                    std::cout<<reply;   
                }
            }
            catch(SocketException& ){}
        }
    }
    catch (SocketException& e)
    {
        std::cout<<"Exception was caught:"<<e.description()<<"\n";
    }
    return 0;
}

