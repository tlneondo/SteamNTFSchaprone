#include <string>
#include <list>
#include <cstdint>


class syncFolder{
    public:
        enum class folderType{
            LinuxOnly,
            WindowsOnly,
            WindowsOrProton,
            DontCare,
            Ignore
        };

        std::string relPath; //relative to drive, will have ./ or / at the beginning
        std::int8_t isInUse; //check open file descriptors etc
        std::int32_t folderContentSize; //folder contents

        //should this folder be considered something to run under linux only, windows only, 
        //both, does not matter, or special case ignore, which will add whiteout files to upper directory
        folderType fldType;


};

class steamFolder : public syncFolder{
    public:
        std::string gameTitle;
        std::int32_t appid;
        std::int32_t status;
        std::string ACFpath; //operations will prepend a ../ to make ../appmanifestXXXX.acf
};

class Drive{
    public:
        std::int32_t numUUID;
        std::string upperPath;
        std::string lowerPath;
        std::string overlayPath;

        std::int32_t upperFreeSpace;
        std::int32_t lowerFreeSpace;

        //list of Folders to Track
        std::list<syncFolder> trackedFolders;
};