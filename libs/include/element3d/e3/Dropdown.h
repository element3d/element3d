#ifndef __CARBON_DROPDOWN_VIEW__
#define __CARBON_DROPDOWN_VIEW__

#include "DropdownBody.h"
#include "Enum.h"
#include "Element.h"

namespace e3
{
	typedef std::function<void(EDropdownState)> OnDropdownStateChangeCallback;

    class Dropdown : public Element
    {
    public:
		Dropdown(Element* pParent = nullptr);
		~Dropdown();

		virtual void Render() override;

	public:
		virtual void Expand();
		virtual void Collapse();

		virtual void SetBody(DropdownBody* pBody);
		DropdownBody* GetBody();

		e3::EDropdownState GetDropdownState();

	public:
		virtual void SetTranslation(const glm::vec3 &direction) override;
		//virtual void SetTranslation(const glm::vec3 &direction, bool recursive) override;
		virtual void SetTranslation(const glm::mat4& translation) override;
		virtual void SetTranslation(float value, EOrientation direction) override;

	public:
		bool OnClick(MouseEvent* pEvent) override;

	public:
		void SetOnDropdownStateChangeCallback(OnDropdownStateChangeCallback callback);

    private:
		friend class Context;
        DropdownBody* mBody = nullptr;
        e3::EDropdownState mDropdownState = e3::EDropdownState::Collabsed;
		OnDropdownStateChangeCallback mOnDropdownStateChangeCallback = nullptr;
    };
}

#endif // __CARBON_DROPDOWN_VIEW__