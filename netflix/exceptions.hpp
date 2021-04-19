
#ifndef exceptions_hpp
#define exceptions_hpp

#include <exception>

namespace NetflixCatalog {


class JSONException : public std::exception {
    
    virtual const char *what() const throw()
    {
        return "Error parsing JSON";
    }
    
};

extern JSONException jsonException;


} // namespace NetflixCatalog


#endif



