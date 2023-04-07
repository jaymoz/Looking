#include "Parser.hpp"

int main(int argc, char *argv[])
{
    std::cout << "-----------------------------" << std::endl;
    //const char* url = "GET http://abc.ru/main/test/test1/test2?param1=3&param2=4";
    //const char* url = "POST http://abc.ru/main/test";
    const char* url = "GET http://abc.ru/main/test/test1/test2";
    //const char* url = "DELETE http://abc.ru/main/part2?param=3&param=4";

    try
    {
        Parser parser(url);
        std::cout << std::endl;
        // Домен
        std::cout << "Домен : " << parser.getDomain() << std::endl;
        std::cout << "-----------------------------";
        std::cout << "\n";

        // HTTP метод
        Parser::HttpMethod method =  parser.getMethod();
        std::cout << "HTTP метод: ";
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
        //Все члены UR
        std::vector<std::string> members = parser.getAllMembers();
        std::cout << "Все члены URL: " << std::endl;
        for (int i = 0; i < members.size(); i++)
            std::cout << "\t" << parser.getNthMember(i) << std::endl;

        std::cout << "-----------------------------\n";
        //метод, возвращающий map<string, string> параметров.
        std::multimap<std::string, std::string> paramMap = parser.getParam();
        if (!paramMap.empty())
        {
            std::multimap<std::string, std::string>::iterator it;
            for (it = paramMap.begin(); it != paramMap.end(); it++)
                std::cout << "{" << it->first << ", " << it->second << "}, ";

        std::cout << "\n-----------------------------" << std::endl;
        }

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    


    return (0);
    
}