#include <string>
#include <list>
#include <cstdint>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;


class syncFolder{
    public:
        enum class osUseCase{
            LinuxOnly,
            WindowsOnly,
            WindowsOrProton,
            DontCare,
            Ignore
        };

        fs::path reltoDrivePath; //relative to drive, will have ./ or / at the beginning
        std::int8_t isInUse; //check open file descriptors etc
        std::int32_t folderContentSize; //folder contents

        //should this folder be considered something to run under linux only, windows only, 
        //both, does not matter, or special case ignore, which will add whiteout files to upper directory
        osUseCase useType;

        //contstruct

        syncFolder(osUseCase useCase, fs::path relDrivePath){
            useType = useCase;
            reltoDrivePath = relDrivePath;
        }


};

class steamWorkshopFolder{
    public:
        fs::path reltoDriveContentPath;
        fs::path WSACFpath; //operations will prepend a ../ to make ../appworkshop_XXX.acf

        //contstruct
        steamWorkshopFolder(fs::path relDrive,fs::path ){
            reltoDrivePath = y;
            WSACFpath = c;
        }
};

class steamGameFolder : public syncFolder{
    public:
        std::string gameTitle;
        std::int32_t appid;
        fs::path ACFpath;
        steamWorkshopFolder wrkshop;
        //contstruct
        steamGameFolder(osUseCase useCase, fs::path relDrivePath, fs::path acfPath) : syncFolder(useCase,relDrivePath){
            ACFpath = acfPath;
            //check for workshop path
            // if $ACFPATH/workshop/appworkshop_$APPID.acf exists
                //wrkshop.reltoDriveContentPath = ./content/$appid
                //wrkshop.WSACFPath = appworkshop_$appid.acf
                //else wrkshop = "";

        }
 
        


};



class Drive{
    public:
        std::int32_t numUUID;
        fs::path upperPath;
        fs::path lowerPath;
        fs::path overlayPath;

        std::int32_t upperFreeSpace;
        std::int32_t lowerFreeSpace;

        //keep track of steamappspath
        fs::path steamappsPath;

        //list of Folders to Track
        std::list<syncFolder> trackedGenericFolders;
        std::list<steamGameFolder> trackedSteamGameFolders;

        
        Drive(){}



        

};