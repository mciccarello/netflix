//
//  video.cpp
//  netflix
//
//  Created by Mark Ciccarello on 4/18/21.
//

#include <set>

#include "video.hpp"
#include "tags.hpp"


using std::set;

namespace NetflixCatalog {


void Video::deserialize(map<string, json> const &jsonMap) {
    name = jsonMap.at(jsonTags.name);
    json attributes = jsonMap.at(jsonTags.attributes);
    language = attributes.at(jsonTags.language);
    aspect = attributes.at(jsonTags.aspect);
    json countriesJson = attributes.at(jsonTags.countries);
    for(auto it=countriesJson.begin(); it != countriesJson.end(); ++it)
    {
        countries.insert((string)*it);
    }
}

} // namespace NetflixCatalog

