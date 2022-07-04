#ifndef __CARBON_SHADER_PROGRAM__
#define __CARBON_SHADER_PROGRAM__

#include "OpenGLES.h"
#include <glm/glm.hpp>
#include <string>

namespace Carbon
{
    enum class EShaderVersion
    {
        GLSL_300_ES,
        GLSL_330
    };

    struct ShaderProgramCreateInfo
    {
        EShaderVersion Version;
        std::string VsPath;
        std::string FsPath;
    };

	struct ShaderProgramCreateInfo2
	{
		EShaderVersion Version;
		std::string VsCode;
		std::string FsCode;
	};

    class ShaderProgram
    {
    public:
        ShaderProgram(const ShaderProgramCreateInfo* pInfo);
		ShaderProgram(const ShaderProgramCreateInfo2* pInfo);

        ShaderProgram();

        ~ShaderProgram();

    public:
        void bind();

        void unbind();

        GLuint GetHandle() { return mHandle; }

        void compile(const char *vsCode, const char *fsCode);

        void setMat4(const std::string &name, const glm::mat4 &mat) const;

        void setVec2(const std::string &name, const glm::vec2 &vec) const;
		void setVec2i(const std::string &name, const glm::ivec2 &vec) const;

        void setVec3(const std::string &name, const glm::vec3 &vec) const;

        void setVec4(const std::string &name, const glm::vec4 &vec) const;

        void setBool(const std::string &name, bool value) const;

        void setFloat(const std::string &name, float value) const;

        void setInt(const std::string &name, int value) const;
		void setIntv(const std::string &name, int numValues, int* values) const;

        GLuint getUniformLocation(const char *name);
		GLuint getVertexAttribLocation(const char *name);

    private:
        void init(const std::string& vsCode, const std::string& fsCode);
        void checkCompileErrors(GLuint shader, const std::string &type);
        std::string ShaderVersionEnumToString(EShaderVersion version);

    private:
        GLuint mHandle = 0;
    };
}

#endif // __CARBON_SHADER_PROGRAM__