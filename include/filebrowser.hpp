#pragma once

#include <filesystem>
#include <vector>
#include <string>
#include <unordered_map>

class Filebrowser {
public:
    /**
     * Retrieves files in directory. Beware as it retrieves only audio files specified by file extensions.
     * 
     * @param path Directory
     * @param sort Should the results be sorted? (Probably yes)
     * @param showHiddenFiles
     * 
     * @return Vector of directory entries for path
     */
    static std::vector<std::filesystem::directory_entry> getFileList(std::filesystem::path path, bool sort, bool showHiddenFiles);

    static std::vector<std::filesystem::path> getDirectoryList(std::filesystem::path path, bool sort, bool showHiddenFiles, bool includeItself);

    /**
     * @param directory
     * @param acceptedFiles
     * @param outputFile If return value is true, this pointer gets set to the file we found.
     * 
     * @return True if directory contains file, false otherwise.
     */
    static bool hasFile(std::filesystem::path directory, std::vector<std::string> acceptedFiles, std::string* outputFile);

    /**
     * Only files with these extensions get showed.
     * Probably should be filled by Utils::createValidExtensions().
     */
    static std::unordered_map<std::string, int> VALID_EXTENSIONS;
private:
    Filebrowser();
    virtual ~Filebrowser();
};