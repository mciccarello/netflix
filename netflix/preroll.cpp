//
//  preroll.cpp
//  netflix
//
//  Created by Mark Ciccarello on 4/18/21.
//

#include "preroll.hpp"
#include "exceptions.hpp"

namespace NetflixCatalog {

void Preroll::deserialize(map<string, json> const &jsonMap)
{
    try {
        name = jsonMap.at("name");
        vector<json> videosJson = jsonMap.at("videos");
        for(auto it = videosJson.begin(); it != videosJson.end(); ++it)
        {
            Video video;
            map<string,json> videoJson = *it;
            video.deserialize(videoJson);
            videos.push_back(video);
        }
    } catch(std::exception e) {
        JSONException je("Error parsing JSON");
        throw je;
    }
    
}

} // namespace NetflixCatalog
