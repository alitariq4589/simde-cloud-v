/* SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright:
 *   2021      Evan Nemerson <evan@nemerson.com>
 */

#if !defined(SIMDE_ARM_SVE_WHILELT_H)
#define SIMDE_ARM_SVE_WHILELT_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS

SIMDE_FUNCTION_ATTRIBUTES
simde_svbool_t
simde_svwhilelt_b8_s32(int32_t op1, int32_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svwhilelt_b8_s32(op1, op2);
  #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
    if (HEDLEY_UNLIKELY(op1 >= op2))
      return simde_svbool_from_mmask64(HEDLEY_STATIC_CAST(__mmask64, 0));

    int_fast32_t remaining = (op2 - op1);
    __mmask64 r = ~HEDLEY_STATIC_CAST(__mmask64, 0);
    if (remaining < 64) {
      r >>= 64 - remaining;
    }

    return simde_svbool_from_mmask64(r);
  #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    if (HEDLEY_UNLIKELY(op1 >= op2))
      return simde_svbool_from_mmask32(HEDLEY_STATIC_CAST(__mmask32, 0));

    int_fast32_t remaining = (op2 - op1);
    __mmask32 r = HEDLEY_STATIC_CAST(__mmask32, ~UINT32_C(0));
    if (remaining < 32) {
      r >>= 32 - remaining;
    }

    return simde_svbool_from_mmask32(r);
  #else
    simde_svint8_t r;

    int_fast32_t remaining = (op2 - op1);
    if (op1 >= op2)
      remaining = 0;

    SIMDE_VECTORIZE
    for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, simde_svcntb()) ; i++) {
      r.values[i] = (remaining-- > 0) ? ~UINT8_C(0) : UINT8_C(0);
    }

    return simde_svbool_from_svint8(r);
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svwhilelt_b8_s32
  #define svwhilelt_b8_s32(op1, op2) simde_svwhilelt_b8_s32(op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svbool_t
simde_svwhilelt_b16_s32(int32_t op1, int32_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svwhilelt_b16_s32(op1, op2);
  #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
    if (HEDLEY_UNLIKELY(op1 >= op2))
      return simde_svbool_from_mmask32(HEDLEY_STATIC_CAST(__mmask32, 0));

    int_fast32_t remaining = (op2 - op1);
    __mmask32 r = HEDLEY_STATIC_CAST(__mmask32, ~UINT32_C(0));
    if (remaining < 32) {
      r >>= 32 - remaining;
    }

    return simde_svbool_from_mmask32(r);
  #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    if (HEDLEY_UNLIKELY(op1 >= op2))
      return simde_svbool_from_mmask16(HEDLEY_STATIC_CAST(__mmask16, 0));

    int_fast32_t remaining = (op2 - op1);
    __mmask16 r = HEDLEY_STATIC_CAST(__mmask16, ~UINT16_C(0));
    if (remaining < 16) {
      r >>= 16 - remaining;
    }

    return simde_svbool_from_mmask16(r);
  #else
    simde_svint16_t r;

    int_fast32_t remaining = (op2 - op1);
    if (op1 >= op2)
      remaining = 0;

    SIMDE_VECTORIZE
    for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, simde_svcnth()) ; i++) {
      r.values[i] = (remaining-- > 0) ? ~UINT16_C(0) : UINT16_C(0);
    }

    return simde_svbool_from_svint16(r);
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svwhilelt_b16_s32
  #define svwhilelt_b16_s32(op1, op2) simde_svwhilelt_b16_s32(op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svbool_t
simde_svwhilelt_b32_s32(int32_t op1, int32_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svwhilelt_b32_s32(op1, op2);
  #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
    if (HEDLEY_UNLIKELY(op1 >= op2))
      return simde_svbool_from_mmask16(HEDLEY_STATIC_CAST(__mmask16, 0));

    int_fast32_t remaining = (op2 - op1);
    __mmask16 r = HEDLEY_STATIC_CAST(__mmask16, ~UINT16_C(0));
    if (remaining < 16) {
      r >>= 16 - remaining;
    }

    return simde_svbool_from_mmask16(r);
  #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    if (HEDLEY_UNLIKELY(op1 >= op2))
      return simde_svbool_from_mmask8(HEDLEY_STATIC_CAST(__mmask8, 0));

    int_fast32_t remaining = (op2 - op1);
    __mmask8 r = HEDLEY_STATIC_CAST(__mmask8, ~UINT8_C(0));
    if (remaining < 8) {
      r >>= 8 - remaining;
    }

    return simde_svbool_from_mmask8(r);
  #else
    simde_svint32_t r;

    int_fast32_t remaining = (op2 - op1);
    if (op1 >= op2)
      remaining = 0;

    SIMDE_VECTORIZE
    for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, simde_svcntw()) ; i++) {
      r.values[i] = (remaining-- > 0) ? ~INT32_C(0) : INT32_C(0);
    }

    return simde_svbool_from_svint32(r);
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svwhilelt_b32_s32
  #define svwhilelt_b32_s32(op1, op2) simde_svwhilelt_b32_s32(op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svbool_t
simde_svwhilelt_b64_s32(int32_t op1, int32_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svwhilelt_b64_s32(op1, op2);
  #elif defined(SIMDE_X86_AVX512BW_NATIVE)
    if (HEDLEY_UNLIKELY(op1 >= op2))
      return simde_svbool_from_mmask8(HEDLEY_STATIC_CAST(__mmask8, 0));

    int_fast32_t remaining = (op2 - op1);
    __mmask8 r = HEDLEY_STATIC_CAST(__mmask8, ~UINT8_C(0));
    if (remaining < 8) {
      r >>= 8 - remaining;
    }

    return simde_svbool_from_mmask8(r);
  #else
    simde_svint64_t r;

    int_fast32_t remaining = (op2 - op1);
    if (op1 >= op2)
      remaining = 0;

    SIMDE_VECTORIZE
    for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, simde_svcntd()) ; i++) {
      r.values[i] = (remaining-- > 0) ? ~INT64_C(0) : INT64_C(0);
    }

    return simde_svbool_from_svint64(r);
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svwhilelt_b64_s32
  #define svwhilelt_b64_s32(op1, op2) simde_svwhilelt_b64_s32(op1, op2)
#endif

HEDLEY_DIAGNOSTIC_POP

#endif /* SIMDE_ARM_SVE_WHILELT_H */
