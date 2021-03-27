#ifndef __CARBON_ICON__
#define __CARBON_ICON__

#include "View.h"
#include <string>

namespace e3
{
    class Icon : public View
    {
    public:
        Icon();

        ~Icon();

    public:
        virtual void draw();

    public:
        void setSrcColor(const glm::vec3 &color) { mSrcColor = glm::vec4(color, 1.0f); }
        void setSrcColor(const glm::vec4 &color) { mSrcColor = color; }

        void setSrcImagePath(const std::string &filename);

        template<typename T>
        void setSrcImageId(T id) { setSrcImageIdPrivate(static_cast<int>(id)); }

        void SetSrcImageUrl(const std::string &url);

    private:
        void setSrcImageIdPrivate(int id);

    private:
        Texture *mTexture = nullptr;
        glm::vec4 mSrcColor = glm::vec4(0);

        float mAspectRatioWidth = 1.0f;
        float mAspectRatioHeight = 1.0f;
    };
}

#endif // __CARBON_ICON__
