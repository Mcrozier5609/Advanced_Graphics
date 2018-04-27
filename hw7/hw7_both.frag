// edge detect and negative

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
   if (sin(time + gl_TexCoord[0].s) > 0)
   {
      float one = 1.0/13.0;
      float two = 2.0/13.0;
      gl_FragColor = one*sample(-dX,+dY) + two*sample(0.0,+dY) + one*sample(+dX,+dY)
                   + two*sample(-dX,0.0) + one*sample(0.0,0.0) + two*sample(+dX,0.0)
                   + one*sample(-dX,-dY) + two*sample(0.0,-dY) + one*sample(+dX,-dY);
   }
   else
   {
      gl_FragColor = -sample(-dX,+dY) -     sample(0.0,+dY) - sample(+dX,+dY)
                     -sample(-dX,0.0) + 9.0*sample(0.0,0.0) - sample(+dX,0.0)
                     -sample(-dX,-dY) -     sample(0.0,-dY) - sample(+dX,-dY);
   }
}
