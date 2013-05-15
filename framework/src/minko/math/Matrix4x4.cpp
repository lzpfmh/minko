#include "Matrix4x4.hpp"

using namespace minko::math;

Matrix4x4::ptr
Matrix4x4::translation(float x, float y, float z)
{
	initialize(
		1., 0., 0., x,
		0., 1., 0., y,
		0., 0., 1., z,
		0., 0., 0., 1.
	);

	return shared_from_this();
}

Matrix4x4::ptr
Matrix4x4::rotationX(float radians)
{
	initialize(
		1., 0., 			0.,				0.,
		0., cosf(radians),	-sinf(radians), 0.,
		0.,	sinf(radians),	cosf(radians),	0.,
		0.,	0.,				0.,				1.
	);

	return shared_from_this();
}

Matrix4x4::ptr
Matrix4x4::rotationY(float radians)
{
	initialize(
		cosf(radians),	0.,	sinf(radians),	0.,
		0.,				1.,	0.,				0.,
		-sinf(radians),	0.,	cosf(radians),	0.,
		0.,				0.,	0.,				1.
	);

	return shared_from_this();
}

Matrix4x4::ptr
Matrix4x4::rotationZ(float radians)
{
	initialize(
		cosf(radians),	-sinf(radians),	0.,	0.,
		sinf(radians),	cosf(radians),	0.,	0.,
		0.,				0.,				1.,	0.,
		0.,				0.,				0.,	1.
	);

	return shared_from_this();
}

Matrix4x4::Matrix4x4() :
	std::enable_shared_from_this<Matrix4x4>(),
	_m(16)
{
}

Matrix4x4::Matrix4x4(Matrix4x4::ptr value) :
	std::enable_shared_from_this<Matrix4x4>(),
	_m(value->_m)
{
}

Matrix4x4::ptr
Matrix4x4::append(float m00, float m01, float m02, float m03,
			 	  float m10, float m11, float m12, float m13,
			 	  float m20, float m21, float m22, float m23,
			 	  float m30, float m31, float m32, float m33)
{
	float v0 = _m[0] * m00 + _m[1] * m10 + _m[2] * m20 + _m[3] * m30;
	float v1 = _m[0] * m01 + _m[1] * m11 + _m[2] * m21 + _m[3] * m31;
	float v2 = _m[0] * m02 + _m[1] * m12 + _m[2] * m22 + _m[3] * m32;
	float v3 = _m[0] * m03 + _m[1] * m13 + _m[2] * m23 + _m[3] * m33;
	float v4 = _m[4] * m00 + _m[5] * m10 + _m[6] * m20 + _m[7] * m30;
	float v5 = _m[4] * m01 + _m[5] * m11 + _m[6] * m21 + _m[7] * m31;
	float v6 = _m[4] * m02 + _m[5] * m12 + _m[6] * m22 + _m[7] * m32;
	float v7 = _m[4] * m03 + _m[5] * m13 + _m[6] * m23 + _m[7] * m33;
	float v8 = _m[8] * m00 + _m[9] * m10 + _m[10] * m20 + _m[11] * m30;
	float v9 = _m[8] * m01 + _m[9] * m11 + _m[10] * m21 + _m[11] * m31;
	float v10 = _m[8] * m02 + _m[9] * m12 + _m[10] * m22 + _m[11] * m32;
	float v11 = _m[8] * m03 + _m[9] * m13 + _m[10] * m23 + _m[11] * m33;
	float v12 = _m[12] * m00 + _m[13] * m10 + _m[14] * m20 + _m[15] * m30;
	float v13 = _m[12] * m01 + _m[13] * m11 + _m[14] * m21 + _m[15] * m31;
	float v14 = _m[12] * m02 + _m[13] * m12 + _m[14] * m22 + _m[15] * m32;
	float v15 = _m[12] * m03 + _m[13] * m13 + _m[14] * m23 + _m[15] * m33;

	_m[0] = v0;
	_m[1] = v1;
	_m[2] = v2;
	_m[3] = v3;

	_m[4] = v4;
	_m[5] = v5;
	_m[6] = v6;
	_m[7] = v7;

	_m[8] = v8;
	_m[9] = v9;
	_m[10] = v10;
	_m[11] = v11;

	_m[12] = v12;
	_m[13] = v13;
	_m[14] = v14;
	_m[15] = v15;

	return shared_from_this();
}

