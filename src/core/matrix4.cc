/************************************************************
 * File: matrix4.cc
 * Description: Thanks to three.js,I can impliement quickly
 * Author: NosicLin(nosiclin@foxmail.com)
 * Date:2012-9-27
 * LastUpdate:2012-9-28
 * Copyright:Faery Studio
 ************************************************************/

#include"core/matrix4.h"
#include"core/mathutil.h"
#include"util/macros.h"
Matrix4 Matrix4::makeRotateX(float theta)
{
	float c=Math::cos(theta);
	float s=Math::sin(theta);
	return Matrix4(1,0,0,0,
				   0,c,-s,0,
				   0,s,c,0,
				   0,0,0,1);
}

Matrix4 Matrix4::makeRotateY(float theta)
{
	float c=Math::cos(theta);
	float s=Math::sin(theta);
	return Matrix4(c,0,-s,0,
				   0,1,0,0,
				   s,0,c,0,
				   0,0,0,1);
}

Matrix4 Matrix4::makeRotateZ(float theta)
{
	float c=Math::cos(theta);
	float s=Math::sin(theta);
	return Matrix4(c,-s,0,0,
				   s,c,0,0,
				   0,0,1,0,
				   0,0,0,1);
}

Matrix4 Matrix4::makeRotateAxis(const Vector3& v,float theta)
{
	float s=Math::sin(theta);
	float c=Math::cos(theta);
	float x=v.x; float y=v.y; float z=v.z;
	float k=1-c; 
	float xk=x*k; float yk=y*k;

	return Matrix4(x*xk+c,x*yk-s*z,xk*z+y*s,0,
				  xk*y+z*s,y*yk+c,yk*z-x*s,0,
				  xk*z-y*s,yk*z+x*s,k*z*z+c,0,
				  0,0,0,1);
}
Matrix4 Matrix4::makeScale(float x,float y,float z)
{
	return Matrix4(x,0,0,0,
				   0,y,0,0,
				   0,0,z,0,
				   0,0,0,1);
}


void Matrix4::add(const Matrix4& n)
{
	m00+=n.m00;m01+=n.m01;m02+=n.m02;m03+=n.m03;
	m10+=n.m10;m11+=n.m11;m12+=n.m12;m13+=n.m13;
	m20+=n.m20;m21+=n.m21;m22+=n.m22;m23+=n.m23;
	m30+=n.m30;m31+=n.m31;m32+=n.m32;m33+=n.m33;
}

void Matrix4::mul(const Matrix4& n)
{
	float t00,t01,t02,t03;
	float t10,t11,t12,t13;
	float t20,t21,t22,t23;
	float t30,t31,t32,t33;

	t00=m00*n.m00+m01*n.m10+m02*n.m20+m03*n.m30;
	t01=m00*n.m01+m01*n.m11+m02*n.m21+m03*n.m31;
	t02=m00*n.m02+m01*n.m12+m02*n.m22+m03*n.m32;
	t03=m00*n.m03+m01*n.m13+m02*n.m23+m03*n.m33;

	t10=m10*n.m00+m11*n.m10+m12*n.m20+m13*n.m30;
	t11=m10*n.m01+m11*n.m11+m12*n.m21+m13*n.m31;
	t12=m10*n.m02+m11*n.m12+m12*n.m22+m13*n.m32;
	t13=m10*n.m03+m11*n.m13+m12*n.m23+m13*n.m33;

	t20=m20*n.m00+m21*n.m10+m22*n.m20+m23*n.m30;
	t21=m20*n.m01+m21*n.m11+m22*n.m21+m23*n.m31;
	t22=m20*n.m02+m21*n.m12+m22*n.m22+m23*n.m32;
	t23=m20*n.m03+m21*n.m13+m22*n.m23+m23*n.m33;

	t30=m30*n.m00+m31*n.m10+m32*n.m20+m33*n.m30;
	t31=m30*n.m01+m31*n.m11+m32*n.m21+m33*n.m31;
	t32=m30*n.m02+m31*n.m12+m32*n.m22+m33*n.m32;
	t33=m30*n.m03+m31*n.m13+m32*n.m23+m33*n.m33;

	set(t00,t01,t02,t03,
		t10,t11,t12,t13,
		t20,t21,t22,t23,
		t30,t31,t32,t33);
}

void Matrix4::mulScaler(float s)
{
	m00*=s;m01*=s;m02*=s;m03*=s;
	m10*=s;m11*=s;m12*=s;m13*=s;
	m20*=s;m21*=s;m22*=s;m23*=s;
	m30*=s;m31*=s;m32*=s;m33*=s;
}

