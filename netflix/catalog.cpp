//
//  catalog.cpp
//  netflix
//
//  Created by Mark Ciccarello on 4/18/21.
//

#include <string>

#include "json.hpp"

#include "catalog.hpp"
#include "video_catalog.hpp"
#include "exceptions.hpp"

using nlohmann::json;

using std::string;

namespace NetflixCatalog {


Catalog::Catalog() {};
Catalog::~Catalog() {};


void Catalog::initialize(string fileName) {
        
    VideoCatalog *newCatalog = new VideoCatalog();
    
    std::ifstream i(fileName,std::ifstream::in);
    if (!i.is_open()) {
        throw fileNotFoundException;
    }

    nlohmann::json j;
    i >> j;
    i.close();
    newCatalog->deserialize(j);
    catalog = std::make_unique<VideoCatalog>(*newCatalog);
    
    
}


void Catalog::getPlayLists(string const &name, string const &country, list<Catalog::PlayList> &playLists) {
    list<VideoPlayList> videoPlayLists;
    catalog->getPlayLists(name, country, videoPlayLists);
    for(auto videoPlayList : videoPlayLists) {
        list<string> videoNames;
        vector<Video> const &videos = videoPlayList.getVideos();
        for(auto video : videos) {
            videoNames.push_back(video.getName());
        }
        PlayList playList(videoPlayList.getAspect(), videoNames);
        playLists.push_back(playList);
    
    }
    
}


} // namespace NetflixCatalog
