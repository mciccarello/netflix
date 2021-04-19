//
//  video_catalog.hpp
//  netflix
//
//  Created by Mark Ciccarello on 4/18/21.
//

#ifndef video_catalog_hpp
#define video_catalog_hpp

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


namespace NetflixCatalog {


class VideoPlayList {
    
    vector<Video> const videos;
    string const contentName;
    string const country;
    string const aspect;
    
    
public:
    
    VideoPlayList(string contentName, string country, string aspect, vector<Video> const &videos) :
        contentName(contentName), country(country), aspect(aspect), videos(videos) {}

    string getContentName() const { return contentName; }
    string getCountry() const { return country; }
    string getAspect() const { return aspect; }
    vector<Video> const &getVideos() const { return videos; }

    
};


class VideoCatalog {
    
    map<string,Content> contents;
    map<string,Preroll> prerolls;
    
    bool findPrerollVideo(string const &prerollName, string const &country, string const &language, string const &aspect, Video &videoOut);
    bool getOnePlayList(Video contentVideo, string const &country, string const &language, vector<string> const &prerollNames, list<VideoPlayList> &playLists);
    
    
public:
    
    void deserialize(map<string,json> const &jsonMap);
    void getPlayLists(string contentName, string country, list<VideoPlayList> &playLists);
    
};

} // namespace NetflixCatalog

#endif /* video_catalog_hpp */
