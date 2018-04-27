//vertex shader

uniform float time;
varying vec4 foo;

void main()
{
   //  Use color unchanged
   foo = gl_Vertex + vec4((sin(2.0*time)+1.0)/2.0,(cos(2.0*time)+1.0)/2.0,(sin(time)+1.0)/2.0,0.0);
   //  Set vertex coordinates
   vec4 pos = gl_Vertex + vec4(sin(2.0*time),cos(2.0*time),sin(time),0.0);
   gl_Position = gl_ModelViewProjectionMatrix * pos;
}
