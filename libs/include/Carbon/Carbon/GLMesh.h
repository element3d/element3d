#ifndef __PUZL_GLMESH_H__
#define __PUZL_GLMESH_H__

#include "Carbon.h"
#include <Carbon/Buffer.h>
#include <Carbon/Texture.h>
// glm
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
// c++
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

struct GLVertex
{
    glm::vec4 position;
    glm::vec3 normal;
    glm::vec2 uv;
};

namespace Carbon
{
	class Material 
	{
	public:
		Material() {}

	public:
		Texture* mDiffuse;
	};
}

class GLMesh
{
public:
    GLMesh
    (
        const std::string& mName,
        const std::vector<GLVertex>& vertices,
        const std::vector<GLuint>& indices
    );
    ~GLMesh();

public:
    void Draw();
    std::string name() { return mName; }
	void SetMaterial(Carbon::Material* pMaterial);
	Carbon::Material* GetMaterial();

private:
    std::string mName;

	bool mLoaded = false;
	std::vector<GLVertex> mVertices;
	std::vector<GLuint> mIndices;

    Carbon::Buffer* mVertexBuffer = NULL;
    Carbon::Buffer* mIndexBuffer = NULL;
    GLuint mNumIndices;
	Carbon::Material* mMaterial = NULL;
};

#endif //__PUZL_GLMESH_H__
