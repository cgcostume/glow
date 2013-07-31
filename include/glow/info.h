#pragma once

#include <GL/glew.h>

#include <glow/glow.h>

#include <string>
#include <vector>


namespace glow {

class GLOW_API info
{
public:
	class Version
	{
	public:
		Version(GLint majorVersion, GLint minorversion);

		GLint majorVersion;
		GLint minorVersion;

		bool operator<(const Version& version) const;
		bool operator>(const Version& version) const;
		bool operator==(const Version& version) const;
		bool operator!=(const Version& version) const;
		bool operator>=(const Version& version) const;
		bool operator<=(const Version& version) const;

		std::string toString() const;
	};
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
