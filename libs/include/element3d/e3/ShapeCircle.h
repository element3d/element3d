#ifndef __CARBON_CIRCLE_RECTANGLE__
#define __CARBON_CIRCLE_RECTANGLE__

#include "CarbonShape.h"

namespace e3
{
    class ShapeCircle : public e3::ShapeGeometry
    {
    public:
        ShapeCircle();
        ~ShapeCircle();

    public:
        Carbon::Buffer* GetVertexBuffer() override { return mVertexBuffer; }
        Carbon::Buffer* GetIndexBuffer() override { return nullptr; }
        int       GetNumIndices() override { return 0; }
        int       GetNumVertices() override { return mNumVertices; }

    private:
        Carbon::Buffer* mVertexBuffer = nullptr;
        int mNumVertices = 0;
    };
}

#endif // __CARBON_CIRCLE_RECTANGLE__