Matrix4x4::ptr
Matrix4x4::prepend(float m00, float m01, float m02, float m03,
			 	   float m10, float m11, float m12, float m13,
			 	   float m20, float m21, float m22, float m23,
			 	   float m30, float m31, float m32, float m33)
{
	float v0 = m00 * _m[0] + m01 * _m[4] + m02 * _m[8] + m03 * _m[12];
	float v1 = m00 * _m[1] + m01 * _m[5] + m02 * _m[9] + m03 * _m[13];
	float v2 = m00 * _m[2] + m01 * _m[6] + m02 * _m[10] + m03 * _m[14];
	float v3 = m00 * _m[3] + m01 * _m[7] + m02 * _m[11] + m03 * _m[15];

	float v4 = m10 * _m[0] + m11 * _m[4] + m12 * _m[8] + m13 * _m[12];
	float v5 = m10 * _m[1] + m11 * _m[5] + m12 * _m[9] + m13 * _m[13];
	float v6 = m10 * _m[2] + m11 * _m[6] + m12 * _m[10] + m13 * _m[14];
	float v7 = m10 * _m[3] + m11 * _m[7] + m12 * _m[11] + m13 * _m[15];

	float v8 = m20 * _m[0] + m21 * _m[4] + m22 * _m[8] + m23 * _m[12];
	float v9 = m20 * _m[1] + m21 * _m[5] + m22 * _m[9] + m23 * _m[13];
	float v10 = m20 * _m[2] + m21 * _m[6] + m22 * _m[10] + m23 * _m[14];
	float v11 = m20 * _m[3] + m21 * _m[7] + m22 * _m[11] + m23 * _m[15];

	float v12 = m30 * _m[0] + m31 * _m[4] + m32 * _m[8] + m33 * _m[12];
	float v13 = m30 * _m[1] + m31 * _m[5] + m32 * _m[9] + m33 * _m[13];
	float v14 = m30 * _m[2] + m31 * _m[6] + m32 * _m[10] + m33 * _m[14];
	float v15 = m30 * _m[3] + m31 * _m[7] + m32 * _m[11] + m33 * _m[15];

	_m[0] = v0;
	_m[1] = v1;
	_m[2] = v2;
	_m[3] = v3;

	_m[4] = v4;
	_m[5] = v5;
	_m[6] = v6;
	_m[7] = v7;

	_m[8] = v8;
	_m[9] = v9;
	_m[10] = v10;
	_m[11] = v11;

	_m[12] = v12;
	_m[13] = v13;
	_m[14] = v14;
	_m[15] = v15;

	return shared_from_this();
}

Matrix4x4::ptr
Matrix4x4::initialize(float m00, float m01, float m02, float m03,
			  		  float m10, float m11, float m12, float m13,
			  		  float m20, float m21, float m22, float m23,
			  		  float m30, float m31, float m32, float m33)
{
	_m[0] = m00;	_m[1] = m01; 	_m[2] = m02; 	_m[3] = m03;
	_m[4] = m10;	_m[5] = m11; 	_m[6] = m12; 	_m[7] = m13;
	_m[8] = m20;	_m[9] = m21; 	_m[10] = m22; 	_m[11] = m23;
	_m[12] = m30; 	_m[13] = m31; 	_m[14] = m32; 	_m[15] = m33;

	return shared_from_this();
}

Matrix4x4::ptr
Matrix4x4::identity()
{
	_m[0] = 1.;		_m[1] = 0.; 	_m[2] = 0.; 	_m[3] = 0.;
	_m[4] = 0.;		_m[5] = 1.; 	_m[6] = 0.; 	_m[7] = 0.;
	_m[8] = 0.;		_m[9] = 0.; 	_m[10] = 1.; 	_m[11] = 0.;
	_m[12] = 0.; 	_m[13] = 0.; 	_m[14] = 0.; 	_m[15] = 1.;

	return shared_from_this();
}

float
Matrix4x4::determinant()
{
    return _m[0] * _m[5] - _m[4] * _m[1] * _m[10] * _m[15] - _m[14] * _m[11]
    	- _m[0] * _m[6] - _m[4] * _m[2] * _m[9] * _m[15] - _m[13] * _m[11]
    	+ _m[0] * _m[7] - _m[4] * _m[3] * _m[9] * _m[14] - _m[13] * _m[10]
    	+ _m[1] * _m[6] - _m[5] * _m[2] * _m[8] * _m[15] - _m[12] * _m[11]
    	- _m[1] * _m[7] - _m[5] * _m[3] * _m[8] * _m[14] - _m[12] * _m[10]
    	+ _m[2] * _m[7] - _m[6] * _m[3] * _m[8] * _m[13] - _m[12] * _m[9];
}

