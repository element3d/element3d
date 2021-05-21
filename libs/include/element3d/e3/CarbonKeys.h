#ifndef __CARBON_KEYS__
#define __CARBON_KEYS__

#include <string>

namespace e3
{
	enum class EMod 
	{
		Shift = 0x0001,
		Control = 0x0002,
		Alt = 0x0003,
	};

    enum class EKey
    {
        KeyUnknown = -1,

        NumbersBegin = 48,
        Key_0 = static_cast<int>(NumbersBegin),
        Key_1,
        Key_2,
        Key_3,
        Key_4,
        Key_5,
        Key_6,
        Key_7,
        Key_8,
        Key_9,
        NumbersEnd = static_cast<int>(Key_9),

        UpperCaseBegin = 65,
        Key_A = static_cast<int>(UpperCaseBegin),
        Key_B,
        Key_C,
        Key_D,
        Key_E,
        Key_F,
        Key_G,
        Key_H,
        Key_I,
        Key_J,
        Key_K,
        Key_L,
        Key_M,
        Key_N,
        Key_O,
        Key_P,
        Key_Q,
        Key_R,
        Key_S,
        Key_T,
        Key_U,
        Key_V,
        Key_W,
        Key_X,
        Key_Y,
        Key_Z,
        UpperCaseEnd = static_cast<int>(Key_Z),

        LowerCaseBegin = 97,
        Key_a = static_cast<int>(LowerCaseBegin),
        Key_b,
        Key_c,
        Key_d,
        Key_e,
        Key_f,
        Key_g,
        Key_h,
        Key_i,
        Key_j,
        Key_k,
        Key_l,
        Key_m,
        Key_n,
        Key_o,
        Key_p,
        Key_q,
        Key_r,
        Key_s,
        Key_t,
        Key_u,
        Key_v,
        Key_w,
        Key_x,
        Key_y,
        Key_z,
        LowerCaseEnd = static_cast<int>(Key_z),

        KeyShift = 150,
//		KeyCapsLock,
        KeyEnter,
        KeySpace,
        KeyBackspace,
		KeyDelete,
        KeyExclamation,
        KeyAtSign,
        KeyNumberSign,
        KeyDollarSign,
        KeyPercent,
        KeyAmpersand,
        KeyPlus,
        KeyQuestionMark,
        KeySlash,
        KeyAsterisk,
        KeyUnderscore,
        KeyDoubleQuote,
        KeySingleQuote,
        KeyLeftParenthesis,
        KeyRightParenthesis,
        KeyMinus,
        KeyColon,
        KeySemicolon,
        KeyComma,
        KeyPeriod,
        KeyEqualSign,
        KeyUp,
        KeyDown,
        KeyEnd,
        KeyHome,
		KeyLeft,
		KeyRight,
		KeyLeftControl,
		KeyRightControl,
    };

    class Keys
    {
    public:
        Keys() {}

    public:
        char GetCharacter(EKey key)
        {
            if (key >= EKey::UpperCaseBegin && key <= EKey::UpperCaseEnd)
            {
                return mUpperCase[(static_cast<int>(key) - static_cast<int>(EKey::UpperCaseBegin))];
            }

            if (key >= EKey::LowerCaseBegin && key <= EKey::LowerCaseEnd)
            {
                return mLowerCase[(static_cast<int>(key) - static_cast<int>(EKey::LowerCaseBegin))];
            }

            if (key >= EKey::NumbersBegin && key <= EKey::NumbersEnd)
            {
                return mNumbers[(static_cast<int>(key) - static_cast<int>(EKey::NumbersBegin))];
            }

            switch (key)
            {
            case EKey::KeyBackspace:
                return 0;
            case EKey::KeySpace:
                return ' ';
            case EKey::KeyExclamation:
                    return '!';
            case EKey::KeyAtSign:
                return '@';
            case EKey::KeyNumberSign:
                return '#';
            case EKey::KeyDollarSign:
                return '$';
            case EKey::KeyPercent:
                return '%';
            case EKey::KeyAmpersand:
                return '&';
            case EKey::KeyPlus:
                return '+';
            case EKey::KeyQuestionMark:
                return '?';
            case EKey::KeySlash:
                return '/';
            case EKey::KeyAsterisk:
                return '*';
            case EKey::KeyUnderscore:
                return '_';
            case EKey::KeyDoubleQuote:
                return '"';
            case EKey::KeySingleQuote:
                return '\'';
            case EKey::KeyLeftParenthesis:
                return '(';
            case EKey::KeyRightParenthesis:
                return ')';
            case EKey::KeyMinus:
                return '-';
            case EKey::KeyColon:
                return ':';
            case EKey::KeySemicolon:
                return ';';
            case EKey::KeyComma:
                return ',';
            case EKey::KeyPeriod:
                return '.';
            case EKey::KeyEqualSign:
                return '=';
            default:
                return 0;
            }
        }

    private:
        std::string mLowerCase = "abcdefghijklmnopqrstuvwxyz";
        std::string mUpperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::string mNumbers = "0123456789";
    };
}

#endif // __CARBON_KEYS__