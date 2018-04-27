// Negatives

uniform float dX;
uniform float dY;
uniform float time;
uniform sampler2D img;

vec4 sample(float dx,float dy)
{
   return (sin(time + gl_TexCoord[0].s))*texture2D(img,gl_TexCoord[0].st+vec2(dx,dy));
}

void main()
{
   gl_FragColor = 1.0 - (-sample(-dX,+dY) -     sample(0.0,+dY) - sample(+dX,+dY)
                  -sample(-dX,0.0) + 9.0*sample(0.0,0.0) - sample(+dX,0.0)
                  -sample(-dX,-dY) -     sample(0.0,-dY) - sample(+dX,-dY));
}