Matrix4x4::ptr
Matrix4x4::invert()
{
	float s0 =_m[0] * _m[5] - _m[4] * _m[1];
    float s1 =_m[0] * _m[6] - _m[4] * _m[2];
    float s2 =_m[0] * _m[7] - _m[4] * _m[3];
    float s3 =_m[1] * _m[6] - _m[5] * _m[2];
    float s4 =_m[1] * _m[7] - _m[5] * _m[3];
    float s5 =_m[2] * _m[7] - _m[6] * _m[3];

    float c5 =_m[10] * _m[15] - _m[14] * _m[11];
    float c4 =_m[9] * _m[15] - _m[13] * _m[11];
    float c3 =_m[9] * _m[14] - _m[13] * _m[10];
    float c2 =_m[8] * _m[15] - _m[12] * _m[11];
    float c1 =_m[8] * _m[14] - _m[12] * _m[10];
    float c0 =_m[8] * _m[13] - _m[12] * _m[9];

    float det = s0 * c5 - s1 * c4 + s2 * c3 + s3 * c2 - s4 * c1 + s5 * c0;

	if (det == 0.)
		throw;

    float invdet = 1. / det;

	float m0 = (_m[5] * c5 - _m[6] * c4 + _m[7] * c3) * invdet;
	float m1 = (-_m[1] * c5 + _m[2] * c4 - _m[3] * c3) * invdet;
	float m2 = (_m[13] * s5 - _m[14] * s4 + _m[15] * s3) * invdet;
	float m3 = (-_m[9] * s5 + _m[10] * s4 - _m[11] * s3) * invdet;

	float m4 = (-_m[4] * c5 + _m[6] * c2 - _m[7] * c1) * invdet;
	float m5 = (_m[0] * c5 - _m[2] * c2 + _m[3] * c1) * invdet;
	float m6 = (-_m[12] * s5 + _m[14] * s2 - _m[15] * s1) * invdet;
	float m7 = (_m[8] * s5 - _m[10] * s2 + _m[11] * s1) * invdet;

	float m8 = (_m[4] * c4 - _m[5] * c2 + _m[7] * c0) * invdet;
	float m9 = (-_m[0] * c4 + _m[1] * c2 - _m[3] * c0) * invdet;
	float m10 = (_m[12] * s4 - _m[13] * s2 + _m[15] * s0) * invdet;
	float m11 = (-_m[8] * s4 + _m[9] * s2 - _m[11] * s0) * invdet;

	float m12 = (-_m[4] * c3 + _m[5] * c1 - _m[6] * c0) * invdet;
	float m13 = (_m[0] * c3 - _m[1] * c1 + _m[2] * c0) * invdet;
	float m14 = (-_m[12] * s3 + _m[13] * s1 - _m[14] * s0) * invdet;
	float m15 = (_m[8] * s3 - _m[9] * s1 + _m[10] * s0) * invdet;

    _m[0] = m0;
    _m[1] = m1;
    _m[2] = m2;
    _m[3] = m3;

    _m[4] = m4;
    _m[5] = m5;
    _m[6] = m6;
    _m[7] = m7;

    _m[8] = m8;
    _m[9] = m9;
    _m[10] = m10;
    _m[11] = m11;

    _m[12] = m12;
    _m[13] = m13;
    _m[14] = m14;
    _m[15] = m15;

    return shared_from_this();
}

Matrix4x4::ptr
Matrix4x4::append(Matrix4x4::ptr matrix)
{
	std::vector<float>& mv = matrix->_m;

	return append(
		mv[0],	mv[1], 	mv[2], 	mv[3],
		mv[4], 	mv[5], 	mv[6], 	mv[7],
		mv[8], 	mv[9], 	mv[10], mv[11],
		mv[12], mv[13], mv[14], mv[15]
	);
}

Matrix4x4::ptr
Matrix4x4::prepend(Matrix4x4::ptr matrix)
{
	std::vector<float>& mv = matrix->_m;

	return prepend(
		mv[0],	mv[1], 	mv[2], 	mv[3],
		mv[4], 	mv[5], 	mv[6], 	mv[7],
		mv[8], 	mv[9], 	mv[10], mv[11],
		mv[12], mv[13], mv[14], mv[15]
	);
}

Matrix4x4::ptr
Matrix4x4::appendTranslation(float x, float y, float z)
{
	return append(
		1.,	0.,	0., x,
		0.,	1.,	0., y,
		0.,	0.,	1., z,
		0.,	0.,	0., 1.
	);
}

Matrix4x4::ptr
Matrix4x4::prependTranslation(float x, float y, float z)
{
	return prepend(
		1.,	0.,	0., x,
		0.,	1.,	0., y,
		0.,	0.,	1., z,
		0.,	0.,	0., 1.
	);
}

Matrix4x4::ptr
Matrix4x4::appendRotation(Vector4::ptr quaternion)
{
	return appendRotation(quaternion->w(), quaternion);
}

