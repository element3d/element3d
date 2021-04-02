#ifndef __E3_ELEMENT__
#define __E3_ELEMENT__

#include <e3/Enum.h>
#include <e3/Types.h>
#include <e3/Animation.h>
#include <e3/Timeout.h>
#include <glm/glm.hpp>
#include <e3/Style.h>
#include "ShapeRenderer.h"
#include <e3/RenderTarget.h>
#include <e3/Camera.h>
#include <e3/MouseEvent.h>
#include <e3/ScaleEvent.h>
#include <memory>

namespace e3
{
	class Animation;
	class Application;
    class Element
    {
		friend class Application;
    public:
        Element(void* pUsrPtr = nullptr);
        virtual ~Element();

    public:
		virtual void Build();
		virtual void Render();
		//virtual void RenderShadow();
		virtual void RenderToTexture();
        virtual void Update();

		Application* GetApplication();

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
        void SetId(int id);
        int GetId() const;
        const EViewType GetType() const;
        void SetElementType(EViewType type) { mType = type; }

        void SetUsrPtr(void* pUsrPtr);
        void* GetUsrPtr();

        void SetParent(e3::Element* pParent);
        Element* GetParent() const;

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

		// Border
		virtual void SetBorderRadius(float radius);
		virtual void SetBorderRadius(const glm::vec4 &radius);
		const glm::vec4& GetBorderRadius() const;

		void SetBorderSize(float borderSize);
		const float GetBorderSize() const;

		void SetBorderColor(const glm::vec4 &color);
		void SetBorderColor(const glm::vec3 &color);
		const glm::vec4& GetBorderColor() const;

		// Background color
		void SetBackgroundColor(const glm::vec4 &color);
		void SetBackgroundColor(const glm::vec3 &color);
		const glm::vec4& GetBackgroundColor() const;

		// Background image
		void SetBackground(const e3::Background& background);
		std::shared_ptr<Image> GetBackgroundImage();
		std::shared_ptr<Image> GetBackgroundImage(int index);
		void SetBackgroundImagePath(const std::string &path);
		//void SetBackgroundImage(int id);
		void SetBackgroundImage(const std::string &path, OnImageLoadCallback callback);
		void SetBackgroundImage(const std::string &path, OnImageLoadCallback1 callback);

		void SetBackgroundImage(std::shared_ptr<Image> pImage);
		void SetBackgroundImage(std::shared_ptr<Image> pImage, int index);

		void SetBackgroundImageOpacity(float opacity);

		void SetBackgroundImageFit(EBackgroundSize fit);
		void SetBackgroundImagePosition(EBackgroundPosition position);

		void SetBackgroundImageColor(const glm::vec4& color);

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

		// Other styles
        void SetScaling(EScaling scaling);
        EScaling GetScaling();

        virtual void SetOpacity(float opacity);
        float GetOpacity();

        void SetVisibility(EVisibility visibility);
        EVisibility GetVisibility();

		void SetWrap(EWrap wrap);
		EWrap GetWrap();

        void SetEnabled(bool enabled);
		bool GetEnabled();

        void SetShadow(const e3::ShadowParams& shadowParams);
        const e3::ShadowParams* GetShadow();

		void SetRipple(const e3::RippleParams& rippleParams);
		const e3::RippleParams* GetRipple();

		void SetOverflow(EOverflow overflow);

        Rect2f GetRect();
        e3::Rect2f GetGeometry();

        void SetZ(float z);
        float GetZ();

        void SetIndex(int index);
        void* GetNode();

        virtual float GetMaxZ();

		EViewState GetState();

		virtual void Focus();
		virtual void Unfocus();

	public: // Transform
		virtual void Translate(const glm::vec3 &direction);
		virtual void Translate(const glm::vec3 &direction, bool recursive);
		virtual void SetTranslation(const glm::vec3 &direction);
		virtual void SetTranslation(const glm::vec3 &direction, bool recursive);
		virtual void SetTranslation(const glm::mat4& translation);
		virtual void SetTranslation(float value, EOrientation direction);
		const glm::mat4 &GetTranslation() const;
		glm::vec3 GetScale();

		virtual void Rotate(float degrees, const glm::vec3 &direction);
		virtual void Rotate(float degrees, const glm::vec3 &direction, bool recursive);

		virtual void SetRotation(float degrees, const glm::vec3 &direction);
		virtual void SetRotation(float degrees, const glm::vec3 &direction, bool recursive);

		virtual void Scale(const glm::vec3 &direction);
		virtual void SetScale(const glm::vec3 &direction);
		virtual void Scale(const glm::vec3 &direction, bool recursive);
		virtual void SetScale(const glm::vec3 &direction, bool recursive);

	public: // Container
		void SetOrientation(EOrientation orientation);
		EOrientation GetOrientation();

		void SetReversed(bool reversed);
		bool GetReversed();

