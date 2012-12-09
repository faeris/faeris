#include "math/FsQuaternion.h"
#include "math/FsMathUtil.h"
#include "math/FsMatrix4.h"

FAERIS_NAMESPACE_BEGIN

void Quaternion::makeFromEuler(const Vector3& v,int order)
{
	float c1=Math::cosa(v.x/2);
	float c2=Math::cosa(v.y/2);
	float c3=Math::cosa(v.z/2);

	float s1=Math::sina(v.x/2);
	float s2=Math::sina(v.y/2);
	float s3=Math::sina(v.z/2);

	switch(order)
	{
		/* qr=qx*qy*qz */
		case FS_EULER_XYZ:
			x = s1 * c2 * c3 + c1 * s2 * s3;
			y = c1 * s2 * c3 - s1 * c2 * s3;
			z = c1 * c2 * s3 + s1 * s2 * c3;
			w = c1 * c2 * c3 - s1 * s2 * s3;
			break;

		/* qr=qx*qz*qz*/
		case FS_EULER_XZY:
			x = s1 * c2 * c3 - c1 * s2 * s3;
			y = c1 * s2 * c3 - s1 * c2 * s3;
			z = c1 * c2 * s3 + s1 * s2 * c3;
			w = c1 * c2 * c3 + s1 * s2 * s3;
			break;

		/* qr=qy*qx*qz */
		case FS_EULER_YXZ:
			x = s1 * c2 * c3 + c1 * s2 * s3;
			y = c1 * s2 * c3 - s1 * c2 * s3;
			z = c1 * c2 * s3 - s1 * s2 * c3;
			w = c1 * c2 * c3 + s1 * s2 * s3;
			break;

		/* qr=qy*qz*qx */
		case FS_EULER_YZX:
			x = s1 * c2 * c3 + c1 * s2 * s3;
			y = c1 * s2 * c3 + s1 * c2 * s3;
			z = c1 * c2 * s3 - s1 * s2 * c3;
			w = c1 * c2 * c3 - s1 * s2 * s3;
			break;

		/* qr=qz*qx*qy */
		case FS_EULER_ZXY:
			x = s1 * c2 * c3 - c1 * s2 * s3;
			y = c1 * s2 * c3 + s1 * c2 * s3;
			z = c1 * c2 * s3 + s1 * s2 * c3;
			w = c1 * c2 * c3 - s1 * s2 * s3;
			break;
		/* qr=qz*qy*qx */
		case FS_EULER_ZYX:
			x = s1 * c2 * c3 - c1 * s2 * s3;
			y = c1 * s2 * c3 + s1 * c2 * s3;
			z = c1 * c2 * s3 - s1 * s2 * c3;
			w = c1 * c2 * c3 + s1 * s2 * s3;
			break;


		default:
			FS_TRACE_WARN("Unkown Euler Older");
	}
}

/* q=[ cos(angle/2),sin(angle/2)*v ] */
void Quaternion::makeFromAxisAngle(const Vector3& v,float angle)
{
	float halfAngle=angle/2;
	float s=Math::sina(halfAngle);

	x=v.x*s; y=v.y*s; z=v.z*s;
	w=Math::cosa(halfAngle);
}

void Quaternion::makeFromRotationMatrix(const Matrix4& m)
{
	/* assumes the upper 3x3 of m is a pure rotation matrix (i.e, unscaled) */
	float trace,s;
	trace = m.m00 + m.m11 + m.m22; 
	if( trace > 0 ) {
		s = 0.5f / Math::sqrt(trace+ 1.0f);
		w = 0.25f / s;
		x = ( m.m21 - m.m12 ) * s;
		y = ( m.m02 - m.m20 ) * s;
		z = ( m.m10 - m.m01 ) * s;
	} 
	else 
	{
		if ( m.m00 > m.m11 && m.m00 > m.m22 ) 
		{
			s = 2.0f * Math::sqrt( 1.0f + m.m00 - m.m11 - m.m22);
			w = (m.m21 - m.m12 ) / s;
			x = 0.25f * s;
			y = (m.m01 + m.m10 ) / s;
			z = (m.m02 + m.m20 ) / s;
		} 
		else if (m.m11 > m.m22) 
		{
			s = 2.0f * Math::sqrt( 1.0f + m.m11 - m.m00 - m.m22);
			w = (m.m02 - m.m20 ) / s;
			x = (m.m01 + m.m10 ) / s;
			y = 0.25f * s;
			z = (m.m12 + m.m21 ) / s;
		} 
		else 
		{
			s = 2.0f * Math::sqrt( 1.0f + m.m22 - m.m00 - m.m11 );
			w = (m.m10 - m.m01 ) / s;
			x = (m.m02 + m.m20 ) / s;
			y = (m.m12 + m.m21 ) / s;
			z = 0.25f * s;
		}
	}
}


void Quaternion::calcuateW()
{
	w=-Math::sqrt(Math::abs(1.0-x*x-y*y-z*z));
}

