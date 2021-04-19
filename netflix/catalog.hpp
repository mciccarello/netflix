//
//  catalog.hpp
//  netflix
//
//  Created by Mark Ciccarello on 4/18/21.
//

#ifndef catalog_hpp
#define catalog_hpp

#include <memory>
#include <list>

using std::list;
using std::string;

/* ******************************************************************************************************************************************
 
   Catalog is the top-level class, and the only class (other than its inner PlayList class) visible to the users of this library. It is
   designed to wrap the "real" top-level class (VideoCatalog) in order to define the API to this library the way we want users to see it,
   hiding all other details.
 
   Two API's are provided and described below: initialize() and getPlayLists().
   ******************************************************************************************************************************************* */



namespace NetflixCatalog {

class VideoCatalog;

class Catalog {
    
    VideoCatalog *catalog;

public:
    
    class PlayList {
        string aspect;
        list<string> videoNames;
    public:
        PlayList(string const &aspect, list<string> &videoNames) : aspect(aspect), videoNames(videoNames) {}
        list<string> const &getVideoNames() { return videoNames; }
        string getAspect() { return aspect; }
    };
    
    Catalog();
    
    void initialize(std::string filePath);
    // ------------------------------------------------------------------
    // initialize
    //
    // parameters: std::string filePath
    //
    // Takes a file name with optional path naming a file containing json
    // with which to initialize the catalog.
    //
    // May be called repeatedly. The old data is simply discarded, assuming
    // the new file parses without error.
    //
    // An error in parsing the JSON file results in a standard error being
    // thrown and nothing else being done.
    // -------------------------------------------------------------------
    
    
    void getPlayLists(string const &name, string const &country, list<Catalog::PlayList> &playLists);
    // -------------------------------------------------------------------
    // getPlayLists
    //
    // parameters:
    //    name -- the name of the content you'd like a playlist for
    //    country -- the country for which you'd like this content
    //    playLists -- output parameter. Playlists will be placed in here.
    //
    // Retrieves zero or more playlists that for a particular piece of content
    // and country. The lists will include the video names for preroll files
    // and content files. In the case of more than one being returned, these
    // will be different aspect ratios.
    //
    // In order for a playlist to be returned, there must be prerolls that
    // match the country and aspect ratio of the content video.
    //
    // It is possible for no playlists to be returned. This is not considered
    // an error condition.
    // -------------------------------------------------------------------



};


} // namespace NetflixCatalog

#endif /* catalog_hpp */
