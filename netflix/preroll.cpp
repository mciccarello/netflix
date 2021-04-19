//
//  preroll.cpp
//  netflix
//
//  Created by Mark Ciccarello on 4/18/21.
//

#include "preroll.hpp"

namespace NetflixCatalog {

void Preroll::deserialize(map<string, json> const &jsonMap)
{
    name = jsonMap.at("name");
    vector<json> videosJson = jsonMap.at("videos");
    for(auto it = videosJson.begin(); it != videosJson.end(); ++it)
    {
        Video video;
        map<string,json> videoJson = *it;
        video.deserialize(videoJson);
        videos.push_back(video);
    }
    
}

} // namespace NetflixCatalog
