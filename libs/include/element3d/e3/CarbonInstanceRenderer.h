#ifndef __CARBON_INSTANCE_RENDERER__
#define __CARBON_INSTANCE_RENDERER__

#include <Carbon.h>
#include "LinearLayout.h"

namespace e3
{
    #define NUM_PARAMS 310

    struct InstanceParams
    {
        glm::mat4 uTranslate[NUM_PARAMS];
        glm::mat4 uScale[NUM_PARAMS];
        glm::vec4 uRect[NUM_PARAMS];
        glm::vec4 uBackgroundImageParams[NUM_PARAMS];
        glm::vec4 uZ[NUM_PARAMS];
        glm::vec4 uBackColor[NUM_PARAMS];
    };

    class InstanceRenderer
    {
    public:
        InstanceRenderer();
        ~InstanceRenderer();

    public:
        void UpdateInstances(LinearLayout* pLayout);

    private:
        InstanceParams* mInstanceParams = nullptr;
        GLuint mBlockId = 0;
        GLuint mUniformBuffer = 0;
        Carbon::ShaderProgram* mProgram;
    };
}

#endif // __CARBON_INSTANCE_RENDERER__