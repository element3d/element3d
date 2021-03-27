#ifndef __CARBON_ASSETS__
#define __CARBON_ASSETS__

#include <map>
#include <string>


namespace Carbon
{
    class AssetsBase
    {
    public:
        AssetsBase() {}

    public:
        virtual void _AddAsset(int id, const std::string& assetPath) = 0;

        virtual std::string _GetAsset(int id) = 0;

    protected:
        std::map<int, std::string> mAssetsMap;

    };
}

#endif // __CARBON_ASSETS__
