#ifndef _CANVAS_GRADINET_H_
#define _CANVAS_GRADINET_H_
class Gradient
{
	public:
		struct ColorStop
		{
			float stop;
			float red;
			float green;
			float blue;
			float alpha;
			ColorStop():stop(0),red(0),green(0),blue(0),alpha(0){}
			ColorStop(float s,float r,float g,float b,float a)
				:stop(s),red(r),green(g),blue(b),alpha(a){}
		};
	public:
		addColorStop(float value,const Color& color);
		addColorStop(const Gradient::ColorStop& stop);
		virtual void getColor(float value,float* r,float* g,float* b,float* a)const;
		void hasAlpha()const;


	private:
};
#endif 

