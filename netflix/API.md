# Netflix Video Catalog API



This API provides a Catalog class containing two member functions. In general, in designing a library, it's important to keep as much detail hidden from the client as possible. 
This enforces loose coupling and allows for flexibility in maintaining the implementation without requiring client changes. Hence only this class (plus one small inner helper class)
is visible to the client.

There are only a few thing that can (predictably) go wrong, and they have to do with opening and parsing the JSON catalog file. I've decided to use exceptions because the unwinding
feature works well with the serialization code. I've tried to create exceptions that make sense in context -- for example, rather than allowing an exception from the json parsing library
to propagate upward, I catch it and throw something called a JSONException instead.

## void initialize(std::string filePath);

Takes a path to a .json file containing the catalog. Initializes the catalog
with the json file. It may be called multiple times to re-initialize with
different data.

Throws a InputFileNotFound exception if the json file does not exist, or a JSONException if it contains an error.

In the event of an error on re-initialization, the catalog remains unchanged.


## void getPlayLists(string const &name, string const &country, list<Catalog::PlayList> &playLists);

Returns a list of Catalog::PlayList objects representing play lists for different aspect ratios for the requested content and country. It is not
considered an error for a play list to be empty. 

Each PlayList returned has methods to obtain the aspect ratio and list of videos to play in correct order. The public API for each PlayList object looks like this:

class Catalog::PlayList {
    string getAspect();
    list<string> const &getVideoNames();
};







