#version 400 core

uniform mat4 ModelViewMatrix;
uniform sampler2D tex;
uniform vec3 lightPosition;
uniform mat4 model;

//  Input from previous shader
in vec3 FrontColor;
in vec2 TextureCoord;
in vec3 Normal;
in vec4 FragVertex;

//  Fragment color
layout (location=0) out vec4 Fragcolor;

void main()
{
   mat3 normalMat = transpose(inverse(mat3(model)));
   vec3 finalNormal = normalize(normalMat * Normal);
   vec3 position = vec3(model * FragVertex);
   vec3 surfaceVector = normalize(lightPosition - position);
   vec3 surfaceToCamera = normalize(-position);
   //Color from Texture
   vec4 texColor = texture(tex, TextureCoord);

   //diffuse lighting
   float brightness = dot(finalNormal, surfaceVector);
   brightness = clamp(brightness, 0, 1);
   vec3 diffuse = brightness * texColor.rgb * FrontColor;

   //ambient lighting
   vec3 ambient = vec3(0.5,0.5,0.5) * texColor.rgb * FrontColor;

   //specular lighting
   float spec = 0.0;
   if (brightness > 0.0)
      spec = pow(max(0.0, dot(surfaceToCamera, reflect(-surfaceVector, finalNormal))), 70.0);
   vec3 specular = vec3(spec,spec,spec);

   Fragcolor = vec4(ambient + diffuse + specular, 1.0);
}
