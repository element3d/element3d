#ifndef __E3_TEXT__
#define __E3_TEXT__

#include "internal/TextBase.h"
#include "Font.h"
#include <memory>
#include <e3/i18n.h>



namespace Carbon 
{
	class ShaderProgram;
}

namespace e3 
{
	class Text : public _e3::TextBase
	{
	public:
		Text(Element* pParent = nullptr);
		~Text();

	public:
		virtual void Render() override;
		virtual void Build() override;
		virtual void Update() override;

	public:
		virtual void SetWidth(const Dim& width) override;
		virtual void SetHeight(const Dim& height) override;

		void SetText(const std::string& text);
		void SetText(const std::string& text, bool translate);
		std::string GetText();

		void SetFontSize(const Dim& fontSize);
		e3::Dim GetFontSize();

		void SetFont(const std::string& font);
		void SetFontFamily(const std::string& fontFamily);
		void SetFontStyle(EFontStyle fontStyle);
		virtual void SetTextColor(const glm::vec4& color);
		glm::vec4 GetTextColor();

		// virtual void SetScale(const glm::vec3 &direction) override;

		void SetTextAlignVer(e3::EAlignment alignment);
		e3::EAlignment GetTextAlignVer();

		void SetTextAlignHor(e3::EAlignment alignment);
		e3::EAlignment GetTextAlignHor();

		void SetMaxNumLines(int maxNumLines);
		int GetMaxNumLines();

		void SetTextOverflow(ETextOverflow textOverflow);
	};
}

#endif // __E3_TEXT__
