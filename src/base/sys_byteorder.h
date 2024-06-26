// Copyright 2012 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This header defines cross-platform ByteSwap() implementations for 16, 32 and
// 64-bit values, and NetToHostXX() / HostToNextXX() functions equivalent to
// the traditional ntohX() and htonX() functions.
// Use the functions defined here rather than using the platform-specific
// functions directly.

#ifndef BASE_SYS_BYTEORDER_H_
#define BASE_SYS_BYTEORDER_H_

#include <stdint.h>

#include "base/numerics/byte_conversions.h"
#include "build/build_config.h"

#if defined(COMPILER_MSVC)
#include <stdlib.h>
#endif

namespace base {

// Returns a value with all bytes in |x| swapped, i.e. reverses the endianness.
// TODO(danakj): Replace with base::numerics::byteswap().
inline constexpr uint16_t ByteSwap(uint16_t x) {
  // Forward to templated function in //base/numerics.
  return numerics::ByteSwap(x);
}

inline constexpr uint32_t ByteSwap(uint32_t x) {
  // Forward to templated function in //base/numerics.
  return numerics::ByteSwap(x);
}

inline constexpr uint64_t ByteSwap(uint64_t x) {
  // Forward to templated function in //base/numerics.
  return numerics::ByteSwap(x);
}

inline constexpr uintptr_t ByteSwapUintPtrT(uintptr_t x) {
  // Forward to templated function in //base/numerics.
  return numerics::ByteSwap(x);
}

// Converts the bytes in |x| from host order (endianness) to little endian, and
// returns the result.
inline constexpr uint16_t ByteSwapToLE16(uint16_t x) {
#if defined(ARCH_CPU_LITTLE_ENDIAN)
  return x;
#else
  return numerics::ByteSwap(x);
#endif
}
inline constexpr uint32_t ByteSwapToLE32(uint32_t x) {
#if defined(ARCH_CPU_LITTLE_ENDIAN)
  return x;
#else
  return numerics::ByteSwap(x);
#endif
}
inline constexpr uint64_t ByteSwapToLE64(uint64_t x) {
#if defined(ARCH_CPU_LITTLE_ENDIAN)
  return x;
#else
  return numerics::ByteSwap(x);
#endif
}

// Converts the bytes in |x| from network to host order (endianness), and
// returns the result.
inline constexpr uint16_t NetToHost16(uint16_t x) {
#if defined(ARCH_CPU_LITTLE_ENDIAN)
  return numerics::ByteSwap(x);
#else
  return x;
#endif
}
inline constexpr uint32_t NetToHost32(uint32_t x) {
#if defined(ARCH_CPU_LITTLE_ENDIAN)
  return numerics::ByteSwap(x);
#else
  return x;
#endif
}
inline constexpr uint64_t NetToHost64(uint64_t x) {
#if defined(ARCH_CPU_LITTLE_ENDIAN)
  return numerics::ByteSwap(x);
#else
  return x;
#endif
}

// Converts the bytes in |x| from host to network order (endianness), and
// returns the result.
inline constexpr uint16_t HostToNet16(uint16_t x) {
#if defined(ARCH_CPU_LITTLE_ENDIAN)
  return numerics::ByteSwap(x);
#else
  return x;
#endif
}
inline constexpr uint32_t HostToNet32(uint32_t x) {
#if defined(ARCH_CPU_LITTLE_ENDIAN)
  return numerics::ByteSwap(x);
#else
  return x;
#endif
}
inline constexpr uint64_t HostToNet64(uint64_t x) {
#if defined(ARCH_CPU_LITTLE_ENDIAN)
  return numerics::ByteSwap(x);
#else
  return x;
#endif
}

}  // namespace base

#undef constexpr

#endif  // BASE_SYS_BYTEORDER_H_
