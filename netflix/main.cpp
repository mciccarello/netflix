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


#include "catalog.hpp"



using std::string;
using std::list;
using std::cout;



using NetflixCatalog::Catalog;


/* *******************************************************************************************
   main
 
   The code in main illustrates the use of the library, the API to which is fully described
   by the Catalog class in catalog.hpp. More detailed information on the APIs can be found
   in that file.
   ******************************************************************************************* */



int main(int argc, const char * argv[]) {
    
    
    try {
        
        Catalog catalog;
        catalog.initialize("catalog.json");
        list<Catalog::PlayList> playLists;
        catalog.getPlayLists("MI3", "UK", playLists);
        for(auto playList : playLists) {
            std::cout << "Playlist (" << playList.getAspect() << "): ";
            list<string> const &videos = playList.getVideoNames();
            for (auto video : videos) {
                std::cout << video << " ";
            }
            std::cout << std::endl;
        }
    } catch (std::exception &e) {
        cout << e.what() << std::endl;
    }
    return 0;
}
