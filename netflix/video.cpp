//
//  video.cpp
//  netflix
//
//  Created by Mark Ciccarello on 4/18/21.
//

#include "video.hpp"



namespace NetflixCatalog {


struct VideoMembers {
    string name;
    vector<string> countries;
    string language;
    string aspect;
};



Video::Video() : members(new VideoMembers()) {}
Video::Video(Video const &rhs) : members(new VideoMembers()) { *this->members = *rhs.members; }
Video::~Video() {};


string const & Video::getName() const { return members->name; }
vector<string> const & Video::getCountries() const { return members->countries; }
string const & Video::getLanguage() const { return members->language; }
string const & Video::getAspect() const { return members->aspect; }



void Video::deserialize(map<string, json> const &jsonMap) {
    members->name = jsonMap.at("name");
    json attributes = jsonMap.at("attributes");
    members->language = attributes.at("language");
    members->aspect = attributes.at("aspect");
    json countriesJson = attributes.at("countries");
    for(auto it=countriesJson.begin(); it != countriesJson.end(); ++ it)
    {
        members->countries.push_back(*it);
    }
}

} // namespace NetflixCatalog

