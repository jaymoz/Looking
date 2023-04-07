#include <iostream>
#include <string>
#include <map>
#include <vector>

class Parser
{
    public:
        Parser(const char *url);//Конструктор. В конструктор класса передается URL строка типа const char *
        ~Parser();
        enum class HttpMethod : unsigned char
        {
            POST,GET,DELETE,PUT
        };
        void                                processUrl(void);
        std::string                         getNthMember(int index); //Получение N-ого члена URL. Параметр - индекс нужного члена URL после имени домена.
        void                                setMembers(void);
        void                                setParam(int param_index);
        HttpMethod                          getMethod(void) const; //Получение HTTP метода в ENUM. Одно из значений: POST / GET / DELETE / PUT
        std::multimap<std::string, std::string>  getParam(void) const; //Задание со звездочкой (по желанию):Реализовать метод, возвращающий map<string, string> параметров.
        std::vector<std::string>            getAllMembers(void) const;
        std::string                         getDomain(void) const;
        bool                                checker(void);

    private:
        std::string                             _url;
        std::string                             _domain;
        std::string                             _path;
        std::multimap<std::string, std::string> _param;
        std::vector<std::string>                _members;
        HttpMethod                              _httpMethod;

};