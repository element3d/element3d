#ifndef __CARBON_BACKGROUND_IMAGE_INSTANCED_RENDERER__
#define __CARBON_BACKGROUND_IMAGE_INSTANCED_RENDERER__

#include <Carbon.h>
#include "LinearLayout.h"

#define NUM_PARAMS 310


namespace e3
{

    struct InstanceParams
    {
        glm::mat4 uTranslate[NUM_PARAMS];
        glm::mat4 uScale[NUM_PARAMS];
        glm::vec4 uRect[NUM_PARAMS];
        glm::vec4 uBackgroundImageParams[NUM_PARAMS];
        glm::vec4 uZ[NUM_PARAMS];
        glm::vec4 uBackColor[NUM_PARAMS];
    };

    class BackgroundImageInstancedRenderer
    {
    public:
        BackgroundImageInstancedRenderer();
        ~BackgroundImageInstancedRenderer();

    public:
        void UpdateInstances(LinearLayout* pLayout);
        void Draw();

    private:
        void UpdateInstances(LinearLayout* pLayout, int& index);

    private:
        InstanceParams* mInstanceParams = nullptr;
        GLuint mBlockId = 0;
        GLuint mUniformBuffer = 0;
        Carbon::ShaderProgram* mProgram;
    };
}

#endif // __CARBON_BACKGROUND_IMAGE_INSTANCED_RENDERER__