//Michael Crozier HW3 procedural shader (no functions)
//background color stuff
const vec3 colorR = vec3(1.0,0.1,0.1);
const vec3 colorG = vec3(0.1,1.0,0.1);
const vec3 colorB = vec3(0.1,0.1,1.0);

//light stuff from vertex shader
varying float LightIntensity;
varying vec2 ModelPos;
uniform float time;

//"random" vec2 where you dot product the original vector with some vectors made 
//from smashing my hands on the number keys.
vec2 rand_vec2(vec2 st)
{
    st = vec2( dot(st,vec2(234.2,321.7)), dot(st,vec2(552.3,179.3)));
    return -1.0 + 2.0*fract(sin(st)*7902.1274308);
}

//noise function, interpolating color between corners of "blocks" with psuedo random color values 
float noise(vec2 pos)
{
    vec2 i = floor(pos);
    vec2 j = fract(pos);

    vec2 u = smoothstep(0.0,1.0,j);

    return mix( mix( dot( rand_vec2(i + vec2(0.0,0.0) ), j - vec2(0.0,0.0) ),
                     dot( rand_vec2(i + vec2(1.0,0.0) ), j - vec2(1.0,0.0) ), u.x),
                mix( dot( rand_vec2(i + vec2(0.0,1.0) ), j - vec2(0.0,1.0) ),
                     dot( rand_vec2(i + vec2(1.0,1.0) ), j - vec2(1.0,1.0) ), u.x), u.y);
}

void main()
{
   vec2 position = ModelPos*7.0;
   vec2 i = floor(position);
   vec2 j = fract(position);

   vec2 u = j*j*(3.0-2.0*j);

   vec2 v1 = i + vec2(0.0,0.0);
   v1 = vec2( dot(v1,vec2(234.2,321.7)), dot(v1,vec2(552.3,179.3)));
   v1 = -1.0 + 2.0*fract(sin(v1)*7902.1274308);

   vec2 v2 = i + vec2(1.0,0.0);
   v2 = vec2( dot(v2,vec2(234.2,321.7)), dot(v2,vec2(552.3,179.3)));
   v2 = -1.0 + 2.0*fract(sin(v2)*7902.1274308);

   vec2 v3 = i + vec2(0.0,1.0);
   v3 = vec2( dot(v3,vec2(234.2,321.7)), dot(v3,vec2(552.3,179.3)));
   v3 = -1.0 + 2.0*fract(sin(v3)*7902.1274308);

   vec2 v4 = i + vec2(1.0,1.0);
   v4 = vec2( dot(v4,vec2(234.2,321.7)), dot(v4,vec2(552.3,179.3)));
   v4 = -1.0 + 2.0*fract(sin(v4)*7902.1274308);

   float n = mix( mix( dot( rand_vec2(v1), j - vec2(0.0,0.0) ),
                     dot( rand_vec2(v2), j - vec2(1.0,0.0) ), u.x),
                mix( dot( rand_vec2(v3), j - vec2(0.0,1.0) ),
                     dot( rand_vec2(v4), j - vec2(1.0,1.0) ), u.x), u.y);
   vec3 color = vec3(n+0.5);
   //if the color of a pixel is below the changing sin(time) threshold, it's color is set
   //to a background color. The background color changes between R, G, and B every sin, because
   //why not?
   if (n <= sin(time))
   {
      float sky = mod(time,18.0);
      
      if (sky < 6.0)       color = colorR;
      else if (sky < 12.0) color = colorG;
      else if (sky < 18.0) color = colorB;
   }
   color *= LightIntensity;
   gl_FragColor = vec4(color,1.0);
}
