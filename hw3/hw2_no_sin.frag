//Michael Crozier HW2 procedural shader
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
   float n = noise(position);
   vec3 color = vec3(n+0.5);
   //if the color of a pixel is below the changing sin(time) threshold, it's color is set
   //to a background color. The background color changes between R, G, and B every sin, because
   //why not?
   float useless = 0.0;
   for (int i = 0; i < 1000000; i++) {
      useless = useless + 1.0;
   }
   if (n <= sin(n))
   {
      float sky = mod(time,18.0);
      
      if (sky < 6.0)       color = colorR;
      else if (sky < 12.0) color = colorG;
      else if (sky < 18.0) color = colorB;
   }
   color *= LightIntensity;
   gl_FragColor = vec4(color,1.0);
}
