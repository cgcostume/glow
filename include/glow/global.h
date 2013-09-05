#pragma once

#include <string>
#include <vector>

#include <GL/glew.h>

#include <glow/glow.h>
#include <glow/Version.h>


namespace glow {

class GLOW_API query
{
public:
	static std::string getString(GLenum pname);
	static GLint getInteger(GLenum pname);
	static GLfloat getFloat(GLenum pname);
	static GLdouble getDouble(GLenum pname);
	static GLboolean getBoolean(GLenum pname);

	static GLint getInteger(GLenum pname, unsigned index);
	static std::vector<GLint> getIntegers(GLenum pname, unsigned size);

	static std::string vendor();
	static std::string renderer();

	static Version version();
	static std::string versionString();

	static GLint majorVersion();
	static GLint minorVersion();
	static bool isCoreProfile();
};

class GLOW_API extensions
{
public:
	static bool isSupported(const char* extension);
	static bool isSupported(const std::string& extension);
};

class GLOW_API memory
{
public:
	/** all sizes in kb */
	static GLint total();
	static GLint dedicated();
	static GLint available();
	static GLint evicted();
	static GLint evictionCount();

protected:
	static GLint memoryInfo(GLenum pname);
};

class GLOW_API glew
{
public:
	static std::string getString(GLenum pname);
	static std::string version();
};


} // namespace glow
