#ifndef __CARBON_BUFFER__
#define __CARBON_BUFFER__

#include "OpenGLES.h"

namespace Carbon {

    enum class EBufferType {
        Vertex = 0x8892,
        Index = 0x8893
    };

    class Buffer {
    public:
        Buffer(EBufferType type, int dataSize, void *pData, bool dynamic = false);

        ~Buffer();

    public:
        void bind();

        void unbind();

        void update(int dataSize, void *pData);


    public:
        void vertexAttribPointer(GLuint location, GLint size, GLint stride, GLint offset);

    private:
        GLuint mHandle = 0;
        EBufferType mType;
    };
}
#endif // __CARBON_BUFFER__
