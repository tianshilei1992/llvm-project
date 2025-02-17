//===-- include/flang/Runtime/reduce.h --------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// Defines the API for implementations of the transformational intrinsic
// function REDUCE(); see F'2023 16.9.173.
//
// Similar to the definition of the APIs for SUM(), &c., in reduction.h,
// there are typed functions here like ReduceInteger4() for total reductions
// to scalars and void functions like ReduceInteger4Dim() for partial
// reductions to smaller arrays.

#ifndef FORTRAN_RUNTIME_REDUCE_H_
#define FORTRAN_RUNTIME_REDUCE_H_

#include "flang/Common/float128.h"
#include "flang/Common/uint128.h"
#include "flang/Runtime/cpp-type.h"
#include "flang/Runtime/entry-names.h"
#include <complex>
#include <cstdint>

namespace Fortran::runtime {

class Descriptor;

template <typename T>
using ReferenceReductionOperation = T (*)(const T *, const T *);
template <typename T> using ValueReductionOperation = T (*)(T, T);
template <typename CHAR>
using ReductionCharOperation = void (*)(CHAR *hiddenResult,
    std::size_t resultLen, const CHAR *x, const CHAR *y, std::size_t xLen,
    std::size_t yLen);
using ReductionDerivedTypeOperation = void (*)(
    void *hiddenResult, const void *x, const void *y);

extern "C" {

std::int8_t RTDECL(ReduceInteger1Ref)(const Descriptor &,
    ReferenceReductionOperation<std::int8_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::int8_t *identity = nullptr, bool ordered = true);
std::int8_t RTDECL(ReduceInteger1Value)(const Descriptor &,
    ValueReductionOperation<std::int8_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::int8_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceInteger1DimRef)(Descriptor &result, const Descriptor &array,
    ReferenceReductionOperation<std::int8_t>, const char *source, int line,
    int dim, const Descriptor *mask = nullptr,
    const std::int8_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceInteger1DimValue)(Descriptor &result, const Descriptor &array,
    ValueReductionOperation<std::int8_t>, const char *source, int line, int dim,
    const Descriptor *mask = nullptr, const std::int8_t *identity = nullptr,
    bool ordered = true);
std::int16_t RTDECL(ReduceInteger2Ref)(const Descriptor &,
    ReferenceReductionOperation<std::int16_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::int16_t *identity = nullptr, bool ordered = true);
std::int16_t RTDECL(ReduceInteger2Value)(const Descriptor &,
    ValueReductionOperation<std::int16_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::int16_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceInteger2DimRef)(Descriptor &result, const Descriptor &array,
    ReferenceReductionOperation<std::int16_t>, const char *source, int line,
    int dim, const Descriptor *mask = nullptr,
    const std::int16_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceInteger2DimValue)(Descriptor &result, const Descriptor &array,
    ValueReductionOperation<std::int16_t>, const char *source, int line,
    int dim, const Descriptor *mask = nullptr,
    const std::int16_t *identity = nullptr, bool ordered = true);
std::int32_t RTDECL(ReduceInteger4Ref)(const Descriptor &,
    ReferenceReductionOperation<std::int32_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::int32_t *identity = nullptr, bool ordered = true);
std::int32_t RTDECL(ReduceInteger4Value)(const Descriptor &,
    ValueReductionOperation<std::int32_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::int32_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceInteger4DimRef)(Descriptor &result, const Descriptor &array,
    ReferenceReductionOperation<std::int32_t>, const char *source, int line,
    int dim, const Descriptor *mask = nullptr,
    const std::int32_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceInteger4DimValue)(Descriptor &result, const Descriptor &array,
    ValueReductionOperation<std::int32_t>, const char *source, int line,
    int dim, const Descriptor *mask = nullptr,
    const std::int32_t *identity = nullptr, bool ordered = true);
std::int64_t RTDECL(ReduceInteger8Ref)(const Descriptor &,
    ReferenceReductionOperation<std::int64_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::int64_t *identity = nullptr, bool ordered = true);
std::int64_t RTDECL(ReduceInteger8Value)(const Descriptor &,
    ValueReductionOperation<std::int64_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::int64_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceInteger8DimRef)(Descriptor &result, const Descriptor &array,
    ReferenceReductionOperation<std::int64_t>, const char *source, int line,
    int dim, const Descriptor *mask = nullptr,
    const std::int64_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceInteger8DimValue)(Descriptor &result, const Descriptor &array,
    ValueReductionOperation<std::int64_t>, const char *source, int line,
    int dim, const Descriptor *mask = nullptr,
    const std::int64_t *identity = nullptr, bool ordered = true);
#ifdef __SIZEOF_INT128__
common::int128_t RTDECL(ReduceInteger16Ref)(const Descriptor &,
    ReferenceReductionOperation<common::int128_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const common::int128_t *identity = nullptr, bool ordered = true);
common::int128_t RTDECL(ReduceInteger16Value)(const Descriptor &,
    ValueReductionOperation<common::int128_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const common::int128_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceInteger16DimRef)(Descriptor &result, const Descriptor &array,
    ReferenceReductionOperation<common::int128_t>, const char *source, int line,
    int dim, const Descriptor *mask = nullptr,
    const common::int128_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceInteger16DimValue)(Descriptor &result,
    const Descriptor &array, ValueReductionOperation<common::int128_t>,
    const char *source, int line, int dim, const Descriptor *mask = nullptr,
    const common::int128_t *identity = nullptr, bool ordered = true);
#endif

std::uint8_t RTDECL(ReduceUnsigned1Ref)(const Descriptor &,
    ReferenceReductionOperation<std::uint8_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::uint8_t *identity = nullptr, bool ordered = true);
std::uint8_t RTDECL(ReduceUnsigned1Value)(const Descriptor &,
    ValueReductionOperation<std::uint8_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::uint8_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceUnsigned1DimRef)(Descriptor &result, const Descriptor &array,
    ReferenceReductionOperation<std::uint8_t>, const char *source, int line,
    int dim, const Descriptor *mask = nullptr,
    const std::uint8_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceUnsigned1DimValue)(Descriptor &result,
    const Descriptor &array, ValueReductionOperation<std::uint8_t>,
    const char *source, int line, int dim, const Descriptor *mask = nullptr,
    const std::uint8_t *identity = nullptr, bool ordered = true);
std::uint16_t RTDECL(ReduceUnsigned2Ref)(const Descriptor &,
    ReferenceReductionOperation<std::uint16_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::uint16_t *identity = nullptr, bool ordered = true);
std::uint16_t RTDECL(ReduceUnsigned2Value)(const Descriptor &,
    ValueReductionOperation<std::uint16_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::uint16_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceUnsigned2DimRef)(Descriptor &result, const Descriptor &array,
    ReferenceReductionOperation<std::uint16_t>, const char *source, int line,
    int dim, const Descriptor *mask = nullptr,
    const std::uint16_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceUnsigned2DimValue)(Descriptor &result,
    const Descriptor &array, ValueReductionOperation<std::uint16_t>,
    const char *source, int line, int dim, const Descriptor *mask = nullptr,
    const std::uint16_t *identity = nullptr, bool ordered = true);
std::uint32_t RTDECL(ReduceUnsigned4Ref)(const Descriptor &,
    ReferenceReductionOperation<std::uint32_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::uint32_t *identity = nullptr, bool ordered = true);
std::uint32_t RTDECL(ReduceUnsigned4Value)(const Descriptor &,
    ValueReductionOperation<std::uint32_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::uint32_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceUnsigned4DimRef)(Descriptor &result, const Descriptor &array,
    ReferenceReductionOperation<std::uint32_t>, const char *source, int line,
    int dim, const Descriptor *mask = nullptr,
    const std::uint32_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceUnsigned4DimValue)(Descriptor &result,
    const Descriptor &array, ValueReductionOperation<std::uint32_t>,
    const char *source, int line, int dim, const Descriptor *mask = nullptr,
    const std::uint32_t *identity = nullptr, bool ordered = true);
std::uint64_t RTDECL(ReduceUnsigned8Ref)(const Descriptor &,
    ReferenceReductionOperation<std::uint64_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::uint64_t *identity = nullptr, bool ordered = true);
std::uint64_t RTDECL(ReduceUnsigned8Value)(const Descriptor &,
    ValueReductionOperation<std::uint64_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::uint64_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceUnsigned8DimRef)(Descriptor &result, const Descriptor &array,
    ReferenceReductionOperation<std::uint64_t>, const char *source, int line,
    int dim, const Descriptor *mask = nullptr,
    const std::uint64_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceUnsigned8DimValue)(Descriptor &result,
    const Descriptor &array, ValueReductionOperation<std::uint64_t>,
    const char *source, int line, int dim, const Descriptor *mask = nullptr,
    const std::uint64_t *identity = nullptr, bool ordered = true);
#ifdef __SIZEOF_INT128__
common::uint128_t RTDECL(ReduceUnsigned16Ref)(const Descriptor &,
    ReferenceReductionOperation<common::uint128_t>, const char *source,
    int line, int dim = 0, const Descriptor *mask = nullptr,
    const common::uint128_t *identity = nullptr, bool ordered = true);
common::uint128_t RTDECL(ReduceUnsigned16Value)(const Descriptor &,
    ValueReductionOperation<common::uint128_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const common::uint128_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceUnsigned16DimRef)(Descriptor &result, const Descriptor &array,
    ReferenceReductionOperation<common::uint128_t>, const char *source,
    int line, int dim, const Descriptor *mask = nullptr,
    const common::uint128_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceUnsigned16DimValue)(Descriptor &result,
    const Descriptor &array, ValueReductionOperation<common::uint128_t>,
    const char *source, int line, int dim, const Descriptor *mask = nullptr,
    const common::uint128_t *identity = nullptr, bool ordered = true);
#endif

// REAL/COMPLEX(2 & 3) return 32-bit float results for the caller to downconvert
float RTDECL(ReduceReal2Ref)(const Descriptor &,
    ReferenceReductionOperation<float>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const float *identity = nullptr, bool ordered = true);
float RTDECL(ReduceReal2Value)(const Descriptor &,
    ValueReductionOperation<float>, const char *source, int line, int dim = 0,
    const Descriptor *mask = nullptr, const float *identity = nullptr,
    bool ordered = true);
void RTDECL(ReduceReal2DimRef)(Descriptor &result, const Descriptor &array,
    ReferenceReductionOperation<float>, const char *source, int line, int dim,
    const Descriptor *mask = nullptr, const float *identity = nullptr,
    bool ordered = true);
void RTDECL(ReduceReal2DimValue)(Descriptor &result, const Descriptor &array,
    ValueReductionOperation<float>, const char *source, int line, int dim,
    const Descriptor *mask = nullptr, const float *identity = nullptr,
    bool ordered = true);
float RTDECL(ReduceReal3Ref)(const Descriptor &,
    ReferenceReductionOperation<float>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const float *identity = nullptr, bool ordered = true);
float RTDECL(ReduceReal3Value)(const Descriptor &,
    ValueReductionOperation<float>, const char *source, int line, int dim = 0,
    const Descriptor *mask = nullptr, const float *identity = nullptr,
    bool ordered = true);
void RTDECL(ReduceReal3DimRef)(Descriptor &result, const Descriptor &array,
    ReferenceReductionOperation<float>, const char *source, int line, int dim,
    const Descriptor *mask = nullptr, const float *identity = nullptr,
    bool ordered = true);
void RTDECL(ReduceReal3DimValue)(Descriptor &result, const Descriptor &array,
    ValueReductionOperation<float>, const char *source, int line, int dim,
    const Descriptor *mask = nullptr, const float *identity = nullptr,
    bool ordered = true);
float RTDECL(ReduceReal4Ref)(const Descriptor &,
    ReferenceReductionOperation<float>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const float *identity = nullptr, bool ordered = true);
float RTDECL(ReduceReal4Value)(const Descriptor &,
    ValueReductionOperation<float>, const char *source, int line, int dim = 0,
    const Descriptor *mask = nullptr, const float *identity = nullptr,
    bool ordered = true);
void RTDECL(ReduceReal4DimRef)(Descriptor &result, const Descriptor &array,
    ReferenceReductionOperation<float>, const char *source, int line, int dim,
    const Descriptor *mask = nullptr, const float *identity = nullptr,
    bool ordered = true);
void RTDECL(ReduceReal4DimValue)(Descriptor &result, const Descriptor &array,
    ValueReductionOperation<float>, const char *source, int line, int dim,
    const Descriptor *mask = nullptr, const float *identity = nullptr,
    bool ordered = true);
double RTDECL(ReduceReal8Ref)(const Descriptor &,
    ReferenceReductionOperation<double>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const double *identity = nullptr, bool ordered = true);
double RTDECL(ReduceReal8Value)(const Descriptor &,
    ValueReductionOperation<double>, const char *source, int line, int dim = 0,
    const Descriptor *mask = nullptr, const double *identity = nullptr,
    bool ordered = true);
void RTDECL(ReduceReal8DimRef)(Descriptor &result, const Descriptor &array,
    ReferenceReductionOperation<double>, const char *source, int line, int dim,
    const Descriptor *mask = nullptr, const double *identity = nullptr,
    bool ordered = true);
void RTDECL(ReduceReal8DimValue)(Descriptor &result, const Descriptor &array,
    ValueReductionOperation<double>, const char *source, int line, int dim,
    const Descriptor *mask = nullptr, const double *identity = nullptr,
    bool ordered = true);
#if HAS_FLOAT80
CppTypeFor<TypeCategory::Real, 10> RTDECL(ReduceReal10Ref)(const Descriptor &,
    ReferenceReductionOperation<CppTypeFor<TypeCategory::Real, 10>>,
    const char *source, int line, int dim = 0, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Real, 10> *identity = nullptr,
    bool ordered = true);
CppTypeFor<TypeCategory::Real, 10> RTDECL(ReduceReal10Value)(const Descriptor &,
    ValueReductionOperation<CppTypeFor<TypeCategory::Real, 10>>,
    const char *source, int line, int dim = 0, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Real, 10> *identity = nullptr,
    bool ordered = true);
void RTDECL(ReduceReal10DimRef)(Descriptor &result, const Descriptor &array,
    ReferenceReductionOperation<CppTypeFor<TypeCategory::Real, 10>>,
    const char *source, int line, int dim, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Real, 10> *identity = nullptr,
    bool ordered = true);
void RTDECL(ReduceReal10DimValue)(Descriptor &result, const Descriptor &array,
    ValueReductionOperation<CppTypeFor<TypeCategory::Real, 10>>,
    const char *source, int line, int dim, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Real, 10> *identity = nullptr,
    bool ordered = true);
#endif
#if HAS_LDBL128 || HAS_FLOAT128
CppFloat128Type RTDECL(ReduceReal16Ref)(const Descriptor &,
    ReferenceReductionOperation<CppFloat128Type>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const CppFloat128Type *identity = nullptr, bool ordered = true);
CppFloat128Type RTDECL(ReduceReal16Value)(const Descriptor &,
    ValueReductionOperation<CppFloat128Type>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const CppFloat128Type *identity = nullptr, bool ordered = true);
void RTDECL(ReduceReal16DimRef)(Descriptor &result, const Descriptor &array,
    ReferenceReductionOperation<CppFloat128Type>, const char *source, int line,
    int dim, const Descriptor *mask = nullptr,
    const CppFloat128Type *identity = nullptr, bool ordered = true);
void RTDECL(ReduceReal16DimValue)(Descriptor &result, const Descriptor &array,
    ValueReductionOperation<CppFloat128Type>, const char *source, int line,
    int dim, const Descriptor *mask = nullptr,
    const CppFloat128Type *identity = nullptr, bool ordered = true);
#endif

void RTDECL(CppReduceComplex2Ref)(CppTypeFor<TypeCategory::Complex, 4> &,
    const Descriptor &,
    ReferenceReductionOperation<CppTypeFor<TypeCategory::Complex, 4>>,
    const char *source, int line, int dim = 0, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 4> *identity = nullptr,
    bool ordered = true);
void RTDECL(CppReduceComplex2Value)(CppTypeFor<TypeCategory::Complex, 4> &,
    const Descriptor &,
    ValueReductionOperation<CppTypeFor<TypeCategory::Complex, 4>>,
    const char *source, int line, int dim = 0, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 4> *identity = nullptr,
    bool ordered = true);
void RTDECL(CppReduceComplex2DimRef)(Descriptor &result,
    const Descriptor &array,
    ReferenceReductionOperation<CppTypeFor<TypeCategory::Complex, 4>>,
    const char *source, int line, int dim, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 4> *identity = nullptr,
    bool ordered = true);
void RTDECL(CppReduceComplex2DimValue)(Descriptor &result,
    const Descriptor &array,
    ValueReductionOperation<CppTypeFor<TypeCategory::Complex, 4>>,
    const char *source, int line, int dim, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 4> *identity = nullptr,
    bool ordered = true);
void RTDECL(CppReduceComplex3Ref)(CppTypeFor<TypeCategory::Complex, 4> &,
    const Descriptor &,
    ReferenceReductionOperation<CppTypeFor<TypeCategory::Complex, 4>>,
    const char *source, int line, int dim = 0, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 4> *identity = nullptr,
    bool ordered = true);
void RTDECL(CppReduceComplex3Value)(CppTypeFor<TypeCategory::Complex, 4> &,
    const Descriptor &,
    ValueReductionOperation<CppTypeFor<TypeCategory::Complex, 4>>,
    const char *source, int line, int dim = 0, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 4> *identity = nullptr,
    bool ordered = true);
void RTDECL(CppReduceComplex3DimRef)(Descriptor &result,
    const Descriptor &array,
    ReferenceReductionOperation<CppTypeFor<TypeCategory::Complex, 4>>,
    const char *source, int line, int dim, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 4> *identity = nullptr,
    bool ordered = true);
void RTDECL(CppReduceComplex3DimValue)(Descriptor &result,
    const Descriptor &array,
    ValueReductionOperation<CppTypeFor<TypeCategory::Complex, 4>>,
    const char *source, int line, int dim, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 4> *identity = nullptr,
    bool ordered = true);
void RTDECL(CppReduceComplex4Ref)(CppTypeFor<TypeCategory::Complex, 4> &,
    const Descriptor &,
    ReferenceReductionOperation<CppTypeFor<TypeCategory::Complex, 4>>,
    const char *source, int line, int dim = 0, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 4> *identity = nullptr,
    bool ordered = true);
void RTDECL(CppReduceComplex4Value)(CppTypeFor<TypeCategory::Complex, 4> &,
    const Descriptor &,
    ValueReductionOperation<CppTypeFor<TypeCategory::Complex, 4>>,
    const char *source, int line, int dim = 0, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 4> *identity = nullptr,
    bool ordered = true);
void RTDECL(CppReduceComplex4DimRef)(Descriptor &result,
    const Descriptor &array,
    ReferenceReductionOperation<CppTypeFor<TypeCategory::Complex, 4>>,
    const char *source, int line, int dim, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 4> *identity = nullptr,
    bool ordered = true);
void RTDECL(CppReduceComplex4DimValue)(Descriptor &result,
    const Descriptor &array,
    ValueReductionOperation<CppTypeFor<TypeCategory::Complex, 4>>,
    const char *source, int line, int dim, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 4> *identity = nullptr,
    bool ordered = true);
void RTDECL(CppReduceComplex8Ref)(CppTypeFor<TypeCategory::Complex, 8> &,
    const Descriptor &,
    ReferenceReductionOperation<CppTypeFor<TypeCategory::Complex, 8>>,
    const char *source, int line, int dim = 0, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 8> *identity = nullptr,
    bool ordered = true);
void RTDECL(CppReduceComplex8Value)(CppTypeFor<TypeCategory::Complex, 8> &,
    const Descriptor &,
    ValueReductionOperation<CppTypeFor<TypeCategory::Complex, 8>>,
    const char *source, int line, int dim = 0, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 8> *identity = nullptr,
    bool ordered = true);
void RTDECL(CppReduceComplex8DimRef)(Descriptor &result,
    const Descriptor &array,
    ReferenceReductionOperation<CppTypeFor<TypeCategory::Complex, 8>>,
    const char *source, int line, int dim, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 8> *identity = nullptr,
    bool ordered = true);
void RTDECL(CppReduceComplex8DimValue)(Descriptor &result,
    const Descriptor &array,
    ValueReductionOperation<CppTypeFor<TypeCategory::Complex, 8>>,
    const char *source, int line, int dim, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 8> *identity = nullptr,
    bool ordered = true);
#if HAS_FLOAT80
void RTDECL(CppReduceComplex10Ref)(CppTypeFor<TypeCategory::Complex, 10> &,
    const Descriptor &,
    ReferenceReductionOperation<CppTypeFor<TypeCategory::Complex, 10>>,
    const char *source, int line, int dim = 0, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 10> *identity = nullptr,
    bool ordered = true);
void RTDECL(CppReduceComplex10Value)(CppTypeFor<TypeCategory::Complex, 10> &,
    const Descriptor &,
    ValueReductionOperation<CppTypeFor<TypeCategory::Complex, 10>>,
    const char *source, int line, int dim = 0, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 10> *identity = nullptr,
    bool ordered = true);
void RTDECL(CppReduceComplex10DimRef)(Descriptor &result,
    const Descriptor &array,
    ReferenceReductionOperation<CppTypeFor<TypeCategory::Complex, 10>>,
    const char *source, int line, int dim, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 10> *identity = nullptr,
    bool ordered = true);
void RTDECL(CppReduceComplex10DimValue)(Descriptor &result,
    const Descriptor &array,
    ValueReductionOperation<CppTypeFor<TypeCategory::Complex, 10>>,
    const char *source, int line, int dim, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 10> *identity = nullptr,
    bool ordered = true);
#endif
#if HAS_LDBL128 || HAS_FLOAT128
void RTDECL(CppReduceComplex16Ref)(CppTypeFor<TypeCategory::Complex, 16> &,
    const Descriptor &,
    ReferenceReductionOperation<CppTypeFor<TypeCategory::Complex, 16>>,
    const char *source, int line, int dim = 0, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 16> *identity = nullptr,
    bool ordered = true);
void RTDECL(CppReduceComplex16Value)(CppTypeFor<TypeCategory::Complex, 16> &,
    const Descriptor &,
    ValueReductionOperation<CppTypeFor<TypeCategory::Complex, 16>>,
    const char *source, int line, int dim = 0, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 16> *identity = nullptr,
    bool ordered = true);
void RTDECL(CppReduceComplex16DimRef)(Descriptor &result,
    const Descriptor &array,
    ReferenceReductionOperation<CppTypeFor<TypeCategory::Complex, 16>>,
    const char *source, int line, int dim, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 16> *identity = nullptr,
    bool ordered = true);
void RTDECL(CppReduceComplex16DimValue)(Descriptor &result,
    const Descriptor &array,
    ValueReductionOperation<CppTypeFor<TypeCategory::Complex, 16>>,
    const char *source, int line, int dim, const Descriptor *mask = nullptr,
    const CppTypeFor<TypeCategory::Complex, 16> *identity = nullptr,
    bool ordered = true);
#endif

bool RTDECL(ReduceLogical1Ref)(const Descriptor &,
    ReferenceReductionOperation<std::int8_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::int8_t *identity = nullptr, bool ordered = true);
bool RTDECL(ReduceLogical1Value)(const Descriptor &,
    ValueReductionOperation<std::int8_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::int8_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceLogical1DimRef)(Descriptor &result, const Descriptor &array,
    ReferenceReductionOperation<std::int8_t>, const char *source, int line,
    int dim, const Descriptor *mask = nullptr,
    const std::int8_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceLogical1DimValue)(Descriptor &result, const Descriptor &array,
    ValueReductionOperation<std::int8_t>, const char *source, int line, int dim,
    const Descriptor *mask = nullptr, const std::int8_t *identity = nullptr,
    bool ordered = true);
bool RTDECL(ReduceLogical2Ref)(const Descriptor &,
    ReferenceReductionOperation<std::int16_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::int16_t *identity = nullptr, bool ordered = true);
bool RTDECL(ReduceLogical2Value)(const Descriptor &,
    ValueReductionOperation<std::int16_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::int16_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceLogical2DimRef)(Descriptor &result, const Descriptor &array,
    ReferenceReductionOperation<std::int16_t>, const char *source, int line,
    int dim, const Descriptor *mask = nullptr,
    const std::int16_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceLogical2DimValue)(Descriptor &result, const Descriptor &array,
    ValueReductionOperation<std::int16_t>, const char *source, int line,
    int dim, const Descriptor *mask = nullptr,
    const std::int16_t *identity = nullptr, bool ordered = true);
bool RTDECL(ReduceLogical4Ref)(const Descriptor &,
    ReferenceReductionOperation<std::int32_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::int32_t *identity = nullptr, bool ordered = true);
bool RTDECL(ReduceLogical4Value)(const Descriptor &,
    ValueReductionOperation<std::int32_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::int32_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceLogical4DimRef)(Descriptor &result, const Descriptor &array,
    ReferenceReductionOperation<std::int32_t>, const char *source, int line,
    int dim, const Descriptor *mask = nullptr,
    const std::int32_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceLogical4DimValue)(Descriptor &result, const Descriptor &array,
    ValueReductionOperation<std::int32_t>, const char *source, int line,
    int dim, const Descriptor *mask = nullptr,
    const std::int32_t *identity = nullptr, bool ordered = true);
bool RTDECL(ReduceLogical8Ref)(const Descriptor &,
    ReferenceReductionOperation<std::int64_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::int64_t *identity = nullptr, bool ordered = true);
bool RTDECL(ReduceLogical8Value)(const Descriptor &,
    ValueReductionOperation<std::int64_t>, const char *source, int line,
    int dim = 0, const Descriptor *mask = nullptr,
    const std::int64_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceLogical8DimRef)(Descriptor &result, const Descriptor &array,
    ReferenceReductionOperation<std::int64_t>, const char *source, int line,
    int dim, const Descriptor *mask = nullptr,
    const std::int64_t *identity = nullptr, bool ordered = true);
void RTDECL(ReduceLogical8DimValue)(Descriptor &result, const Descriptor &array,
    ValueReductionOperation<std::int64_t>, const char *source, int line,
    int dim, const Descriptor *mask = nullptr,
    const std::int64_t *identity = nullptr, bool ordered = true);

void RTDECL(ReduceChar1)(char *result, const Descriptor &array,
    ReductionCharOperation<char>, const char *source, int line, int dim = 0,
    const Descriptor *mask = nullptr, const char *identity = nullptr,
    bool ordered = true);
void RTDECL(ReduceCharacter1Dim)(Descriptor &result, const Descriptor &array,
    ReductionCharOperation<char>, const char *source, int line, int dim,
    const Descriptor *mask = nullptr, const char *identity = nullptr,
    bool ordered = true);
void RTDECL(ReduceChar2)(char16_t *result, const Descriptor &array,
    ReductionCharOperation<char16_t>, const char *source, int line, int dim = 0,
    const Descriptor *mask = nullptr, const char16_t *identity = nullptr,
    bool ordered = true);
void RTDECL(ReduceCharacter2Dim)(Descriptor &result, const Descriptor &array,
    ReductionCharOperation<char16_t>, const char *source, int line, int dim,
    const Descriptor *mask = nullptr, const char16_t *identity = nullptr,
    bool ordered = true);
void RTDECL(ReduceChar4)(char32_t *result, const Descriptor &array,
    ReductionCharOperation<char32_t>, const char *source, int line, int dim = 0,
    const Descriptor *mask = nullptr, const char32_t *identity = nullptr,
    bool ordered = true);
void RTDECL(ReduceCharacter4Dim)(Descriptor &result, const Descriptor &array,
    ReductionCharOperation<char32_t>, const char *source, int line, int dim,
    const Descriptor *mask = nullptr, const char32_t *identity = nullptr,
    bool ordered = true);

void RTDECL(ReduceDerivedType)(char *result, const Descriptor &array,
    ReductionDerivedTypeOperation, const char *source, int line, int dim = 0,
    const Descriptor *mask = nullptr, const char *identity = nullptr,
    bool ordered = true);
void RTDECL(ReduceDerivedTypeDim)(Descriptor &result, const Descriptor &array,
    ReductionDerivedTypeOperation, const char *source, int line, int dim,
    const Descriptor *mask = nullptr, const char *identity = nullptr,
    bool ordered = true);

} // extern "C"
} // namespace Fortran::runtime
#endif // FORTRAN_RUNTIME_REDUCE_H_
