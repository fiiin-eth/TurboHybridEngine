#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <SDL2/SDL.h>
#include <glm/ext.hpp>

#include "Mesh.h"
#include "Model.h"
#include "Texture.h"

#include <string>
#include <vector>
namespace Render {
	class Shader {

	public:
		Shader(bool GUI);
		~Shader();

		void setMat4(std::string variable, glm::mat4 value);
		void draw(Mesh& _mesh, Texture& _tex);
		void draw(Mesh& _mesh, GLuint _texId);
		void draw(Model& _model, Texture& _tex);
		void draw(Model& _model, GLuint _texId);
		void draw(Model* _model, Texture* _tex);
		void draw(Mesh* _mesh, Texture* _tex);

		GLuint programId;
		GLint modelLoc;
		GLint viewLoc;
		GLint projectionLoc;

	private:

		const GLchar* vertexShaderSrc =
			"attribute vec3 a_Position;														" \
			"attribute vec2 a_TexCoord;														" \
			"attribute vec3 a_Normal;														" \
			"																				" \
			"uniform mat4 u_Projection;														" \
			"uniform mat4 u_View;															" \
			"uniform mat4 u_Model;															" \
			"varying vec3 v_Normal;															" \
			"varying vec3 v_FragPos;														" \
			"varying vec2 v_TexCoord;														" \
			"																				" \
			"																				" \
			"void main()																	" \
			"{																				" \
			" gl_Position = u_Projection * u_View * u_Model * vec4(a_Position, 1.0);		" \
			" v_TexCoord = a_TexCoord;														" \
			" v_Normal = mat3(u_Model) * a_Normal;											" \
			" v_FragPos = vec3(u_Model * vec4(a_Position, 1.0));							" \
			"}																				" \
			"																				";

		const GLchar* fragmentShaderSrc =
			"varying vec2 v_TexCoord;									" \
			"uniform sampler2D u_Texture;								" \
			"varying vec3 v_Normal;										" \
			"varying vec3 v_FragPos;									" \
			"uniform vec3 u_ViewPos;									" \
			"void main()												" \
			"{															" \
			" vec4 tex = texture2D(u_Texture, v_TexCoord);				" \
			" gl_FragColor = tex;										" \
			"															" \
			" vec3 lightPos = vec3(10, 10, 10);							" \
			" vec3 diffuseColor = vec3(1, 1, 1);						" \
			"															" \
			" vec3 N = normalize(v_Normal);								" \
			" vec3 lightDir = normalize(lightPos - v_FragPos);			" \
			" float diff = max(dot(N, lightDir), 0.0);					" \
			" vec3 diffuse = diffuseColor * diff;						" \
			"															" \
			" vec3 specularColor = vec3(1, 1, 1);						" \
			"															" \
			" vec3 viewDir = normalize(u_ViewPos - v_FragPos);			" \
			" vec3 reflectDir = reflect(-lightDir, N);					" \
			" float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32); " \
			" vec3 specular = spec * specularColor;						" \
			"															" \
			" vec3 lighting = diffuse + specular;						" \
			" gl_FragColor = vec4(lighting, 1) * tex;					" \
			"}															" \
			"															";
	};

}
#endif