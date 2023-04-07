#include "Parser.hpp"

int main(int argc, char *argv[])
{
    std::cout << "-----------------------------" << std::endl;
    //const char* url = "GET http://abc.ru/main/test/test1/test2?param1=3&param2=4";
    const char* url = "POST http://abc.ru/main/test";
    //const char* url = "GET http://abc.ru/main/test/test1/test2";
    //const char* url = "DELETE http://abc.ru/main/part2?param=3&param=4";

    Parser parser(url);
    std::cout << std::endl;
    // Print out the Domain
    std::cout << "Domain : " << parser.getDomain() << std::endl;
    std::cout << "-----------------------------";
    std::cout << "\n";

    // Get the Http Method
    Parser::HttpMethod method =  parser.getMethod();
    std::cout << "HTTP method: ";
    switch (method) {
        case Parser::HttpMethod::GET:
            std::cout << "GET" << std::endl;
            break;
        case Parser::HttpMethod::POST:
            std::cout << "POST" << std::endl;
            break;
        case Parser::HttpMethod::DELETE:
            std::cout << "DELETE" << std::endl;
            break;
        case Parser::HttpMethod::PUT:
            std::cout << "PUT" << std::endl;
            break;
    }
    std::cout << "-----------------------------";
    std::cout << "\n";
    //Print out all URL members
    std::vector<std::string> members = parser.getAllMembers();
    std::cout << "All members: " << std::endl;
    for (int i = 0; i < members.size(); i++)
        std::cout << "\t" << parser.getNthMember(i) << std::endl;

    std::cout << "-----------------------------";
    std::cout << "\n";
    //Print out all params
    std::map<std::string, std::string> paramMap = parser.getParam();
    std::map<std::string, std::string>::iterator it;
    for (it = paramMap.begin(); it != paramMap.end(); it++)
        std::cout << it->first << " : " << it->second << std::endl;

    std::cout << "-----------------------------" << std::endl;


    return (0);
    
}