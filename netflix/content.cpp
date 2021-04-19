//
//  content.cpp
//  netflix
//
//  Created by Mark Ciccarello on 4/18/21.
//

#include <iostream>
#include "content.hpp"
#include "tags.hpp"

using NetflixCatalog::Video;

namespace NetflixCatalog {


void Content::deserialize(map<string, json> const &jsonMap)
{
    name = jsonMap.at(jsonTags.name);
    vector<json> prerollsJson = jsonMap.at(jsonTags.preroll);
    for(auto it = prerollsJson.begin(); it != prerollsJson.end(); ++it)
    {
        string preroll = (*it).at(jsonTags.name);
        prerollNames.push_back(preroll);
    }
    vector<json> videosJson = jsonMap.at(jsonTags.videos);
    for(auto it = videosJson.begin(); it != videosJson.end(); ++it)
    {
        Video video;
        map<string,json> videoJson = *it;
        video.deserialize(videoJson);
        videos.push_back(video);
    }
    
}

} // namespace NetflixCatalog;

