#version 400 core

//  Transformation matrices
uniform mat4 ModelViewMatrix;
uniform mat4 ProjectionMatrix;

//  Vertex attributes (input)
layout(location = 0) in vec4 Vertex;
layout(location = 1) in vec3 Color;
layout(location = 2) in vec2 TexCoord;
layout(location = 3) in vec3 inNormal;

//  Output to next shader
out vec3 FrontColor;
out vec4 FragVertex;
out vec2 TextureCoord;
out vec3 Normal;

void main()
{	
   //  Pass stuff to fragment shader
   FrontColor = Color;
   FragVertex = Vertex;
   TextureCoord = TexCoord;
   Normal = inNormal;
   
   //  Set transformed vertex location
   gl_Position =  ProjectionMatrix * ModelViewMatrix * Vertex;
}
