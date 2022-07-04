#ifndef __E3_FB_LOGIN_MANAGER_LITE__
#define __E3_FB_LOGIN_MANAGER_LITE__

#include <string>
#include <functional>

namespace e3
{

    typedef std::function<void(const std::string& accessToken)> OnFBLoginSuccessCallback;
    typedef std::function<void(const std::string& error)> OnFBLoginErrorCallback;

    class Activity;
    class FBLoginManagerLite
    {
    public:
		static FBLoginManagerLite* get();

    public:
        void logInWithReadPermissions
        (
            Activity* pActivity,
            OnFBLoginSuccessCallback onSuccessCallback,
            OnFBLoginErrorCallback onErrorCallback
        );
		void onLoginSuccess(const std::string& accessToken);
		void onLoginError(const std::string& error);

    private:
        static FBLoginManagerLite* sInstance;
        std::string mAccessToken = "";
        OnFBLoginSuccessCallback mOnFBLoginSuccessCallback = nullptr;
        OnFBLoginErrorCallback mOnFBLoginErrorCallback = nullptr;
    };
}

#endif // __E3_FB_LOGIN_MANAGER_LITE__