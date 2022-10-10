#pragma once

#include <gtkmm.h>
#include <filesystem>

#include "mediafile.hpp"
#include "album.hpp"
#include "coverimage.hpp"

#include <fstream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/base_object.hpp>



class MediaLibrary {
public:
    MediaLibrary();
    ~MediaLibrary();

    std::vector<MediaFile*> getMediaFiles();
    std::vector<MediaFile*> getMediaFiles(std::string albumName);
    std::vector<Album*> getAlbums();

    std::string getStats();

    void addMediaFile(MediaFile* mediaFile);
    void addMediaFile(std::filesystem::path path);

    void addSearchPath(std::filesystem::path path);
    std::vector<std::filesystem::path> getSearchPaths();

    void loadCovers();
private:
    friend class boost::serialization::access;
    std::vector<MediaFile*> mMediaFiles;
    std::map<std::string, Album*> mAlbumMap;
    std::map<std::string, MediaFile*> mMediaFilesMap;
    std::vector<std::string> mPaths;
    int mAlbumCount = 0;
    int mMediaFileCount = 0;

    template<class Archive>
    void serialize(Archive &a, const unsigned version){
        a & mMediaFiles & mAlbumMap & mMediaFilesMap & mAlbumCount & mMediaFileCount & mPaths;
    }
    
    void addAlbum(MediaFile* mediaFile);
};