		void SetAlignItemsVer(e3::EAlignment alignment);
		void SetAlignItemsHor(e3::EAlignment alignment);

		e3::EAlignment GetAlignItemsVer();
		e3::EAlignment GetAlignItemsHor();

		std::vector<e3::Element*>& GetChildren();
		int GetNumChildren();

		bool Contains(Element* pElement);

        void SetCamera(std::shared_ptr<Camera> pCamera, bool recursive = false);
        std::shared_ptr<Camera> GetCamera();
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

    public:
        bool HasOnClickCallback();
		void SetVisibilityInternal(EVisibility visibility);
		EVisibility GetVisibilityInternal();
		static Element *GetFocusedElement();

    protected:
        void SetState(EViewState state);
		virtual void SetScrollTranslation(float value, EOrientation direction);
		bool UpdateYoga();
		void UpdateGeometry();
		void UpdateGeometryRecoursive();

	private:
		int FindElementIndexById(int id);
	
	

    protected:
		Style         mStyle;
        void*         mUsrPtr = nullptr;
        e3::Element*  mParent = nullptr;
        int           mId = -1;
        int           mIndex = -1;
        void*         mNode = nullptr;
        EViewType     mType;
        e3::Rect2f    mRect;
		e3::Rect2f    mGeometry;

		float         mOpacityUpdated = false;

        EViewState mState;
        e3::Transform mInternalTransform;
        e3::Transform mTransform;
		glm::vec4 mScrollTranslation;
		glm::mat4 mScrollMatrix;

		e3::ShadowParams* mShadowParams = nullptr;
        bool mUpdateShadows = false;
		bool mUpdateTexture = false;
		e3::RippleParams* mRippleParams = nullptr;
		float mRippleScale = 0.0f;
		glm::vec2 mRipplePosition = glm::vec2(0);
		float mRippleOpacity = 0.0f;
		e3::Animation* mRippleAnimation = nullptr;

        bool mForcedWidth = false;
        bool mForcedHeight = false;

        bool mFocused = false;
        static Element* sFocusedView;

		//bool hasScale = false;

		// Event callbacks
		e3::OnClickCallback mOnClickCallback = nullptr;
		e3::OnDoubleClickCallback mOnDoubleClickCallback = nullptr;
		e3::OnMouseDownCallback mOnDownCallback = nullptr;
		e3::OnScaleCallback mOnScaleCallback = nullptr;
		e3::OnMouseUpCallback mOnUpCallback = nullptr;
		e3::OnLongClickCallback mOnLongClickCallback = nullptr;
		e3::OnMouseLongDownCallback mOnLongDownCallback = nullptr;
		e3::OnMouseMoveCallback mOnMoveCallback = nullptr;
		e3::OnMouseEnterCallback mOnMouseEnterCallback = nullptr;
		e3::OnMouseHoverCallback mOnMouseHoverCallback = nullptr;
		e3::OnMouseLeaveCallback mOnMouseLeaveCallback = nullptr;
		e3::OnStateChangeCallback mOnStateChangeCallback = nullptr;

		
	protected:
		e3::RenderTarget* mRenderTarget = 0;
		ShapeRenderParams* mParams = nullptr;
		glm::vec2 mChildrenScrollDirection = glm::vec2(0);
        std::shared_ptr<Camera> mCamera = nullptr;
		bool mInternalUpdated = false;

	private: // Container props
		std::vector<e3::Element*> mChildren;
		bool mGeometrUpdated = false;
		bool mLayoutUpdated = false;

		struct 
		{
			bool HasWidth = false;
			Dim Width;
			bool HasHeight = false;
			Dim Height;
			bool HasMinWidth = false;
			Dim MinWidth;
			bool HasMinHeight = false;
			Dim MinHeight;
			bool HasMaxWidth = false;
			Dim MaxWidth;
			bool HasMaxHeight = false;
			Dim MaxHeight;

			bool HasPadding = false;
			Dim Padding;
			bool HasPaddingLeft = false;
			Dim PaddingLeft;
			bool HasPaddingRight = false;
			Dim PaddingRight;
			bool HasPaddingTop = false;
			Dim PaddingTop;
			bool HasPaddingBottom = false;
			Dim PaddingBottom;

			bool HasMargin = false;
			Dim Margin;
			bool HasMarginLeft = false;
			Dim MarginLeft;
			bool HasMarginRight = false;
			Dim MarginRight;
			bool HasMarginTop = false;
			Dim MarginTop;
			bool HasMarginBottom = false;
			Dim MarginBottom;

			bool HasLeft = false;
			Dim Left;
			bool HasRight = false;
			Dim Right;
			bool HasTop = false;
			Dim Top;
			bool HasBottom = false;
			Dim Bottom;
		} mDims;

    };

}

#endif // __E3_ELEMENT__
