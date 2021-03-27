#ifndef __PUZL_GLMODEL_H__
#define __PUZL_GLMODEL_H__

#include <Carbon.h>
#include "GLMesh.h"
// Assimp
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
// STL
#include <vector>
#include <thread>

struct MeshCpu
{
	std::string Name;
	std::vector<GLVertex> Vertices;
	std::vector<GLuint> Indices;
};

class GLModel
{
public:
    GLModel();
    ~GLModel();

public:
    bool load(const std::string& filename, bool useAssimp);
	bool LoadAsync(const std::string& filename);
    void draw();

public:
    std::vector<GLMesh*> meshes() { return mMeshes; }
	glm::vec3 GetCenter();
	glm::vec3 GetBoundingBoxMin();
	glm::vec3 GetBoundingBoxMax();

private:
    bool loadAssimp(const std::string& filename);
    void processNode(aiNode *node, bool async);
    GLMesh* processMesh(aiMesh *mesh, int meshId, bool async);
    std::vector<Texture*> loadMaterialTextures(aiMaterial *mat, aiTextureType type, const std::string& typeName);
	void LoadThreadCallback();

private:
	glm::vec3 mMin;
	glm::vec3 mMax;
	std::string mFilename = "";
    Assimp::Importer* mImporter = NULL;
    const aiScene*    mScene = NULL;
    std::vector<GLMesh*> mMeshes;
	std::vector<MeshCpu*> mMeshesCpu;
    std::vector<Texture*> textures_loaded;
	std::thread mLoadThread;

	bool mLoaded = false;
	bool mInitialized = false;
};

#endif // __PUZL_GLMODEL_H__
