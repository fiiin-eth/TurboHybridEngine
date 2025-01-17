#include "ShaderProgram.h"
#include <iostream>
namespace Render {
	Shader::Shader(bool GUI) {
		if (GUI) {
			/*************** Vertex Shader ****************/

			// Create a new vertex shader, attach source code, compile it and
			// check for errors.
			GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertexShaderId, 1, &guiVertexShaderSrc, NULL);
			glCompileShader(vertexShaderId);
			GLint success = 0;
			glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);


			if (!success)
			{
				std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

				GLchar infoLog[512];
				glGetShaderInfoLog(vertexShaderId, 512, NULL, infoLog);
				std::cout << "Vertex Shader Error: " << infoLog << std::endl;
				throw std::runtime_error("Vertex shader compilation failed.");
				//std::cout << "Vertex Shader Error" << std::endl;
				//throw std::exception();
			}


			/*************** Fragment Shader ****************/

			// Create a new fragment shader, attach source code, compile it and
			// check for errors.
			GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragmentShaderId, 1, &guiFragmentShaderSrc, NULL);
			glCompileShader(fragmentShaderId);
			glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);

			if (!success)
			{
				std::cout << "Fragment Shader Error" << std::endl;
				throw std::exception();
			}

			/************ Program ***************/

			// Create new shader program and attach our shader objects
			programId = glCreateProgram();
			glAttachShader(programId, vertexShaderId);
			glAttachShader(programId, fragmentShaderId);

			// Ensure the VAO "position" attribute stream gets set as the first position
			// during the link.
			glBindAttribLocation(programId, 0, "a_Position");
			glBindAttribLocation(programId, 1, "a_TexCoord");
			glBindAttribLocation(programId, 2, "a_Normal");

			// Perform the link and check for failure
			glLinkProgram(programId);
			glGetProgramiv(programId, GL_LINK_STATUS, &success);

			// Find uniform locations
			modelLoc = glGetUniformLocation(programId, "u_Model");
			//viewLoc = glGetUniformLocation(programId, "u_View");
			projectionLoc = glGetUniformLocation(programId, "u_Projection");

			if (!success)
			{
				throw std::exception();
			}

			if (modelLoc == -1 || projectionLoc == -1) {
				throw std::runtime_error("One or more uniform locations not found");
			}


			// Detach and destroy the shader objects. These are no longer needed
			// because we now have a complete shader program.
			glDetachShader(programId, vertexShaderId);
			glDeleteShader(vertexShaderId);
			glDetachShader(programId, fragmentShaderId);
			glDeleteShader(fragmentShaderId);
		}
		else{
		
			/*************** Vertex Shader ****************/

			// Create a new vertex shader, attach source code, compile it and
			// check for errors.
			GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertexShaderId, 1, &vertexShaderSrc, NULL);
			glCompileShader(vertexShaderId);
			GLint success = 0;
			glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);


			if (!success)
			{
				throw std::exception();
			}


			/*************** Fragment Shader ****************/

			// Create a new fragment shader, attach source code, compile it and
			// check for errors.
			GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragmentShaderId, 1, &fragmentShaderSrc, NULL);
			glCompileShader(fragmentShaderId);
			glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);

			if (!success)
			{
				throw std::exception();
			}

			/************ Program ***************/

			// Create new shader program and attach our shader objects
			programId = glCreateProgram();
			glAttachShader(programId, vertexShaderId);
			glAttachShader(programId, fragmentShaderId);

			// Ensure the VAO "position" attribute stream gets set as the first position
			// during the link.
			glBindAttribLocation(programId, 0, "a_Position");
			glBindAttribLocation(programId, 1, "a_TexCoord");
			glBindAttribLocation(programId, 2, "a_Normal");

			// Perform the link and check for failure
			glLinkProgram(programId);
			glGetProgramiv(programId, GL_LINK_STATUS, &success);

			// Find uniform locations
			modelLoc = glGetUniformLocation(programId, "u_Model");
			viewLoc = glGetUniformLocation(programId, "u_View");
			projectionLoc = glGetUniformLocation(programId, "u_Projection");

			if (!success)
			{
				throw std::exception();
			}

			if (modelLoc == -1 || viewLoc == -1 || projectionLoc == -1) {
				throw std::runtime_error("One or more uniform locations not found");
			}

			// Detach and destroy the shader objects. These are no longer needed
			// because we now have a complete shader program.
			glDetachShader(programId, vertexShaderId);
			glDeleteShader(vertexShaderId);
			glDetachShader(programId, fragmentShaderId);
			glDeleteShader(fragmentShaderId);
		
		}
	}

	Shader::~Shader() {

	}

	void Shader::setMat4(std::string variable, glm::mat4 value) {
		glUseProgram(programId);
		glUniformMatrix4fv(glGetUniformLocation(programId, variable.c_str()), 1, GL_FALSE, glm::value_ptr(value));
		glUseProgram(0);
	}

	void Shader::draw(Mesh& _mesh, Texture& _tex) {
		glUseProgram(programId);
		glBindVertexArray(_mesh.vao_id());
		glBindTexture(GL_TEXTURE_2D, _tex.getid());

		glDrawArrays(GL_TRIANGLES, 0, _mesh.vertex_count());

		glBindVertexArray(0);
		glBindTexture(GL_TEXTURE_2D, 0);
		glUseProgram(0);
	}

	void Shader::draw(Mesh& _mesh, GLuint _texId) {
		glUseProgram(programId);
		glBindVertexArray(_mesh.vao_id());
		glBindTexture(GL_TEXTURE_2D, _texId);
		glDrawArrays(GL_TRIANGLES, 0, _mesh.vertex_count());
		glUseProgram(0);
	}

	void Shader::draw(Model& _model, Texture& _tex) {
		glUseProgram(programId);
		glBindVertexArray(_model.vao_id());
		glBindTexture(GL_TEXTURE_2D, _tex.getid());
		glDrawArrays(GL_TRIANGLES, 0, _model.vertex_count());
		glUseProgram(0);
	}

	void Shader::draw(Model& _model, GLuint _texId) {
		glUseProgram(programId);
		glBindVertexArray(_model.vao_id());
		glBindTexture(GL_TEXTURE_2D, _texId);
		glDrawArrays(GL_TRIANGLES, 0, _model.vertex_count());
		glUseProgram(0);
	}
	void Shader::draw(Model* _model, Texture* _tex)
	{
		glUseProgram(programId);
		glBindVertexArray(_model->vao_id());
		glBindTexture(GL_TEXTURE_2D, _tex->getid());
		glDrawArrays(GL_TRIANGLES, 0, _model->vertex_count());
		glBindVertexArray(0);
		glBindTexture(GL_TEXTURE_2D, 0);
		glUseProgram(0);
	}
	void Shader::draw(Mesh* _mesh, Texture* _tex)
	{
		glUseProgram(programId);
		glBindVertexArray(_mesh->vao_id());
		glBindTexture(GL_TEXTURE_2D, _tex->getid());
		glDrawArrays(GL_TRIANGLES, 0, _mesh->vertex_count());
		glBindVertexArray(0);
		glBindTexture(GL_TEXTURE_2D, 0);
		glUseProgram(0);
	}
}