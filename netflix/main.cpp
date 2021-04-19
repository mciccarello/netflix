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

void printPlayLists(list<Catalog::PlayList> const &playLists) {
    
    for(auto playList : playLists) {
        std::cout << "Playlist (" << playList.getAspect() << "): ";
        for (auto video : playList.getVideoNames()) {
            std::cout << video << " ";
        }
        std::cout << endl;
    }
    
}


/* *******************************************************************************************
   main
 
   The code in main illustrates the use of the library, the API to which is fully described
   by the Catalog class in catalog.hpp. More detailed information on the APIs can be found
   in that file and in API.md
   ******************************************************************************************* */





int main(int argc, const char * argv[]) {
    
    
    try {
        
        Catalog catalog;
        list<Catalog::PlayList> playLists;
        
        //
        // catalog.json
        //
        
        cout << endl << endl;
        cout << "****** catalog.json ******" << endl;
        cout << "Original test cases." << endl;
        cout <<"**************************" << endl;
        
        catalog.initialize("catalog.json");
        
        cout << endl << "Test case MI3, US: " << endl;

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
        
        //
        // catalog2.json
        //
        
        catalog.initialize("catalog2.json");
        
        cout << endl << endl;
        cout << "****** catalog2.json ******" << endl;
        cout << "US requires two prerolls but only one has a match." << endl;
        cout << "CA requires two prerolls, matches provided for 16:9." << endl;
        cout <<"**************************" << endl;
        
        cout << endl << "Test case MI3, US: " << endl;
        playLists.clear();
        catalog.getPlayLists("MI3", "US", playLists);
        printPlayLists(playLists);
        
        
        cout << endl << "Test case MI3, CA: " << endl;
        playLists.clear();
        catalog.getPlayLists("MI3", "CA", playLists);
        printPlayLists(playLists);

        //
        // bad_catalog.json
        //
        
        cout << endl << endl;
        cout << "****** bad_catalog.json ******" << endl;
        cout << "Catalog file contains a bad tag. Will throw." << endl;
        cout << "Afterwards catalog should be unchanged so we'll" << endl;
        cout << "try the CA case again." << endl;
        cout << "**************************" << endl;
        
        try {
            catalog.initialize("bad_catalog.json");
        } catch(std::exception &e) {
            cout << "Caught: " << e.what() << endl;
        }
        cout << endl << "Test case MI3, CA: " << endl;
        playLists.clear();
        catalog.getPlayLists("MI3", "CA", playLists);
        printPlayLists(playLists);
        
        //
        // doesnotexist.json
        //
        
        cout << endl << endl;
        cout << "****** doesnotexist.json ******" << endl;
        cout << "Catalog file does not exist. Will throw." << endl;
        cout << "Afterwards catalog should be unchanged so we'll" << endl;
        cout << "try the CA case again." << endl;
        cout << "**************************" << endl;
        
        try {
            catalog.initialize("doesnotexist.json");
        } catch(std::exception &e) {
            cout << "Caught: " << e.what() << endl;
        }
        cout << endl << "Test case MI3, CA: " << endl;
        playLists.clear();
        catalog.getPlayLists("MI3", "CA", playLists);
        printPlayLists(playLists);
        
        
    } catch (std::exception &e) {
        cout << e.what() << endl;
    }
    return 0;
}
