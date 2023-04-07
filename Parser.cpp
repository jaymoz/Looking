#include "Parser.hpp"

Parser::Parser(const char *url) : _url(url)
{
    Parser::processUrl();

}

Parser::~Parser(){};

Parser::Parser(const Parser &other)
{

}

Parser::HttpMethod Parser::getMethod() const { return this->_httpMethod; }

void Parser::processUrl(void)
{
    std::string method = this->_url.substr(0, _url.find(' '));
    if (method == "GET")
        this->_httpMethod = Parser::HttpMethod::GET;
    else if (method == "POST")
        this->_httpMethod = Parser::HttpMethod::POST;
    else if (method == "PUT")
        this->_httpMethod = Parser::HttpMethod::PUT;
    else if (method == "DELETE")
        this->_httpMethod = Parser::HttpMethod::DELETE;

    size_t domain_index = this->_url.find("://") + 3;
    size_t path_index = this->_url.find('/', domain_index);
    size_t param_index = this->_url.find('?', path_index);

    this->_domain = this->_url.substr(domain_index, path_index - domain_index);
    this->_path = this->_url.substr(path_index, param_index - path_index);
    Parser::setParam(param_index);
    Parser::setMembers();
}


void    Parser::setMembers(void)
{
    size_t start = 0;
    size_t end = this->_path.find('/', start);
    while (end != std::string::npos)
    {
        this->_members.push_back(this->_path.substr(start, end -start));
        start = end + 1;
        end = this->_path.find('/', start);
    }
    this->_members.push_back(this->_path.substr(start));
}

void    Parser::setParam(int param_index)
{
    if (param_index < this->_url.length())
    {
        std::string param = this->_url.substr(param_index + 1);
        size_t start = 0;
        while (start < param.length())
        {
            size_t end = param.find('&', start);
            if (end == std::string::npos)
                end = param.length();
            size_t equal_sign_index = param.find('=', start);
            if (equal_sign_index != std::string::npos && equal_sign_index < end)
            {
                std::string key = param.substr(start, equal_sign_index - start);
                std::string val = param.substr(equal_sign_index + 1, end - equal_sign_index - 1);
                this->_param.insert({key, val});
            }
            start = end + 1;
        }
    }
}

std::string Parser::getNthMember(int index)
{
    if (index >= this->_members.size())
        throw std::out_of_range("Index out of range");
    
    return (this->_members[index]);
}

std::map<std::string, std::string>  Parser::getParam() const
{
    return (this->_param);
}

std::vector<std::string>    Parser::getAllMembers() const
{
    return this->_members;
}

std::string     Parser::getDomain() const
{
    return this->_domain;
}