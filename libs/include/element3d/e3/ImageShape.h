#ifndef __E3_IMAGE_SHAPE__
#define __E3_IMAGE_SHAPE__

#include <e3/Shape.h>

namespace e3
{
    class ImageShape : public Shape
    {
    public:
        ImageShape();
        ~ImageShape();

    public:
        virtual void Update() override;
        virtual void Render() override;

    public:
        void SetImagePath(const std::string &path);
        void SetImage(int id);
        void SetImageUrl(const std::string &url);
        void SetImageUrl(const std::string &url, const std::vector<std::string>& headers);
        void SetImageOpacity(float opacity);

        void SetImageFit(EBackgroundSize fit);
    private:
        float mImageOpacity = 1.0f;
        Image *mImage = nullptr;
    };
}

#endif // __E3_IMAGE_SHAPE__