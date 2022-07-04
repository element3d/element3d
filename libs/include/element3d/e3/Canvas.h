#ifndef __E3_CANVAS__
#define __E3_CANVAS__

#include <Carbon.h>
#include <e3/ShapeRectangle.h>
#include <e3/ShapeCircle.h>
#include <e3/Types.h>

namespace e3 
{
	typedef struct CircleRenderParams
	{
		Rect2f Rect;
		glm::mat4 Translate;
		glm::mat4 Scale;
		glm::mat4 Rotate;
		glm::vec4 Color;
		float     Opacity;
	} RectangleRenderParams;

	class Canvas 
	{
	public:
		static Canvas* Get();
		static void Destroy();

		~Canvas() {}

	public:
		void RenderRectangle(const RectangleRenderParams* pParams);
		void RenderCircle(const CircleRenderParams* pParams);

	private:
		Canvas();

	private:
		static Canvas* sInstance;
		GLuint mVAO = 0;

		struct
		{
			ShapeRectangle* Shape = nullptr;
			Carbon::ShaderProgram* Program = nullptr;
		} mRectangle;

		struct
		{
			ShapeCircle* Shape = nullptr;
			Carbon::ShaderProgram* Program = nullptr;
		} mCircle;

		glm::mat4 mProjection;
		glm::mat4 mView;
	};
}

#endif // __E3_CANVAS__
