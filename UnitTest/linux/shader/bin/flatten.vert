void main(void)
{
	vec4 v=vec4(gl_Vertex);
	v.z=0.0;
	gl_Position=gl_ModelViewProjectionMatrix*v;
}

