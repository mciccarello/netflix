//
//  catalog.hpp
//  netflix
//
//  Created by Mark Ciccarello on 4/18/21.
//

#ifndef catalog_hpp
#define catalog_hpp

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <list>

#include "json.hpp"

#include "video.hpp"
#include "content.hpp"
#include "preroll.hpp"


using std::string;
using std::vector;
using std::list;
using std::map;
using nlohmann::json;

using NetflixCatalog::Video;
using NetflixCatalog::Content;
using NetflixCatalog::Preroll;
using NetflixCatalog::jsonTags;


namespace NetflixCatalog {


class PlayList {
    
    vector<Video> const videos;
    string const contentName;
    string const country;
    string const aspect;
    
    
public:
    
    PlayList(string contentName, string country, string aspect, vector<Video> const &videos) :
        contentName(contentName), country(country), aspect(aspect), videos(videos) {}

    string getContentName() const { return contentName; }
    string getCountry() const { return country; }
    string getAspect() const { return aspect; }
    vector<Video> const &getVideos() const { return videos; }

    
};


class Catalog {
    
    map<string,Content> contents;
    map<string,Preroll> prerolls;
    
    bool findPrerollVideo(string const &prerollName, string const &country, string const &aspect, Video &videoOut);
    bool getOnePlayList(Video contentVideo, string country, vector<string> const &prerollNames, list<PlayList> &playLists);
    
    
public:
    
    void deserialize(map<string,json> const &jsonMap);
    void getPlayLists(string contentName, string country, list<PlayList> &playLists);
    
};

} // namespace NetflixCatalog

#endif /* catalog_hpp */
