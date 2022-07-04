#ifndef __PUZL_TEXTURE_H__
#define __PUZL_TEXTURE_H__

#include "OpenGLES.h"
//#include <e3/Image.h>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <mutex>
// #include <opencv2/core/core.hpp>

class Texture;
typedef std::function<void(Texture*)> OnTextureLoadCallback;

enum class ETextureType
{
    Texture2D = GL_TEXTURE_2D,
    Texture2DMultisample = GL_TEXTURE_2D_MULTISAMPLE,
    TextureCube = GL_TEXTURE_CUBE_MAP
};

enum class ETextureFormat
{
    R8_Unorm,
    R8G8_Unorm,
    R8G8B8_Unorm,
    R8G8B8A8_Unorm,

    Auto,
    R = GL_RED,
    RG = GL_LUMINANCE_ALPHA,
    RGB = GL_RGB,
    RGBA = GL_RGBA


};

enum class GLInternalFormat
{
    Auto,
    R8 = GL_R8,
    RG = GL_RG8,
    RGB8 = GL_RGB8,
	RGB32F = GL_RGB32F,
    RGBA8 = GL_RGBA8,
    RGBA32F = GL_RGBA32F

};

enum class CubeMapFace
{
    PositiveX = GL_TEXTURE_CUBE_MAP_POSITIVE_X,
    NegativeX = GL_TEXTURE_CUBE_MAP_POSITIVE_X,
    PositiveY = GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
    NegativeY = GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
    PositiveZ = GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
    NegativeZ = GL_TEXTURE_CUBE_MAP_POSITIVE_Z

};

struct TextureLazyData
{
    void* Data;
    float Width;
    float Height;
    int   NumChannels;
};

struct TextureCreateInfo
{
    float Width;
    float Height;
    ETextureType Type;
    ETextureFormat Format;
    void* Data;
};

class Texture
{
public:
    Texture(const TextureCreateInfo* pInfo);
    /*Texture(ETextureType type, ETextureFormat format = ETextureFormat::Auto);
    Texture(ETextureType type, int borderSize, ETextureFormat format = ETextureFormat::Auto);*/
    ~Texture();
public:
    // bool load(const char* filename, ETextureFormat format = ETextureFormat::Auto);

   // static void LoadAsync(int id, OnTextureLoadCallback callback);

  //  static Texture* loadAsync(int id, ETextureType type, ETextureFormat format = ETextureFormat::Auto);
    /*template <typename T>
    static Texture* loadAsset(T id, ETextureFormat format = ETextureFormat::Auto)
    {
        return loadAssetPrivate(static_cast<int>(id), format);
    }*/
   // static void LoadUrl(const std::string& url, OnTextureLoadCallback callback);
   // static void LoadUrl(const std::string& url, const std::vector<std::string>& headers, OnTextureLoadCallback callback);

 //   bool loadCubeMap(std::vector<std::string>& filenames);
    void setData(int width, int height, void* pData);
    void setLazyData(TextureLazyData* pLazyData) { mLazyData = pLazyData; }
    //void SetLazyImage(e3::Image* image) { mLazyImage = image; }
    void createLazy();
 //   void setDataCubeMap(CubeMapFace face, int width, int height, void* pData);
    void bind();
    void unbind();

    GLuint handle() { return mHandle; }
    GLuint type() { return static_cast<GLuint>(mType); }
    int width() { return mCreateInfo->Width; }
    int height() { return mCreateInfo->Height; }
    bool empty() { std::lock_guard<std::mutex> lock(mMutex); return mEmpty; }
    std::string filename() { return mFilename; }

private:
    void TextureFormatToGLFormat(ETextureFormat format);
    void create();

    static Texture* loadAssetPrivate(int id, ETextureFormat format = ETextureFormat::Auto);
//    void setDataMultisample(int width, int height, void* pData);

private:
    TextureCreateInfo* mCreateInfo = nullptr;

    GLuint mHandle = 0;
    GLuint mFormat = GL_RGBA;
    GLuint mInternalFormat = GL_RGBA8;
    GLenum mDataType;
    bool   mEmpty = true;
    std::string mFilename;
    ETextureType mType;
    int mBorderSize = 0;

    TextureLazyData* mLazyData = nullptr;
//    e3::Image* mLazyImage = nullptr;
    std::mutex mMutex;



};

#endif // __PUZL_TEXTURE_H__
