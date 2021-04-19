//
//  preroll.hpp
//  netflix
//
//  Created by Mark Ciccarello on 4/18/21.
//

#ifndef preroll_hpp
#define preroll_hpp

#include <string>
#include <vector>
#include <map>
#include "json.hpp"
#include "video.hpp"

using std::string;
using std::vector;
using std::map;
using nlohmann::json;

namespace NetflixCatalog {

class Preroll {
    
    string name;
    vector<Video> videos;
    
public:
    
    string const & getName() const { return name; }
    vector<Video> const & getVideos() const { return videos; }
    
    void deserialize(map<string, json> const &jsonMap);

};

} // namespace NetflixCatalog

#endif /* preroll_hpp */
