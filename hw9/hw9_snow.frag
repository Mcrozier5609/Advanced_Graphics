#version 120

// Large point texture

uniform sampler2D img;

void main()
{
   //  Sample texture
   vec4 color = texture2D(img,gl_PointCoord.st);
   gl_FragColor = color;
}
