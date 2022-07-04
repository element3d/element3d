#ifndef __E3_ELEMENT__
#define __E3_ELEMENT__

#include <e3/internal/ElementBase.h>
#include <e3/Enum.h>
#include <e3/Types.h>
#include <e3/Animation.h>
#include <e3/Timeout.h>
#include <e3/Style.h>
#include <e3/RenderTarget.h>
#include <e3/Camera.h>
#include <e3/MouseEvent.h>
#include <e3/ScaleEvent.h>

#include <glm/glm.hpp>
#include <memory>

namespace e3
{
	class Animation;
	class Application;
	class Element : public _e3::ElementBase
	{
		typedef std::function<void(void)> OnLoadCallback;
		typedef std::function<void(const glm::vec2&)> OnScrollCallback;

	public:
		Element(Element* pParent = nullptr);
		virtual ~Element();

	public:
		virtual void Build();
		virtual void Render();
		void Render2();
		virtual void Update();
		virtual void OnLoad() {}
		virtual void OnResume() {}
		void SetOnLoadCallback(OnLoadCallback onLoadCallback);
		void SetOnScrollCallback(OnScrollCallback onScrollCallback);
	public:
		static Application* GetApplication();

    public:
        virtual bool OnClick(MouseEvent* pEvent);
		virtual bool OnDoubleClick(MouseEvent* pEvent);
		virtual bool OnLongClick(MouseEvent* pEvent);
        virtual bool OnScale(ScaleEvent* pEvent);
        virtual void OnMouseMove(MouseEvent* pEvent);
		virtual void OnMouseWhell(MouseEvent* pEvent);
        virtual bool OnMouseDown(MouseEvent* pEvent);
		virtual bool OnMouseLongDown(MouseEvent* pEvent);
        virtual bool OnMouseUp(MouseEvent* pEvent);
		virtual void OnMouseEnter(MouseEvent* pEvent);
		virtual void OnMouseHover(MouseEvent* pEvent);
		virtual void OnMouseLeave(MouseEvent* pEvent);

    public:
        void SetOnClickCallback(OnClickCallback callback);
		void SetOnDoubleClickCallback(OnDoubleClickCallback callback);
		void SetOnLongClickCallback(OnLongClickCallback callback);
		void SetOnMouseDownCallback(OnMouseDownCallback callback);
		void SetOnMouseUpCallback(OnMouseUpCallback callback);
		void SetOnMouseLongDownCallback(OnMouseLongDownCallback callback);
		void SetOnMouseMoveCallback(OnMouseMoveCallback callback);
		void SetOnMouseEnterCallback(OnMouseEnterCallback callback);
		void SetOnMouseHoverCallback(OnMouseHoverCallback callback);
		void SetOnMouseLeaveCallback(OnMouseLeaveCallback callback);
        void SetOnStateChangeCallback(OnStateChangeCallback callback);
        void SetOnScaleCallback(OnScaleCallback callback);

        /*void setOnFocusOutCallback(OnFocusOutCallback callback) {
            mOnFocusOutCallback = callback;
        }*/

    public:
		virtual e3::Element* Clone();

        void SetId(int id);
        int GetId() const;

        const EElementType GetType() const;
		void SetElementType(EElementType type);

        void SetUsrPtr(void* pUsrPtr);
        void* GetUsrPtr();

		virtual void SetParent(e3::Element* pParent);
        Element* GetParent() const;

		void SetStopEvents(bool stopEvents);
		bool GetStopEvents();

		virtual void Focus();
		virtual void Unfocus();

	public: // Style
		// Width, height
		virtual void SetWidth(const Dim& width);
		virtual void SetWidthPercent(int percent);
		virtual void SetHeight(const Dim& height);
		virtual void SetHeightPercent(int percent);

		void SetMaxWidth(const Dim& width);
		void SetMaxWidthPercent(int percent);
		void SetMaxHeight(const Dim& height);
        void SetMaxHeightPercent(int percent);

		void SetMinWidth(const Dim& width);
		void SetMinWidthPercent(int percent);
		void SetMinHeight(const Dim& height);
		void SetMinHeightPercent(int percent);

