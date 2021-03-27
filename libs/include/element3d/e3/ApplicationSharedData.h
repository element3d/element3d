#ifndef __CARBON_APPLICATION_SHARED_DATA__
#define __CARBON_APPLICATION_SHARED_DATA__

#include "Carbon.h"
#include "Context.h"
#include <Carbon/Texture.h>
#include <mutex>
#include <glm/glm.hpp>
#include <e3/Types.h>
#include <e3/SelectionLayer.h>
#include <e3/Camera.h>

/*namespace e3
{
	class ApplicationSharedData;
}

extern e3::ApplicationSharedData* sInstance;*/

namespace e3
{
    class DropdownLayout;
   // class Container;
	class Application;

    struct Viewport
    {
        float Width;
        float Height;
    };

    class ApplicationSharedData
    {
    public:
        static ApplicationSharedData* Get();

        static void Destroy() { delete sInstance; }

    public:
        void SetApplication(e3::Application* pContext) { mApplication = pContext; }
        e3::Application* GetApplication() { return mApplication; }

        void SetContext(e3::Context* pContext) { mContext = pContext; }
        e3::Context* GetContext() { return mContext; }

        void SetOverflowMaskTexture(GLuint pOverflowMaskTexture) { mOverflowMaskTexture = pOverflowMaskTexture; }
        GLuint GetOverflowMaskTexture() { return mOverflowMaskTexture; }

        void AddMouseDownElement(Element* pMouseDownElement) { mMouseDownElements[pMouseDownElement] = true; }
		void RemoveMouseDownElement(Element* pMouseDownElement) 
		{
			std::map<Element*, bool>::iterator iter = mMouseDownElements.find(pMouseDownElement);
			if (iter != mMouseDownElements.end())
				mMouseDownElements.erase(iter);
			//mMouseDownElements.erase(std::remove(mMouseDownElements.begin(), mMouseDownElements.end(), pMouseDownElement), mMouseDownElements.end());
		}
        std::map<Element*, bool> GetMouseDownElements() { return mMouseDownElements; }
		void ClearMouseDownElements() { mMouseDownElements.clear(); }      

        void SetShadowTexture(GLuint pShadowTexture) { mShadowTexture = pShadowTexture; }
        GLuint GetShadowTexture() { return mShadowTexture; }

        void SetBloomTexture(GLuint pBloomTexture) { mBloomTexture = pBloomTexture; }
        GLuint GetBloomTexture() { return mBloomTexture; }

        void SetProjection(const glm::mat4& projection) { mProjection = projection; }
        const glm::mat4& GetProjection() const { return mProjection; }

        void SetCamera(std::shared_ptr<Camera> pCamera) { mCamera = pCamera; }
        std::shared_ptr<Camera> GetCamera() const { return mCamera; }

        void SetKeyboardTransform(const glm::mat4& projection) { mKeyboardTransform = projection; }
        const glm::mat4& GetKeyboardTransform() const { return mKeyboardTransform; }

        void SetKeyboardTransformY(float y) { mKeyboardTransformY = y; }
        const float GetKeyboardTransformY() const { return mKeyboardTransformY; }

        std::mutex& GetScrollMutex() { return mScrollMutex; }
        float GetZDiff() { return mZDiff; }

        void SetDropdownLayout(DropdownLayout* pl) { mDropdownLayout = pl; }
        DropdownLayout* GetDropdownLayout() { return mDropdownLayout; }

        void SetDialogContainer(e3::Element* pDialogContainer) { mDialogContainer = pDialogContainer; }
        e3::Element* GetDialogContainer() { return mDialogContainer; }

        void SetSelectionLayer(e3::SelectionLayer* pSelectionLayer) { mSelectionLayer = pSelectionLayer; }
        e3::SelectionLayer* GetSelectionLayer() { return mSelectionLayer; }

        void SetShowKeyboard(bool show) { mShowKeyboard = show; }
        bool GetShowKeyboard() { return mShowKeyboard; }

        void SetViewport(float width, float height) { mViewport.Width = width; mViewport.Height = height; }
        Viewport GetViewport() { return mViewport; }

        const Rect2f& GetScreenRect() const { return mScreenRect; }
        const Rect2f& GetScreenRectGL() const { return mGLScreenRect; }
        void SetScreenRect(const Rect2f& rect);

        const Size2f& GetOptimalScreenSize() const { return mOptimalScreenSize; }
        void SetOptimalScreenSize(const Size2f& size) { mOptimalScreenSize = size; }

        const Size2f& GetResolution() const { return mResolution; }
        void SetResolution(const Size2f& resolution)
        {
                mResolution = resolution;
                mResolutionScale.x = mResolution.Width / mScreenRect.width;
                mResolutionScale.y = mResolution.Height / mScreenRect.height;
        }
		void SetWindowSize(const Size2i& size) 
		{
			mWindowSize = size;
		}
		Size2i GetWindowSize() { return mWindowSize; }

        glm::vec2 GetResolutionScale() { return mResolutionScale; }

		void SetApplicationDataDirectory(const std::string& dir);
		std::string GetApplicationDataDirectory();
    private:
		ApplicationSharedData();
        ~ApplicationSharedData() {}

    private:
        static ApplicationSharedData* sInstance;
      	std::string mApplicationDataDirectory;
		bool mRequestYogaUpdate = false;
        Rect2f mScreenRect;
		Size2i mWindowSize;
        Rect2f mGLScreenRect;
        Size2f mOptimalScreenSize;
        Size2f mResolution;
        glm::vec2 mResolutionScale = glm::vec2(1.0f);
        glm::mat4 mProjection;
        std::shared_ptr<Camera> mCamera;
        glm::mat4 mKeyboardTransform;
        float mKeyboardTransformY = 0;
		GLuint mOverflowMaskTexture = 0;
        GLuint mShadowTexture = 0;
        GLuint mBloomTexture = 0;
        std::mutex mScrollMutex;
        e3::Context* mContext;
        float mZDiff = 0.1f;
        DropdownLayout* mDropdownLayout = nullptr;
        e3::Element* mDialogContainer = nullptr;
		e3::SelectionLayer* mSelectionLayer = nullptr;
        bool mShowKeyboard = false;
        Viewport mViewport;
        Application* mApplication = nullptr;
        //Element* mMouseDownElement = nullptr;
		std::map<Element*, bool> mMouseDownElements;
        Element* mMouseMoveElement = nullptr;

    };
}

#endif // __CARBON_APPLICATION_SHARED_DATA__
