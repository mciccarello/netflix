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

#include "video.hpp"
#include "content.hpp"
#include "preroll.hpp"

using std::string;
using std::vector;
using std::map;
using nlohmann::json;

using NetflixCatalog::Video;
using NetflixCatalog::Content;
using NetflixCatalog::Preroll;






/*
struct CatalogMembers {
    map<string,Content> content;
    map<string,Preroll> prerolls;
    
};
*/

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