void Matrix4::transpose()
{
	float tp;
	tp=m10;m10=m01;m01=tp;
	tp=m20;m20=m02;m02=tp;
	tp=m21;m21=m12;m12=tp;
	tp=m30;m30=m03;m03=tp;
	tp=m31;m31=m13;m13=tp;
	tp=m32;m32=m23;m23=tp;
}
float Matrix4::getDetermiant()
{
	float r=m03 * m12 * m21 * m30-
			m02 * m13 * m21 * m30-
			m03 * m11 * m22 * m30+
			m01 * m13 * m22 * m30+

			m02 * m11 * m23 * m30-
			m01 * m12 * m23 * m30-
			m03 * m12 * m20 * m31+
			m02 * m13 * m20 * m31+

			m03 * m10 * m22 * m31-
			m00 * m13 * m22 * m31-
			m02 * m10 * m23 * m31+
			m00 * m12 * m23 * m31+

			m03 * m11 * m20 * m32-
			m01 * m13 * m20 * m32-
			m03 * m10 * m21 * m32+
			m00 * m13 * m21 * m32+

			m01 * m10 * m23 * m32-
			m00 * m11 * m23 * m32-
			m02 * m11 * m20 * m33+
			m01 * m12 * m20 * m33+

			m02 * m10 * m21 * m33-
			m00 * m12 * m21 * m33-
			m01 * m10 * m22 * m33+
			m00 * m11 * m22 * m33;
	return r;
}

void Matrix4::identity()
{
	set(1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		0,0,0,1
	   );
}

void Matrix4::setPosition(float x,float y,float z)
{
	m03=x;
	m13=y;
	m23=z;
}


void Matrix4::setPosition(const Vector3& v)
{
	setPosition(v.x,v.y,v.y);
}

Vector3 Matrix4::getColumnX()
{
	return Vector3(m00,m10,m20);
}

Vector3 Matrix4::getColumnY()
{
	return Vector3(m01,m11,m21);
}

Vector3 Matrix4::getColumnZ()
{
	return Vector3(m02,m12,m22);
}

Vector3 Matrix4::getPosition()
{
	return Vector3(m03,m13,m23);
}

Matrix4 Matrix4::getInverse()
{
	return Matrix4(
			m12*m23*m31 - m13*m22*m31 + m13*m21*m32 - m11*m23*m32 - m12*m21*m33 + m11*m22*m33,
			m03*m22*m31 - m02*m23*m31 - m03*m21*m32 + m01*m23*m32 + m02*m21*m33 - m01*m22*m33,
			m02*m13*m31 - m03*m12*m31 + m03*m11*m32 - m01*m13*m32 - m02*m11*m33 + m01*m12*m33,
			m03*m12*m21 - m02*m13*m21 - m03*m11*m22 + m01*m13*m22 + m02*m11*m23 - m01*m12*m23,
			m13*m22*m30 - m12*m23*m30 - m13*m20*m32 + m10*m23*m32 + m12*m20*m33 - m10*m22*m33,
			m02*m23*m30 - m03*m22*m30 + m03*m20*m32 - m00*m23*m32 - m02*m20*m33 + m00*m22*m33,
			m03*m12*m30 - m02*m13*m30 - m03*m10*m32 + m00*m13*m32 + m02*m10*m33 - m00*m12*m33,
			m02*m13*m20 - m03*m12*m20 + m03*m10*m22 - m00*m13*m22 - m02*m10*m23 + m00*m12*m23,
			m11*m23*m30 - m13*m21*m30 + m13*m20*m31 - m10*m23*m31 - m11*m20*m33 + m10*m21*m33,
			m03*m21*m30 - m01*m23*m30 - m03*m20*m31 + m00*m23*m31 + m01*m20*m33 - m00*m21*m33,
			m01*m13*m30 - m03*m11*m30 + m03*m10*m31 - m00*m13*m31 - m01*m10*m33 + m00*m11*m33,
			m03*m11*m20 - m01*m13*m20 - m03*m10*m21 + m00*m13*m21 + m01*m10*m23 - m00*m11*m23,
			m12*m21*m30 - m11*m22*m30 - m12*m20*m31 + m10*m22*m31 + m11*m20*m32 - m10*m21*m32,
			m01*m22*m30 - m02*m21*m30 + m02*m20*m31 - m00*m22*m31 - m01*m20*m32 + m00*m21*m32,
			m02*m11*m30 - m01*m12*m30 - m02*m10*m31 + m00*m12*m31 + m01*m10*m32 - m00*m11*m32,
			m01*m12*m20 - m02*m11*m20 + m02*m10*m21 - m00*m12*m21 - m01*m10*m22 + m00*m11*m22
			);

}


