#ifndef __CARBON_PICKER__
#define __CARBON_PICKER__

//#include "Container.h"
#include "DropdownLayout.h"

namespace e3
{
    class Picker
    {
    public:
        Picker()
        {

        }

    public:
        Element* PickPrivate(Element* topView, glm::vec2 pos)
        {
            Container* top = dynamic_cast<Container*>(topView);
			if (!top) 
			{
				return topView;
			}

            Element* ppPickedView = top;
			bool found = false;
            for (int i = 0; i < top->GetNumChildren(); ++i)
            {
                Element* pView = top->GetChildren()[i];
                if (pView->GetGeometry().contains(pos))
                {

                    /*LinearLayout* pl = nullptr;
                    if (pView->Type() == EViewType::LinearLayout)
                    {
                        pl = static_cast<LinearLayout*>(pView);
                        return pl->onClick(pos);
                    }*/
                    /*if (pView->Type() == EViewType::DropdownLayout)
                    {
                        DropdownLayout* pDropdownLayout = dynamic_cast<DropdownLayout*>(pView);
                        EDropdownState state = pDropdownLayout->GetDropdownState();
                        if (state == EDropdownState::Collabsed) continue;
                        ppPickedView = PickPrivate(pView, pos, ppPickedView);
                        return ppPickedView;
                    }*/

					if (pView->GetOpacity() > 0.0 && pView->GetType() != EViewType::DropdownLayout && (!ppPickedView || ppPickedView->GetZ() < pView->GetZ()))
					{
						found = true;
						ppPickedView = pView;
					}
//                    if (!ppPickedView) ppPickedView = pView;
//                    else pView->GetZ() > (ppPickedView)->GetZ() ? ppPickedView = pView : mPickedView = mPickedView;
//                    pView->onClick(pos);
//                    /*if (pView->HasOnClickCallback())
//                        return ppPickedView;*/
//                    ppPickedView = PickPrivate(pView, pos, ppPickedView);
//                    return ppPickedView;
                }
            }

            //if (ppPickedView->HasOnClickCallback()) ppPickedView->OnClick(pos);
			if (!found) {
				return ppPickedView;
			}
			if (ppPickedView->GetType() == EViewType::EditText) {
				return ppPickedView;
			}
            return PickPrivate(ppPickedView, pos);
        }

        Element* Pick(Element* topView, glm::vec2 pos)
        {
           Element* pPickedView = nullptr;
           pPickedView = PickPrivate(topView, pos);
           if (pPickedView) pPickedView->OnClick(pos);
           return pPickedView;
        }

    private:
        Element* mPickedView = nullptr;
    };
}

#endif // __CARBON_PICKER__