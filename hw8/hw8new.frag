//  Wood fragment but with textures

uniform sampler3D Noise3D;
uniform sampler2D tex1;

const float Scale = 0.2;
const float Mag = 1.2;

const vec4  darkRed         = vec4(0.55,0.0,0.0,1.0);
const vec4  red             = vec4(1.0,0.0,0.0,1.0);
const vec4  yellow          = vec4(1.0,1.0,0.0,1.0);
const vec4  green           = vec4(0.0,1.0,0.0,1.0);
const vec4  lightBlue       = vec4(0.53,0.81,0.98,1.0);
const vec4  darkBlue        = vec4(0.0,0.0,0.55,1.0);
const vec4  purple          = vec4(0.29,0.0,0.51,1.0);
const float RingFreq        = 1.0;
const float oneSeventh      = 0.142857142857;

void main(void)
{
   vec4 nv = Mag*texture3D(Noise3D,Scale*gl_TexCoord[0].xyz);

   vec4 map   = texture2D(tex1,(gl_TexCoord[0].xy/2.0)-vec2(0.5,0.5));

   vec3 loc = gl_TexCoord[0].xyz + nv.xyz;

   float dist = RingFreq*sqrt(loc.x*loc.x + loc.z*loc.z);

   float r = 2.0 * fract(dist + nv[0] + nv[1] + nv[2]);
   if (r > 1.0) r = 2.0 - r;

   vec4 color = (0.0,0.0,0.0,0.0);

   if      (r <  oneSeventh && r > 0.0)                color = mix(map, purple , 0.6);
   else if (r >= oneSeventh && r < oneSeventh*2.0)     color = mix(map, darkBlue, 0.6);
   else if (r >= oneSeventh*2.0 && r < oneSeventh*3.0) color = mix(map, lightBlue, 0.6);
   else if (r >= oneSeventh*3.0 && r < oneSeventh*4.0) color = mix(map, green, 0.6);
   else if (r >= oneSeventh*4.0 && r < oneSeventh*5.0) color = mix(map, yellow, 0.6);
   else if (r >= oneSeventh*5.0 && r < oneSeventh*6.0) color = mix(map, red, 0.6);
   else if (r>= oneSeventh*6.0 && r <= 1.0)            color = mix(map, darkRed, 0.6);
   else                                                color = map;

   gl_FragColor = length(gl_Color.xyz) * color;
}
