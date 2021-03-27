#ifndef __CARBON_GLMATERIALS__
#define __CARBON_GLMATERIALS__

#include "Carbon.h"
#include <e3/Enum.h>
#include <Carbon/Texture.h>
#include <map>

class GLMaterials
{
public:
    GLMaterials();
    ~GLMaterials();

    void addTextureMap(const std::string& meshName, EMaterialType type, Texture* pTexture);
    Texture* textureMap(const std::string& meshName, EMaterialType type) { return mDiffuseMaps[meshName]; }

private:
    std::map<std::string, Texture*> mDiffuseMaps;
};

#endif // __CARBON_GLMATERIALS__