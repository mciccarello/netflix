
#ifndef exceptions_hpp
#define exceptions_hpp

#include <exception>

namespace NetflixCatalog {


class JSONException : public std::exception {
    
    const char *const detail = nullptr;
    
    virtual const char *what() const throw()
    {
        return detail;
    }
    

public:
    
    JSONException(const char * const detail) : detail(detail){
        
    }
    
};

extern JSONException jsonException;


class FileNotFoundException : public std::exception {
    
    virtual const char *what() const throw()
    {
        return "Error opening input file.";
    }
    
};

extern FileNotFoundException fileNotFoundException;



} // namespace NetflixCatalog


#endif



