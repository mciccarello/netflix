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
#include <set>
#include "json.hpp"

using std::string;
using std::vector;
using std::map;
using std::shared_ptr;
using std::set;
using nlohmann::json;

namespace NetflixCatalog {


struct VideoMemberData;

class Video {
       
    
    string name;
    set<string> countries;
    string language;
    string aspect;
    
    
public:
        
    string const & getName() const { return name; }
    set<string> const & getCountries() const { return countries; }
    string const & getLanguage() const { return language; }
    string const & getAspect() const { return aspect; }

    
    void deserialize(map<string, json> const &jsonMap);
    
    
};

} // namespace NetflixCatalog

#endif /* video_hpp */
