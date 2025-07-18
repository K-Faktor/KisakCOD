#pragma once

#ifndef KISAK_SP
#error This file is for SinglePlayer only
#endif

#include <xanim/dobj.h>
#include <bgame/bg_local.h>

void __cdecl QuatMultiply(float *in1, float *in2, float *out);
void __cdecl PitchToQuat(double pitch, float *quat, float *a3);
void __cdecl RollToQuat(double roll, float *quat, float *a3);
void __cdecl LocalMatrixTransformVectorQuatTrans(const float *in, const DObjAnimMat *mat, float *out);
void __cdecl NormalizeQuatTrans(DObjAnimMat *mat);
void __cdecl CG_mg42_DoControllers(const cpose_t *pose, const DObj_s *obj, int *partBits, long double a4);
void __cdecl CG_Vehicle_DoControllers(const cpose_t *pose, const DObj_s *obj, int *partBits);
void __cdecl CG_Actor_DoControllers(const cpose_t *pose, const DObj_s *obj, int *partBits);
void __cdecl CG_DoBaseOriginController(const cpose_t *pose, const DObj_s *obj, int *setPartBits);
void __cdecl CG_DoControllers(const cpose_t *pose, const DObj_s *obj, int *partBits);
DObjAnimMat *__cdecl CG_DObjCalcPose(const cpose_t *pose, const DObj_s *obj, int *partBits);

int __cdecl CompressUnit(double unit)
{
    if (unit < 0.0 || unit > 1.0)
        MyAssertHandler(
            "c:\\trees\\cod3\\cod3src\\src\\cgame\\cg_pose.h",
            71,
            0,
            "%s\n\t(unit) = %g",
            HIDWORD(unit),
            LODWORD(unit));
    return (unsigned __int16)(__int64)(float)((float)((float)unit * (float)65535.0) + (float)0.5);
}