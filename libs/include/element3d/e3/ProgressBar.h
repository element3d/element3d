#ifndef __CARBON_PROGRESS_BAR__
#define __CARBON_PROGRESS_BAR__

#include "Shape.h"
#include <glm.hpp>
#include "ShapeRenderer.h"

namespace e3
{
    class ProgressBar : public e3::Shape
    {
    public:
        ProgressBar();
        ~ProgressBar();

    public:
        void Render() override;
        void Update() override;

    public:
        void SetValueColor(const glm::vec3& valueColor) { mValueColor = glm::vec4(valueColor / 255.f, 1.0); }
        void SetValueColor(const glm::vec4& valueColor) { mValueColor = valueColor / 255.f; }
        glm::vec4 GetValueColor() { return mValueColor; }

        void SetValue(int value) { mValue = std::max(0, std::min(100, value)); }
        int GetValue() { return mValue; }

        void setOrientation(EOrientation orientation) { mOrientation = orientation; }
    private:
        glm::vec4 mValueColor = glm::vec4(0.0f);
        int mValue = 0;
        e3::ShapeRenderParams* mBackgroundShapeRenderParam = nullptr;
        e3::ShapeRenderParams* mValueShapeRenderParam = nullptr;
        EOrientation mOrientation = EOrientation::Horizontal;
    };
}

#endif // __CARBON_PROGRESS_BAR__