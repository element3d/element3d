#ifndef __CARBON_SHAPE__
#define __CARBON_SHAPE__

#include <Carbon/Buffer.h>

namespace e3
{
    class ShapeGeometry
    {
    public:
        ShapeGeometry() {}
        virtual ~ShapeGeometry() {}

    public:
        virtual Carbon::Buffer* GetVertexBuffer() = 0;
        virtual Carbon::Buffer* GetIndexBuffer() = 0;
        virtual int       GetNumVertices() = 0;
        virtual int       GetNumIndices() = 0;
    };
}

#endif // __CARBON_SHAPE_RECTANGLE__