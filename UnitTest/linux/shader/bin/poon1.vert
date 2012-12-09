uniform vec3 lightDir;
varying float intensity;
void main()
{
	vec3 ld;
	intensity=dot(lightDir,gl_Normal);
	gl_Position=ftransform();
}