void Matrix4::setRotationFromEuler(int type,float rx,float ry,float rz)
{
	float a = Math::cos( rx );
	float b = Math::sin( rx );
	float c = Math::cos( ry );
   	float d = Math::sin( ry );
	float e = Math::cos( rz );
	float f = Math::sin( rz );
	switch(type)
	{

		case MR_XYZ:
			{
				float ae = a * e, af = a * f, be = b * e, bf = b * f;
				m00 = c * e;
				m01 = - c * f;
				m02 = d;

				m10 = af + be * d;
				m11 = ae - bf * d;
				m12 = - b * c;

				m20 = bf - ae * d;
				m21 = be + af * d;
				m22 = a * c;

			}
			break;

		case MR_YXZ:
			{


				float ce = c * e, cf = c * f, de = d * e, df = d * f;

				m00 = ce + df * b;
				m01 = de * b - cf;
				m02 = a * d;

				m10 = a * f;
				m11 = a * e;
				m12 = - b;

				m20 = cf * b - de;
				m21 = df + ce * b;
				m22 = a * c;

			}
			break;
		case MR_ZXY:
			{

				float ce = c * e, cf = c * f, de = d * e, df = d * f;

				m00 = ce - df * b;
				m01 = - a * f;
				m02 = de + cf * b;

				m10 = cf + de * b;
				m11 = a * e;
				m12 = df - ce * b;

				m20 = - a * d;
				m21 = b;
				m22 = a * c;

			}
			break;
		case MR_ZYX:
			{


				float ae = a * e, af = a * f, be = b * e, bf = b * f;

				m00 = c * e;
				m01 = be * d - af;
				m02 = ae * d + bf;

				m10 = c * f;
				m11 = bf * d + ae;
				m12 = af * d - be;

				m20 = - d;
				m21 = b * c;
				m22 = a * c;

			} 
			break;
		case MR_YZX:
			{

				float ac = a * c, ad = a * d, bc = b * c, bd = b * d;

				m00 = c * e;
				m01 = bd - ac * f;
				m02 = bc * f + ad;

				m10 = f;
				m11 = a * e;
				m12 = - b * e;

				m20 = - d * e;
				m21 = ad * f + bc;
				m22 = ac - bd * f;


			} 
			break;
		case MR_XZY:
			{

				float ac = a * c, ad = a * d, bc = b * c, bd = b * d;

				m00 = c * e;
				m01 = - f;
				m02 = d * e;

				m10 = ac * f + bd;
				m11 = a * e;
				m12 = ad * f - bc;

				m20 = bc * f - ad;
				m21 = b * e;
				m22 = bd * f + ac;

			}
			break;
		default:
			BUG("Unkown Rotate Type");

	}
}

void Matrix4::setRotationFromQuaternion(const Quaternion& q)
{
		float x = q.x, y = q.y, z = q.z, w = q.w;
		float x2 = x + x, y2 = y + y, z2 = z + z;
		float xx = x * x2, xy = x * y2, xz = x * z2;
		float yy = y * y2, yz = y * z2, zz = z * z2;
		float wx = w * x2, wy = w * y2, wz = w * z2;

		m00 = 1 - ( yy + zz );
		m01 = xy - wz;
		m02 = xz + wy;

		m10 = xy + wz;
		m11 = 1 - ( xx + zz );
		m12 = yz - wx;

		m20 = xz - wy;
		m21 = yz + wx;
		m22 = 1 - ( xx + yy );
} 

void Matrix4::compose(const Vector3& translation,const Quaternion& q,const Vector3& s)
{
		Matrix4 rotate;

		rotate.identity();
		rotate.setRotationFromQuaternion( q );

		Matrix4 scale=makeScale( s.x, s.y, s.z );

		rotate.mul(scale );

		*this=rotate;

		m03 = translation.x;
		m13 = translation.y;
		m23 = translation.z;
}

void Matrix4::decompose(Vector3* translation,Quaternion* q,Vector3* s)
{
	Vector3 v_x(m00,m10,m20);
	Vector3 v_y(m01,m11,m21);
	Vector3 v_z(m02,m12,m22);

	s->x=v_x.length();
	s->y=v_y.length();
	s->z=v_z.length();

	translation->x=m03;
	translation->y=m13;
	translation->z=m23;

	Matrix4 tc=*this;

	tc.m00/=s->x;
	tc.m10/=s->x;
	tc.m20/=s->x;


	tc.m01/=s->y;
	tc.m11/=s->y;
	tc.m21/=s->y;

	tc.m02/=s->z;
	tc.m12/=s->z;
	tc.m22/=s->z;

	q->setFromRotationMatrix(tc);

}













