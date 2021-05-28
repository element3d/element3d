#ifndef __E3_TYPES__
#define __E3_TYPES__

#include "Enum.h"
#include <algorithm>
#include <functional>
#include <cmath>
#include "MouseEvent.h"
#include "ScaleEvent.h"
#include <glm/glm.hpp>

template<class _Rp>
class Callback
{
public:
	std::function<_Rp> f;
	bool s = false;
	Callback(std::function<_Rp> ff) { f = ff; s = true; }
	Callback() {}
	void Unsubscribe() { s = false; }
	bool GetSubscribed() { return s; }
};

namespace e3
{
	class Element;

	typedef std::function<void(MouseEvent* pEvent)> OnClickCallback;
	typedef std::function<void(MouseEvent* pEvent)> OnDoubleClickCallback;
	typedef std::function<void(MouseEvent* pEvent)> OnMouseLongDownCallback;
	typedef std::function<void(MouseEvent* pEvent)> OnMouseDownCallback;
	typedef std::function<void(ScaleEvent* pEvent)> OnScaleCallback;
	typedef std::function<void(MouseEvent* pEvent)> OnMouseUpCallback;
	typedef std::function<void(MouseEvent* pEvent)> OnLongClickCallback;
	typedef std::function<void(MouseEvent* pEvent)> OnMouseMoveCallback;
	typedef std::function<void(MouseEvent* pEvent)> OnMouseEnterCallback;
	typedef std::function<void(MouseEvent* pEvent)> OnMouseHoverCallback;
	typedef std::function<void(MouseEvent* pEvent)> OnMouseLeaveCallback;
	typedef std::function<void(EElementState state)> OnStateChangeCallback;
	typedef std::function<void(void)> OnSubmitCallback;

	struct Point2f
	{
		float x;
		float y;

		Point2f() = default;
		Point2f(float xx, float yy) { x = xx; y = yy; }
	};

	struct Size2f
	{
		float Width;
		float Height;

		Size2f() { Width = 0.0f; Height = 0.0f; }
		Size2f(float w, float h) { Width = w; Height = h; }
	};

	struct Size2i
	{
		int Width;
		int Height;

		Size2i() { Width = 0.0f; Height = 0.0f; }
		Size2i(int w, int h) { Width = w; Height = h; }
	};

	struct Rect2f 
	{
		float x;
		float y;
		float width;
		float height;
		Rect2f() { x = 0; y = 0; width = 0; height = 0; }
		Rect2f(float xx, float yy, float w, float h) { x = xx; y = yy; width = w; height = h; }

		Point2f tl()
		{
			return Point2f(x, y);
		}

		Point2f br()
		{
			return Point2f(x + width, y + height);
		}

		bool contains(const Point2f& p)
		{
                        if (p.x >= x && p.y >= y && p.x <= x + width && p.y <= y + height) return true;

			return false;
		}

                bool containsRect(Rect2f r)
		{
                    Point2f tl = r.tl();
                    Point2f br = r.br();
                    return contains(tl) && contains(br);
		}

		bool containsX(float x)
		{
			if (x >= this->x && x <= this->x + width) return true;

			return false;
		}

		bool containsY(float y)
		{
			if (y >= this->y && y <= this->y + height) return true;

			return false;
		}

		bool contains(const glm::vec2& p)
		{
			if (p.x >= x && p.y > y && p.x <= x + width && p.y <= y + height) return true;

			return false; 
		}

		Rect2f operator&(const Rect2f& other) 
		{
			float xx = std::max(x, other.x);
			float yy = std::max(y, other.y);
			float w = std::min(x + width, other.x + other.width) - xx;
			float h = std::min(y + height, other.y + other.height) - yy;
			return Rect2f(xx, yy, w, h);
		}

	
	};
	struct Dim;
	struct DimValue
	{
		float Value;
		e3::EUnit Unit;

		DimValue() { Value = 0; Unit = e3::EUnit::Pixel; }
		DimValue(const Dim& d);
		DimValue(const std::string& exp);
		DimValue(const char* exp);
		DimValue(float value) { Value = value; Unit = e3::EUnit::Pixel; }
		DimValue(double value) { Value = value; Unit = e3::EUnit::Pixel; }
		DimValue(int value) { Value = value; Unit = e3::EUnit::Pixel; }
		
		operator float() const { return Value; }

		void operator=(const Dim& d);
		void operator=(float value);
		void operator=(double value);
		void operator=(int value);
		void operator=(const std::string& exp);
		void operator=(const char* exp);
	};

	struct DimItem
	{
		DimValue Small;
		DimValue Medium;
		DimValue Large;
	};

	struct Dim
	{
		DimItem Mobile;
		DimItem Desktop;
		
		Dim() {}
		Dim(float value);
		Dim(int value);
		Dim(double value);
		Dim(const std::string& exp);
		Dim(const char* exp);
		Dim(const DimValue& value);
		Dim(const DimValue& mobileSmall, const DimValue& mobileMedium, const DimValue& mobileLarge, const DimValue& dekstopSmall, const DimValue& dekstopMedium, const DimValue& dekstopLarge);

		void operator=(const DimValue& v);
		//operator DimValue() const;
		operator float() const;
	};


	struct Transform
	{
		glm::mat4 Translate;
		glm::mat4 Rotate;
		glm::mat4 Scale;
	};

	struct ShadowParams
	{
		glm::vec4  Color;
		glm::ivec2 Offset;
		int        BlurSize;
		float      Opacity;
		float      Scale;
	};
}

#endif // __E3_TYPES__
