#ifndef TEXTURE_H
#define TEXTURE_H
#include <GL/glew.h>

#include <string>
#include <vector>

struct Texture 
{
	Texture(const std::string& _path);
	~Texture();

	GLuint getid();

private:
	std::vector<unsigned char> m_data;
	GLuint m_id;
	int m_width;
	int m_height;
	bool m_dirty;
};
#endif