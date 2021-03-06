#version 430

layout (location = 0) in vec2 inUV;
layout (location = 0) out vec3 outColor;
 
uniform layout (binding = 0) sampler2D scene;
 
void main()
{ 

	vec3 normal = texture(scene, inUV).rgb * 1;      
   
	vec3 visionColor = vec3(0,1,0);
 
	outColor = normal * visionColor;
}
