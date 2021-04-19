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
#include <list>

#include "json.hpp"

#include "video.hpp"
#include "content.hpp"
#include "preroll.hpp"
#include "catalog.hpp"

#include "tags.hpp"

using std::string;
using std::list;
using nlohmann::json;

using NetflixCatalog::Catalog;
using NetflixCatalog::PlayList;


int main(int argc, const char * argv[]) {
    
    std::ifstream i("catalog.json",std::ifstream::in);

    nlohmann::json j;
    i >> j;
    i.close();
    
    Catalog catalog;
    catalog.deserialize(j);
    
    list<PlayList> playLists;
    catalog.getPlayLists("MI3", "US", playLists);
    for(auto playList : playLists) {
        std::cout << "Playlist: ";
        vector<Video> const &videos = playList.getVideos();
        for (auto video : videos) {
            std::cout << video.getName() + " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
