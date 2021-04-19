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
using std::endl;



using NetflixCatalog::Catalog;


/* *******************************************************************************************
   main
 
   The code in main illustrates the use of the library, the API to which is fully described
   by the Catalog class in catalog.hpp. More detailed information on the APIs can be found
   in that file.
   ******************************************************************************************* */


void printPlayLists(list<Catalog::PlayList> const &playLists) {
    
    for(auto playList : playLists) {
        std::cout << "Playlist (" << playList.getAspect() << "): ";
        for (auto video : playList.getVideoNames()) {
            std::cout << video << " ";
        }
        std::cout << endl;
    }
    
}


int main(int argc, const char * argv[]) {
    
    
    try {
        
        Catalog catalog;
        catalog.initialize("catalog.json");
        
        
        cout << endl << "Test case MI3, US: " << endl;
        list<Catalog::PlayList> playLists;
        catalog.getPlayLists("MI3", "US", playLists);
        printPlayLists(playLists);
        
        
        cout << endl << "Test case MI3, CA: " << endl;
        playLists.clear();
        catalog.getPlayLists("MI3", "CA", playLists);
        printPlayLists(playLists);
        
        cout << endl << "Test case MI3, UK: " << endl;
        playLists.clear();
        catalog.getPlayLists("MI3", "UK", playLists);
        printPlayLists(playLists);
                
        
    } catch (std::exception &e) {
        cout << e.what() << endl;
    }
    return 0;
}
