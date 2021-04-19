//
//  tags.hpp
//  netflix
//
//  Created by Mark Ciccarello on 4/18/21.
//

#ifndef tags_hpp
#define tags_hpp

#include <string>

using std::string;

namespace NetflixCatalog {

struct JSONTags {
    string aspect = "aspect";
    string attributes = "attributes";
    string content = "content";
    string countries = "countries";
    string language = "language";
    string name = "name";
    string preroll = "preroll";
    string videos = "videos";
};

extern JSONTags const jsonTags;

} // namespace NetflixCatalog


#endif /* tags_hpp */
