#ifndef __CARBON_SHAPE_RECTANGLE__
#define __CARBON_SHAPE_RECTANGLE__

#include "CarbonShape.h"

namespace e3
{
    class ShapeRectangle : public ShapeGeometry
    {
    public:
        ShapeRectangle();
        ~ShapeRectangle();

    public:
        Carbon::Buffer* GetVertexBuffer() override { return mVertexBuffer; }
        Carbon::Buffer* GetIndexBuffer() override { return mIndexBuffer; }
        int       GetNumIndices() override { return mNumIndices; }
        int       GetNumVertices() override { return 0; }

    private:
        Carbon::Buffer* mVertexBuffer = nullptr;
        Carbon::Buffer* mIndexBuffer = nullptr;
        int mNumIndices = 0;
    };
}

#endif // __CARBON_SHAPE_RECTANGLE__