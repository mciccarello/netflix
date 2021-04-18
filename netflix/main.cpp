//
//  main.cpp
//  netflix
//
//  Created by Mark Ciccarello on 4/17/21.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#include "json.hpp"

using std::string;
using std::vector;
using std::map;
using nlohmann::json;



class Video {
        
    string name;
    vector<string> countries;
    string language;
    string aspect;
    
public:
    
    void deserialize(map<string, json> const &jsonMap) {
        name = jsonMap.at("name");
        json attributes = jsonMap.at("attributes");
        language = attributes.at("language");
        aspect = attributes.at("aspect");
        json countriesJson = attributes.at("countries");
        for(auto it=countriesJson.begin(); it != countriesJson.end(); ++ it)
        {
            countries.push_back(*it);
        }
        std::cout << "video " << name << std::endl;
    }
    
    
    
    
};



class Content {
  
    string name;
    vector<string> prerolls;
    vector<Video> videos;
    
public:
    string getName() { return name; }
    
    void deserialize(map<string, json> const &jsonMap)
    {
        name = jsonMap.at("name");
        vector<json> prerollsJson = jsonMap.at("preroll");
        for(auto it = prerollsJson.begin(); it != prerollsJson.end(); ++it)
        {
            string preroll = (*it).at("name");
            prerolls.push_back(preroll);
        }
        vector<json> videosJson = jsonMap.at("videos");
        for(auto it = videosJson.begin(); it != videosJson.end(); ++it)
        {
            Video video;
            map<string,json> videoJson = *it;
            video.deserialize(videoJson);
            videos.push_back(video);
        }
        std::cout << "content " << name << std::endl;
        
    }
    
};


class Preroll {
    
    
    string name;
    vector<Video> videos;
    
public:
    string getName() { return name; }
    void deserialize(map<string, json> const &jsonMap)
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
        std::cout << "preroll " << name << std::endl;
        
    }
    
    
};



class Catalog {
    
    map<string,Content> contents;
    map<string,Preroll> prerolls;
    
    
public:
    
    void deserialize(map<string,json> const &jsonMap)
    //
    // This slight abuse of the term "deserialize," because it only does half the job,
    // relying on a json library having already parsed the serial json document file.
    // It takes the parsed json document in the form of a heirarchy of maps and vectors
    // of values and converts it into C++ a Catalog class, and its component and subcomponent
    // classes (Content, Preroll and Video), as requested in the requirements document.
    //
    {
        vector<json> contentJson = jsonMap.at("content");
        for(auto it = contentJson.begin(); it != contentJson.end(); ++it) {
            Content content;
            content.deserialize(*it);
            contents.insert(std::pair<string,Content>(content.getName(),content));
        }
        vector<json> prerollJson = jsonMap.at("preroll");
        for(auto it = prerollJson.begin(); it != prerollJson.end(); ++it) {
            Preroll preroll;
            preroll.deserialize(*it);
            prerolls.insert(std::pair<string,Preroll>(preroll.getName(),preroll));
        }
    }
    
    
};







// std::string const Video::aspectRatios[] = { "4:3", "16:9" };


int main(int argc, const char * argv[]) {
    
    std::ifstream i("catalog.json",std::ifstream::in);

    nlohmann::json j;
    i >> j;
    i.close();
    
    
    Catalog catalog;
    catalog.deserialize(j);
    
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