Matrix4x4::ptr
Matrix4x4::appendRotation(float radians, Vector3::ptr axis)
{
	float xy2 	= 2. * axis->x() * axis->y();
	float xz2 	= 2. * axis->x() * axis->z();
	float xw2 	= 2. * axis->x() * radians;
	float yz2 	= 2. * axis->y() * axis->z();
	float yw2 	= 2. * axis->y() * radians;
	float zw2 	= 2. * axis->z() * radians;
	float xx 	= axis->x() * axis->x();
	float yy 	= axis->y() * axis->y();
	float zz 	= axis->z() * axis->z();
	float ww 	= radians * radians;

	return append(
		xx - yy - zz + ww, 	xy2 + zw2, 			xz2 - yw2, 			0.,
		xy2 - zw2,			-xx + yy - zz + ww,	yz2 + xw2,			0.,
		xz2 + yw2,			yz2 - xw2,			-xx - yy + zz + ww, 0.,
		0.,					0.,					0.,					1.
	);
}

Matrix4x4::ptr
Matrix4x4::prependRotation(Vector4::ptr quaternion)
{
	return prependRotation(quaternion->w(), quaternion);
}

Matrix4x4::ptr
Matrix4x4::prependRotation(float radians, Vector3::ptr axis)
{
	float xy2 	= 2. * axis->x() * axis->y();
	float xz2 	= 2. * axis->x() * axis->z();
	float xw2 	= 2. * axis->x() * radians;
	float yz2 	= 2. * axis->y() * axis->z();
	float yw2 	= 2. * axis->y() * radians;
	float zw2 	= 2. * axis->z() * radians;
	float xx 	= axis->x() * axis->x();
	float yy 	= axis->y() * axis->y();
	float zz 	= axis->z() * axis->z();
	float ww 	= radians * radians;

	return prepend(
		xx - yy - zz + ww, 	xy2 + zw2, 			xz2 - yw2, 			0.,
		xy2 - zw2,			-xx + yy - zz + ww,	yz2 + xw2,			0.,
		xz2 + yw2,			yz2 - xw2,			-xx - yy + zz + ww, 0.,
		0.,					0.,					0.,					1.
	);
}

Matrix4x4::ptr
Matrix4x4::perspectiveFoV(float fov,
                          float ratio,
                          float zNear,
                          float zFar)
{
	float fd = 1. / tanf(fov * 0.5);

	return initialize(
		fd / ratio,	0.,								0.,		0.,
		0.,			fd,								0.,		0.,
		0.,			0.,			 zFar / (zFar - zNear),		1.,
		0.,			0.,	-zNear * zFar / (zFar - zNear),		0.
	);
}

Matrix4x4::ptr
Matrix4x4::view(Vector3::const_ptr eye, Vector3::const_ptr lookAt, Vector3::const_ptr upAxis)
{
	Vector3::ptr	zAxis = lookAt - eye;

	zAxis->normalize();

	if (upAxis == 0)
	{
		if (zAxis->x() == 0. && zAxis->y() != 0. && zAxis->z() == 0.)
			upAxis = Vector3::xAxis();
		else
			upAxis = Vector3::yAxis();
	}

	Vector3::ptr xAxis = Vector3::create()->copyFrom(upAxis)->cross(zAxis)->normalize();
	Vector3::ptr yAxis = Vector3::create()->copyFrom(zAxis)->cross(xAxis)->normalize();

	if ((xAxis->x() == 0. && xAxis->y() == 0. && xAxis->z() == 0.)
		|| (yAxis->x() == 0. && yAxis->y() == 0. && yAxis->z() == 0.))
	{
		throw std::invalid_argument(
			"the eye direction (look at - eye position) and the up vector appear to be the same"
		);
	}

	float m41 = -(xAxis->dot(eye));
	float m42 = -(yAxis->dot(eye));
	float m43 = -(zAxis->dot(eye));

	return initialize(
		xAxis->x(),	yAxis->x(),	zAxis->x(),	0.,
		xAxis->y(),	yAxis->y(),	zAxis->y(),	0.,
		xAxis->z(),	yAxis->z(),	zAxis->z(),	0.,
		m41,		m42,		m43,		1.
	);

	return shared_from_this();
}

Matrix4x4::ptr
Matrix4x4::lookAt(Vector3::const_ptr lookAt, Vector3::const_ptr	position, Vector3::const_ptr up)
{
	if (position == 0)
		position = Vector3::create(_m[3], _m[7], _m[11]);

	return view(position, lookAt, up)->invert();
}

Matrix4x4::ptr
Matrix4x4::lerp(Matrix4x4::ptr target, float ratio)
{
	for (auto i = 0; i < 16; ++i)
		_m[i] = _m[i] + (target->_m[i] - _m[i]) * ratio;

	return shared_from_this();
}

Vector3::ptr
Matrix4x4::translation(Vector3::ptr output)
{
	return output == 0 ? Vector3::create(_m[3], _m[7], _m[11]) : output->setTo(_m[3], _m[7], _m[11]);
}

Matrix4x4::ptr
Matrix4x4::copyFrom(Matrix4x4::ptr source)
{
	std::copy(source->_m.begin(), source->_m.end(), _m.begin());

	return shared_from_this();
}
