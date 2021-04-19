//
//  video.hpp
//  netflix
//
//  Created by Mark Ciccarello on 4/18/21.
//

#ifndef video_hpp
#define video_hpp

#include <string>
#include <vector>
#include <map>
#include "json.hpp"

using std::string;
using std::vector;
using std::map;
using std::unique_ptr;
using nlohmann::json;

namespace NetflixCatalog {




struct VideoMembers;

class Video {
       
    unique_ptr<struct VideoMembers> members;
    
public:
    
    Video();
    Video(Video const &);
    ~Video();
    
    string const & getName() const;
    vector<string> const & getCountries() const;
    string const & getLanguage() const;
    string const & getAspect() const;

    
    void deserialize(map<string, json> const &jsonMap);
    
    
};

} // namespace NetflixCatalog

#endif /* video_hpp */
