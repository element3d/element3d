#ifndef __CARBON_BUFFER__
#define __CARBON_BUFFER__

#include "OpenGLES.h"

namespace e3 
{

    enum class EGLBufferType {
        Vertex = 0x8892,
        Index = 0x8893
    };

    class GLBuffer {
    public:
        GLBuffer(EGLBufferType type, int dataSize, void *pData, bool dynamic = false);

        ~GLBuffer();

    public:
        void bind();

        void unbind();

        void update(int dataSize, void *pData);


    public:
        void vertexAttribPointer(GLuint location, GLint size, GLint stride, GLint offset);

    private:
        GLuint mHandle = 0;
        EGLBufferType mType;
    };
}
#endif // __CARBON_BUFFER__
