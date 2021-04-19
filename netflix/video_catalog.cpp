//
//  video_catalog.cpp
//  netflix
//
//  Created by Mark Ciccarello on 4/18/21.
//

#include "video_catalog.hpp"
#include "tags.hpp"

namespace NetflixCatalog {

void VideoCatalog::deserialize(map<string,json> const &jsonMap)
//
// This slight abuse of the term "deserialize," because it only does half the job,
// relying on a json library having already parsed the serial json document file.
// It takes the parsed json document in the form of a heirarchy of maps and vectors
// of values and converts it into C++ a Catalog class, and its component and subcomponent
// classes (Content, Preroll and Video), as requested in the requirements document.
//
{
    vector<json> contentJson = jsonMap.at(jsonTags.content);
    for(auto it = contentJson.begin(); it != contentJson.end(); ++it) {
        Content content;
        content.deserialize(*it);
        contents.insert(std::pair<string,Content>(content.getName(),content));
    }
    vector<json> prerollJson = jsonMap.at(jsonTags.preroll);
    for(auto it = prerollJson.begin(); it != prerollJson.end(); ++it) {
        Preroll preroll;
        preroll.deserialize(*it);
        prerolls.insert(std::pair<string,Preroll>(preroll.getName(),preroll));
    }
}



bool VideoCatalog::findPrerollVideo(string const &prerollName, string const &country, string const &aspect, Video &videoOut)
{
    auto prerollIt = prerolls.find(prerollName);
    if (prerollIt == prerolls.end()) {
        return false;
    }
    auto videos = prerollIt->second.getVideos();
    for(auto video : videos) {
        auto countries = video.getCountries();
        if (countries.find(country) != countries.end()) {
            if (video.getAspect() == aspect) {
                videoOut = video;
                return true;
            }
        }
    }
    return false;
    
}


bool VideoCatalog::getOnePlayList(Video contentVideo, string country, vector<string> const &prerollNames, list<VideoPlayList> &playLists) {
//
// given a content video and a list of preroll names, see if we can satisfy the
// prerolls (matching country, aspect, etc). If so, create a playlist from the content
// video and prerolls and add to the playlist
//
    
    vector<Video> videos;
    for( auto prerollName : prerollNames)
    {
        // for each named preroll there should (hopefully) be one matching preroll video
        // add each to the list of videos
        Video prerollVideo;
        if (!findPrerollVideo(prerollName, country, contentVideo.getAspect(), prerollVideo))
        {
            // no preroll video satisfies -- can't make a playlist from this content video
            return false;
        }
        videos.push_back(prerollVideo);
    }
    
    // All prerolls satisfied with videos added to the list. Now add the content video, played last
    videos.push_back(contentVideo);
    
    VideoPlayList playList(contentVideo.getName(), country, contentVideo.getAspect(), videos);
    playLists.push_back(playList);
    return true;
            
}



void VideoCatalog::getPlayLists(string contentName, string country, list<VideoPlayList> &playLists) {
//
// Retrieves a list of playLists for a piece of content for a specified country.
// If more than one returned, each playList will be for a different aspect ratio
//
    auto contentIt = contents.find(contentName);
    if (contentIt == contents.end()) {
        // no content found. I'm not sure this is an error condition
        return;
    }
    auto videos = contentIt->second.getVideos();
    for(auto contentVideo : videos) {
        // we have some content videos for this content. Each should be for a unique
        // combination of country (possibly more than one), language and aspect ratio
        auto contentVideoCountries = contentVideo.getCountries();
        if (contentVideoCountries.find(country) != contentVideoCountries.end()) {
            // found the right content video for the country. Now try to find
            // all specified preroll, matching country, aspect ratio
            auto prerollNames = contentIt->second.getPrerollNames();
            getOnePlayList(contentVideo, country, contentIt->second.getPrerollNames(), playLists);
        }
        
    }
    
}

} // namespace NetflixCatalog


