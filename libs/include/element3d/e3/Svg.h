#ifndef __E3_SVG__
#define __E3_SVG__

#include <e3/Element.h>
#include "Image.h"
#include "Carbon/ShaderProgram.h"

namespace e3
{
    class Svg : public Element
    {
    public:
        Svg();
        ~Svg();

    public:
        void Render() override;

    public:
        void SetSvg(int id);

    private:
        Image* mImage = nullptr;
        Carbon::ShaderProgram* mProgram = nullptr;
    };
}

#endif // __E3_SVG__