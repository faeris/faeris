#ifndef FAERY_RENDER_IRENDER_H_
#define FAERY_RENDER_IRENDER_H_
class Mesh;
class Light;
class IRender 
{
	public:
		virtual ~IRender()=0;
		virtual RenderMesh(Mesh* m)=0;
		virtual SetMeterial(Meterial* m)=0;
		virtual SetLight(Light* l,int id)=0;
		virtual EnableLight(int id)=0;
};
#endif 