/* q*inverse(q) =1 */
void Quaternion::inverse()
{
	x=-x; y=-y; z=-z;
}
void Quaternion::getInverse(Quaternion* q)const
{
	q->x=-x; q->y=-y; q->z=-z; q->w=w;
}

void Quaternion::normalize()
{
	float l=Math::sqrt(x*x+y*y+z*z+w*w);
	if(l==0)
	{
		x=0; y=0; z=0; w=0;
	}
	else
	{
		l=1/l;
		x*=l; y*=l; z*=l; w*=l;
	}
}
/* q_a = [ s_a , v_a ]
 * q_b = [ s_b , v_b]
 * q_r = q_a * q_b 
 *     = [ s_a*s_b-dot(v_a,v_b) , s_a*v_b+s_b*s_a+cross(v_a,v_b) ]
 */
void Quaternion::multiply(const Quaternion& a,const Quaternion& b)
{
	float qax = a.x, qay = a.y, qaz = a.z, qaw = a.w;
	float qbx = b.x, qby = b.y, qbz = b.z, qbw = b.w;

	x =  qax * qbw + qay * qbz - qaz * qby + qaw * qbx;
	y = -qax * qbz + qay * qbw + qaz * qbx + qaw * qby;
	z =  qax * qby - qay * qbx + qaz * qbw + qaw * qbz;
	w = -qax * qbx - qay * qby - qaz * qbz + qaw * qbw;
}

/* Vector3 transform by Quaternion 
 * v'=q*v*inverse(q) 
 */ 
Vector3 Quaternion::multiplyVector3(const Vector3& v) const
{
	float dx,dy,dz,ix,iy,iz,iw;
	float sx=v.x, sy=v.y, sz=v.z;
	float qx=x,qy=y,qz=z,qw=w;

	/* calcuate q * v */
	ix =  qw * sx + qy * sz - qz * sy,
	   iy =  qw * sy + qz * sx - qx * sz,
	   iz =  qw * sz + qx * sy - qy * sx,
	   iw = -qx * sx - qy * sy - qz * sz;

	/* calculate result * inverse(q) */

	dx = ix * qw + iw * -qx + iy * -qz - iz * -qy;
	dy = iy * qw + iw * -qy + iz * -qx - ix * -qz;
	dz = iz * qw + iw * -qz + ix * -qy - iy * -qx;

	/* return result */
	return Vector3(dx,dy,dz);
}




/* Interpolating Quaternions 
 *
 *     sin((1-t)*theta))         sin(t*theta)
 * q=  ------------------ q1 +  -------------- q2
 *         sin(theta)             sin(theta)
 *
 * So,given 
 * 		q1=[s1,<x1,y1,z1>]
 * 		q2=[s2,<x2,y2,z2>]
 * theta is obtained by taking the 4D dot product of q1 and q2 
 * 
 *                 dot(q1,q2)
 *    cos(theta)= -------------
 *                 |q1|*|q2|
 *
 * if we are  working with unit-norm quaternion ,then 
 *
 * 	  cos(theta)=s1*s2+x1*x2+y1*y2+z1*z2	
 */

void Quaternion::slerp(const Quaternion& qa,const Quaternion& qb,float t)
{
	/* calcuate the angle between them */
	float cos_half_theta = qa.w * qb.w + qa.x * qb.x + qa.y * qb.y + qa.z * qb.z;

	/* if qa=qb or qa=-qb then theta=0 and we can result is qa */
	if ( Math::abs( cos_half_theta ) >= 1.0 ) 
	{
		w = qa.w; x = qa.x; y = qa.y; z = qa.z;
		return;
	}


	float qmx,qmy,qmz,qmw;
	if ( cos_half_theta < 0 )
	{
		qmx = -qb.x; qmy = -qb.y; qmz = -qb.z; qmw = -qb.w;
		cos_half_theta = -cos_half_theta;
	} 
	else 
	{
		qmx=qb.x; qmy=qb.y; qmz=qb.z ;qmw=qb.w; 
	}

	float half_theta = Math::acosr( cos_half_theta );
	float sin_half_theta = Math::sqrt( 1.0 - cos_half_theta * cos_half_theta );

	/* if theta=180 degrees then result is not fully defined */
	if ( Math::abs( sin_half_theta ) < 0.001 ) {

		w = 0.5 * ( qa.w + qmw );
		x = 0.5 * ( qa.x + qmx );
		y = 0.5 * ( qa.y + qmy );
		z = 0.5 * ( qa.z + qmz );
		return ;
	}

	float ratio_a = Math::sinr( ( 1 - t ) * half_theta ) / sin_half_theta;
	float ratio_b = Math::sinr( t * half_theta ) / sin_half_theta;

	w = ( qa.w * ratio_a + qmw * ratio_b );
	x = ( qa.x * ratio_a + qmx * ratio_b );
	y = ( qa.y * ratio_a + qmy * ratio_b );
	z = ( qa.z * ratio_a + qmz * ratio_b );
}







FAERIS_NAMESPACE_END

