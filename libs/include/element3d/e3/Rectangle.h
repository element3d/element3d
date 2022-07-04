#ifndef __E3_RECTANGLE__
#define __E3_RECTANGLE__

#include <e3/Container.h>
#include <e3/Canvas.h>

namespace e3
{
	class Rectangle : public Container
	{
	public:
		Rectangle();
		~Rectangle() {}

	public:
		virtual void Render() override;
		/*virtual void RenderShadow() override;
		virtual void RenderToTexture();*/
		virtual void Update() override;

	public:
		void SetColor(const glm::vec4& color);
		glm::vec4 GetColor();

	private:
		RectangleRenderParams* mParams = nullptr;
	};
}

#endif // __E3_RECTANGLE__