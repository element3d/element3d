#ifndef __E3_CIRCLE__
#define __E3_CIRCLE__

#include <e3/Container.h>
#include <e3/Canvas.h>

namespace e3 
{
	class Circle : public Container
	{
	public:
		Circle();
		~Circle() {}

	public:
		virtual void Render() override;
		/*virtual void RenderShadow() override;
		virtual void RenderToTexture();*/
		virtual void Update() override;

	public:
		void SetColor(const glm::vec4& color);
		glm::vec4 GetColor();

	private:
		CircleRenderParams* mParams = nullptr;
	};
}

#endif // __E3_CIRCLE__