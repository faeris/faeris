#ifndef _CANVAS_CANVAS2D_H_
#define _CANVAS_CANVAS2D_H_


class Canvas2D
{
	public:
		void save();
		void restore();

		/*rects*/
		void clearRect(double x,double y,double w,double h);
		void fillRect(double x,double y,double w,double h);
		void strokeRect(double x,double y,double w,double h);

		/*path*/
		void beginPath();
		void fill();
		void stroke();
		void clip();
		boolean isPointInPath(double x,double y);

		/* path api method*/
		void closePath();
		void moveTo(double x,double y);
		void lineTo(double x,double y);
		void quadraticCurveTo(double cpx,double cpy,double x,double y);
		void bezierCurveTo(double cp1x,double cp1y,double cp2x,double cp2y,double x,double y);
		void arcTo(double x1,double y1,double x2,double y2,double radius);
		void rect(double x,double y,double w,double h);
		double arc(double x,double y,double radius,double startAngle,double endAngle,bool anticlockwise=true);

		/*text*/
		enum TextAlign
		{
			TA_START, /*default*/
			TA_END,
			TA_LEFT,
			TA_RIGHT,
			TA_CENTER,
		};
		enum TextBaseline
		{
			TB_TOP,
			TB_HANGING,
			TB_MIDDLE,
			TB_ALPHABETIC,  /*default*/
			TB_IDEOGRAPHIC,
			TB_BOTTOM,
		};

		void fillText(const char* text,double x,double y,double maxWidth=0.0);
		void stokeText(const char* text,double x,double y,double maxWidth=0.0);
		void setFont(Font* font);
		Font* getFont()const;
		void setTextAlign(TextAlign type);
		TextAlign getTextAlign();
		void setTextBaseline(TextBaseline type);
		TextBaseline getTextBaseline();




		/*images*/
		void drawImage(Image* image,double dx,double dy);
		void drawImage(Image* image,double dx,double dy,double dw,double dh);
		void drawImage(Image* image,double sx,double sy,double sw,double sh,double dx,double dy,double dw,double dh);


		/*pixel manipulation*/


		/*transformation*/
		void scale(double x,double y);
		void rotate(double angle);
		void translate(double x,double y);
		void transform(double a,double b,double c,double d,double e,double f);
		void setTransform(double a,double b,double c,double d,double e,double f);


		/*line caps/joins*/
		enum LineCap
		{
			LC_BUTT,  /*default*/
			LC_ROUND,
			LC_SQUARE,
		};
		enum LineJoin
		{
			LJ_ROUND,
			LJ_BEVEL,
			LJ_MITER, /*default*/
		};

		void setLineWidth(double lineWidth);
		double getLineWidth();
		void setMiterLimit(double miter);
		double getMiterLimit();
		void setLineGap(LineCap type);
		LineCap getLineCap();
		void setLineJoin(LineJoin type);
		LineJoin getLineJoin();


		/* alpha */
		enum CompositeOperation
		{
			CO_SOURCE_ATOP,
			CO_SOURCE_IN,
			CO_SOURCE_OUT,
			CO_SOURCE_OVER, /*default*/
			CO_DESTINATION_ATOP,
			CO_DESTINATION_IN,
			CO_DESTINATION_OUT,
			CO_DESTINATION_OVER,
			CO_LIGHTER,
			CO_COPY,
			CO_XOR,
		};

};

#endif

