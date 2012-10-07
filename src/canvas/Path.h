#ifndef _GRAPHICS_PATH_H_
#define _GRAPHICS_PATH_H_

#if PLATFORM(SKIA)
class SkPath;
typedef SkPath PlatformPath
#elif PLATFORM(CAIRO)
struct CairoPath;
typedef CairoPath PlatformPath 
#else 
	#error "UNSUPPORT_PLATFORM_FOR_PATH"
#endif 

class Path
{
	public:
		Path();
		~Path();
		Path(const Path&);
		Path& operator=(const Path&);

	public:
		FloatRect boundingRect()const;

		void clear();
		bool isEmpty();
		bool hasCurrentPoint()const;
		FloatPoint CurrentPoint()const;

		void moveTo(const FloatPoint& );
		void addLineTo(const FloatPoint& );
		void addQuadCurveTo(const FloatPoint& cp,const FloatPoint& ep);
		void addBezierCurveTo(const FloatPoint& cp1,const FloatPoint& cp2,const FloatPoint& ep);
		void addArcTo(const FloatPoint& bp,const FloatPoint& ep,float radius);
		void closeSubpath();

		void addArc(const FloatPoint&,float radius,float startAngle,float endAngle,bool anticlockwise);
		void addRect(const FloatRect&);
		void addEllipse(const FloatRect&);
		void addRoundedRect(const FloatRect&,const FloatSize& roundRadii);
		void addRoundedRect(const FloatRect&,const FloatSize& topLeftRadius,const FloatSize& topRightRadius,
										     const FloatSize& bottomLeftRadius,const FloatSize& bottomRightRadius);
		void translate(const FloatSize&);
		void transform(const Matrix3&);

	private:
		PlatformPath* m_path;

}
#endif  /*_GRAPHICS_PATH_H_*/