		// Padding
		void SetPadding(const Dim& padding);
		void SetPaddingPercent(int percent);

		void SetPaddingTop(const Dim& padding);
		void SetPaddingTopPercent(int percent);

		void SetPaddingBottom(const Dim& padding);
		void SetPaddingBottomPercent(int percent);

		void SetPaddingLeft(const Dim& padding);
		void SetPaddingLeftPercent(int percent);

		void SetPaddingRight(const Dim& padding);
		void SetPaddingRightPercent(int percent);

        float GetPaddingTop();
        float GetPaddingBottom();
		float GetPaddingLeft();
		float GetPaddingRight();

		// Margin
		void SetMargin(const Dim& margin);
		void SetMarginPercent(int percent);

		void SetMarginTop(const Dim& margin);
		void SetMarginTopPercent(int percent);

		void SetMarginBottom(const Dim& margin);
		void SetMarginBottomPercent(int percent);

		void SetMarginLeft(const Dim& margin);
		void SetMarginLeftPercent(int percent);

		void SetMarginRight(const Dim& margin);
		void SetMarginRightPercent(int percent);

        float GetMarginTop();
        float GetMarginBottom();
        float GetMarginLeft();
        float GetMarginRight();
		float GetMargin();

		// Shape type
		void SetShapeType(EShapeType shapeType);
		const EShapeType GetShapeType() const;

		// AspectRatio
		void SetAspectRatio(float aspectRatio);

		// Absolute distance
		void SetPositionType(EPositionType positionType);
		EPositionType GetPositionType();

		float GetTop();
		void SetTop(const Dim& value);
		void SetTopPercent(int percent);

		float GetBottom();
		void SetBottom(const Dim& value);
		void SetBottomPercent(int percent);

		float GetLeft();
		void SetLeft(const Dim& value);
		void SetLeftPercent(int percent);

		float GetRight();
		void SetRight(const Dim& value);
		void SetRightPercent(int percent);

		// Border
		void SetBorderType(EBorderType borderType);
		EBorderType GetBorderType();

		virtual void SetBorderRadius(float radius);
		virtual void SetBorderRadius(const glm::vec4 &radius);
		const glm::vec4& GetBorderRadius() const;

		void SetBorderSize(const Dim& value);
		const float GetBorderSize() const;

		void SetBorderColor(const glm::vec4 &color);
		const glm::vec4& GetBorderColor() const;

		// Background color
		virtual void SetBackgroundColor(const glm::vec4 &color);
		virtual glm::vec4 GetBackgroundColor();

		// Background gradient
		void SetBackgroundLinearGradient(float degree, const glm::vec4& color1, const glm::vec4& color2);
		void SetBackgroundRadialGradient(const glm::vec2& offset, float innerRadius, float outerRadius, const glm::vec4& innerColor, const glm::vec4& outerColor);

		// Background image
		void SetBackground(const e3::Background& background);
		std::shared_ptr<Image> GetBackgroundImage();
		void SetBackgroundImagePath(const std::string &path);
		void SetBackgroundImage(const std::string &path);
		void SetBackgroundImageAsync(const std::string &asset);
		void SetBackgroundImageAsset(const std::string &asset);
		//void SetBackgroundImage(int id);
		void SetBackgroundImage(const std::string &path, OnImageLoadCallback callback);
		void SetBackgroundImage(const std::string &path, OnImageLoadCallback1 callback);

		void SetBackgroundImage(std::shared_ptr<Image> pImage);

		void SetBackgroundImageOpacity(float opacity);

		void SetBackgroundImageFit(EBackgroundSize fit);
		void SetBackgroundImagePosition(EBackgroundPosition position);

		void SetBackgroundImageColor(const glm::vec4& color);
		const glm::vec4& GetBackgroundImageColor() const;

		// Other styles
		void SetClipRect(const e3::ClipRect2f& clipRect);
		void UnsetClipRect();

		void SetSmoothFactor(float smoothFactor);
		float GetSmoothFactor();

        void SetScaling(EScaling scaling);
        EScaling GetScaling();

