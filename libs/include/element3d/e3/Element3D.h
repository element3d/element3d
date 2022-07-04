#ifndef __E3_ELEMENT3D__
#define __E3_ELEMENT3D__

#include "Element.h"

class GLModel;

namespace e3
{
    class Element3D : public Element
    {
    public:
        Element3D();
        ~Element3D();

	public:
		void Render() override;

	public:
		void SetModel(const std::string modelPath);
	//	void SetModel(int modelAssetId);

	public:
		virtual void OnMouseMove(MouseEvent* pEvent) override;

    private:
		std::string mModelPath = "";
		glm::mat4 mRotate = glm::mat4(1);
		glm::vec2 mRotattion = glm::vec2(0);
		GLModel* mModel = nullptr;
		GLuint mVAO = 0;
		Carbon::ShaderProgram* mProgram = nullptr;
    };
}

#endif // __E3_ELEMENT3D__