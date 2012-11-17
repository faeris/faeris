/************************************************************
 * File: quaternion.h
 * Description: Thanks to three.js,I can impliement quickly
 * Author: NosicLin(nosiclin@foxmail.com)
 * Date:2012-9-28
 * Copyright:Faery Studio
 ************************************************************/

#ifndef _FAERY_CORE_QUATERNION_H_
#define _FAERY_CORE_QUATERNION_H_
class Matrix4;
class Quaternion 
{
	public:
		union
		{
			struct
			{
				float x,y,z,w;
			};
			float v[4];
		};
	public:
		void setFromRotationMatrix(const Matrix4& m){};
};
#endif /*_FAERY_CORE_QUATERNION_H_*/