        virtual void SetOpacity(float opacity);
        float GetOpacity();

        void SetVisibility(EVisibility visibility);
        EVisibility GetVisibility();

		void SetWrap(EWrap wrap);
		EWrap GetWrap();

		virtual void SetEnabled(bool enabled);
		bool GetEnabled();

		void SetShapeOffset(const glm::vec3& offset);
		glm::vec3 GetShapeOffset();

		void SetInverted(bool inverted);
		bool GetInverted();

        void SetShadow(const e3::ShadowParams& shadowParams);
        const e3::ShadowParams* GetShadow();

		void SetLinearGradient(const e3::LinearGradientParams& linearGradientParams);
		const e3::LinearGradientParams* GetLinearGradient();

		void SetOverflow(EOverflow overflow);

        Rect2f GetRect();
        e3::Rect2f GetGeometry();

        void SetZ(float z);
        float GetZ();

        void SetIndex(int index);
        void* GetNode();

        virtual float GetMaxZ();

		EElementState GetState();

		void SetCamera(std::shared_ptr<Camera> pCamera, bool recursive = false);
		std::shared_ptr<Camera> GetCamera();

	public: // Transform
		virtual void Translate(const glm::vec3 &direction);
		//virtual void Translate(const glm::vec3 &direction, bool recursive);
		virtual void SetTranslation(const glm::vec3 &direction);
		//virtual void SetTranslation(const glm::vec3 &direction, bool recursive);
		virtual void SetTranslation(const glm::mat4& translation);
		virtual void SetTranslation(float value, EOrientation direction);
		const glm::mat4 &GetTranslation() const;

		virtual void Rotate(float degrees, const glm::vec3 &direction, ETransformAlignment transformAlignment);
		//virtual void Rotate(float degrees, const glm::vec3 &direction, bool recursive);

		virtual void SetRotation(float degrees, const glm::vec3 &direction, ETransformAlignment transformAlignment);
		// virtual void SetRotation(float degrees, const glm::vec3 &direction, bool recursive);

		virtual void Scale(const glm::vec3 &direction, ETransformAlignment transformAlignment);
		virtual void SetScale(const glm::vec3 &direction, ETransformAlignment transformAlignment);
		glm::vec3 GetScale();

	public: // Container
		void SetOrientation(EOrientation orientation);
		EOrientation GetOrientation();

		void SetReversed(bool reversed);
		bool GetReversed();

		void SetAlignItemsVer(e3::EAlignment alignment);
		void SetAlignItemsHor(e3::EAlignment alignment);

		e3::EAlignment GetAlignItemsVer();
		e3::EAlignment GetAlignItemsHor();

		const std::vector<e3::Element*>& GetChildren();
		int GetNumChildren();

		bool Contains(Element* pElement);

	public:
		virtual void AddElement(Element* pElement);
		void InsertElement(int index, Element *pElement);
		Element* FindElementById(int id);

		void RemoveElement(Element* pElement);
		void RemoveElement(Element* pElement, bool destroyElement);

		void RemoveElementById(int id);
		void RemoveElementById(int id, bool destroyElement);

		void RemoveElementByIndex(int index);
		void RemoveElementByIndex(int index, bool destroyElement);

		void PopElement();
		void PopElement(bool destroyElement);

		void RemoveAllElements();
		void RemoveAllElements(bool destroyElements);

		void Clear();
		void Clear(bool destroyElements);

		bool Scroll(const glm::vec3& direction);

		public:
			glm::vec2 GetScrollVec();
			void RegisterCallable(Callable* pCallable);

	protected:
		friend class Application;
		int GetMaxStecilLayer();
		int GetMaxStecilLayer(e3::Element* pE);
		bool _ScrollUnsafe(const glm::vec3& direction);
		int mStencilLayer = 1;
		bool mPicked = false;
		OnLoadCallback mOnLoadCallback = nullptr;
		OnScrollCallback mOnScrollCallback = nullptr;
		
		std::vector<Callable*> mRegisteredCallables;
		e3::Size2i mLastUpdatedScreenSize;
    };

}

#endif // __E3_ELEMENT__
