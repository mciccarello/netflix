//
//  content.hpp
//  netflix
//
//  Created by Mark Ciccarello on 4/18/21.
//

#ifndef content_hpp
#define content_hpp

#include <string>
#include <vector>
#include <map>
#include "json.hpp"
#include "video.hpp"

using std::string;
using std::vector;
using std::map;
using std::shared_ptr;

using nlohmann::json;


namespace NetflixCatalog {


struct ContentMemberData;

class Content {
    
    
    string name;
    vector<string> prerollNames;
    vector<Video> videos;
      
public:

    
    string const & getName() const { return name; }
    vector<string> const & getPrerollNames() const { return prerollNames; }
    vector<Video> const & getVideos() const { return videos; }
    
    
    void deserialize(map<string, json> const &jsonMap);
    
    
};

} // namespace NetflixCatalog


#endif /* content_hpp */
