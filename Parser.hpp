#include <iostream>
#include <string>
#include <map>
#include <vector>

class Parser
{
    public:
        Parser(const char *url);
        ~Parser();
        Parser(const Parser &other);
        enum class HttpMethod : unsigned char
        {
            POST,GET,DELETE,PUT
        };
        void                                processUrl(void);
        std::string                         getNthMember(int index);
        void                                setMembers(void);
        void                                setParam(int param_index);
        HttpMethod                          getMethod() const;
        std::map<std::string, std::string>  getParam() const;
        std::vector<std::string>            getAllMembers() const;
        std::string                         getDomain() const;

    private:
        std::string _url;
        std::string _domain;
        std::string _path;
        std::map<std::string, std::string> _param;
        std::vector<std::string> _members;
        HttpMethod _httpMethod;

};