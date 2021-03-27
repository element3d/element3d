#ifndef __GLBUTTON__
#define __GLBUTTON__

#include "Shape.h"
#include <ctime>

namespace Carbon
{
    enum class EButtonState
    {
        Pressed,
        Released
    };
};

namespace e3
{

    class Button : public Shape
    {
    public:
        Button();

    public:
        virtual void Render() override ;

        virtual void Update() override;

        virtual bool OnClick(const glm::vec2 &pos) override;

        virtual bool OnPointerUp(const glm::vec2 &pos) override;

    private:

    };
}
#endif // __GLBUTTON__
