#ifndef __E3_CONTAINER__
#define __E3_CONTAINER__

// e3
#include <e3/Element.h>
#include <e3/Enum.h>
// std
#include <vector>

namespace e3
{
    class Container : public Element
    {
    public:
        Container();
        ~Container();

    public:
        // virtual void Render() override;
        // virtual void RenderShadow() override;
		// virtual void RenderToTexture() override;
        // virtual void Update() override;

    public:
        // virtual bool OnClick(const glm::vec2 &pos) override;
        // virtual bool OnMouseDown(const glm::vec2 &pos) override;
		// virtual bool OnMouseLongDown(const glm::vec2 &pos) override;
		// virtual bool OnMouseLongClick(const glm::vec2 &pos) override;
        // virtual bool OnPointerUp(const glm::vec2 &pos) override;
        // virtual void OnMove(const glm::vec2 &distance, const glm::vec2 &pos) override;
		//virtual void OnMouseEnter(const glm::vec2 &pos) override;
		/*virtual void OnMouseHover(const glm::vec2 &pos) override;
		virtual void OnMouseLeave(const glm::vec2 &pos) override;*/

    public:
       // virtual void AddElement(Element* pElement);
        //void InsertElement(int index, Element *pElement);
        //Element* FindElementById(int id);
        // void RemoveElementById(int id);
        //Element* RemoveElementByIndex(int index);
        //void PopElement();
        //void RemoveAllElements();

      /*  void Clear ()
        {
            YGNodeRemoveAllChildren(mNode);
            for (int i = 0; i < mChildren.size(); ++i)
            {
                delete mChildren[i];
            }
            mChildren.clear();
        }*/
    public:
        /*void SetOrientation(EOrientation orientation);
        EOrientation GetOrientation();*/

        /*void SetReversed(bool reversed);
        bool GetReversed();*/

        /*void SetAlignItemsVer(e3::EAlignment alignment);
        void SetAlignItemsHor(e3::EAlignment alignment);*/

        /*e3::EAlignment GetAlignItemsVer() { return mAlignItemsVer; }
        e3::EAlignment GetAlignItemsHor() { return mAlignItemsHor; }*/

        /*std::vector<e3::Element*>& GetChildren();
        int GetNumChildren();*/

        // bool Contains(Element* pElement);

    public:
        // virtual void Translate(const glm::vec3 &direction) override;

		/*virtual void Scale(const glm::vec3 &direction) override;
		virtual void SetScale(const glm::vec3 &direction) override;*/
        /*virtual void Scale(const glm::vec3 &direction, bool recursive);
        virtual void SetScale(const glm::vec3 &direction, bool recursive);*/

        //virtual void SetTranslation(const glm::vec3 &direction) override;

        // virtual void SetTranslation(float value, EOrientation direction) override;

        // virtual void SetOpacity(float opacity) override;

	protected:
		// virtual void SetScrollTranslation(float value, EOrientation direction) override;

    private:
        /*virtual float GetMaxZ() override;
        float GetMaxZ(float maxZ, Element* pElement);*/
        //int FindElementIndexById(int id);

    /*private:
        EOrientation mOrientation;
        bool mReversed = false;
        e3::EAlignment mAlignItemsVer;
        e3::EAlignment mAlignItemsHor;
        std::vector<e3::Element*> mChildren;*/
    };
}

#endif // __E3_CONTAINER_IMPL__