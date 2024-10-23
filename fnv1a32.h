/*
Based on https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function#FNV-1a_hash
Written by Aleks Babkov Yatsenko

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>
*/
#ifndef FNV1A32_H_INCLUDED
#define FNV1A32_H_INCLUDED

#ifdef __cplusplus
#include <cstdint>
#include <string>
#else
#include <stdint.h>
#endif

#define FNV1A32_BASIS 0x811c9dc5
#define FNV1A32_PRIME 0x01000193

#ifdef __cplusplus

/*
* Returns fnv1a 32-Bit hash.
*
* It is NOT safe to pass NULL to this function.
*
* \param buf a buffer to UTF-8 C string or data.
* \param len the size to hash.
*/
static inline constexpr uint32_t fnv1a32(const char *buf, uint32_t len) {
	uint32_t out = FNV1A32_BASIS;

	for (uint32_t i = 0; i < len; i++)
		out = (out ^ buf[i]) * FNV1A32_PRIME;
	
	return out;
}

/*
* Returns fnv1a 32-Bit hash.
*
* It is NOT safe to pass NULL to this function.
*
* \param buf a UTF-8 C string.
*/
static inline constexpr uint32_t fnv1a32_str(const char* str) {
	uint32_t len = 0;

	while (str[len] != '\0')
		len++;

	return fnv1a32(str, len);
}

/*
* Returns fnv1a 32-Bit hash.
*
* \param str a UTF-8 C++ string.
*/
static inline constexpr uint32_t fnv1a32_str(const std::string& str) {
	return fnv1a32(str.c_str(), (uint32_t)str.length());
}

// compile-time function
#define FNV1A32(str) [](){ constexpr uint32_t out{ fnv1a32_str( str ) }; return out; }()

#else

/*
* Returns fnv1a 32-Bit hash.
* 
* It is NOT safe to pass NULL to this function.
* 
* \param buf a buffer to UTF-8 C string or data.
* \param len the size to hash.
*/
static inline const uint32_t fnv1a32(const char* buf, uint32_t len) {
	uint32_t out = FNV1A32_BASIS;

	for (uint32_t i = 0; i < len; i++)
		out = (out ^ buf[i]) * FNV1A32_PRIME;

	return out;
}

/*
* Returns fnv1a 32-Bit hash.
*
* It is NOT safe to pass NULL to this function.
*
* \param buf a UTF-8 C string.
*/
static inline const uint32_t fnv1a32_str(const char* str) {
	uint32_t len = 0;

	while (str[len] != '\0')
		len++;

	return fnv1a32(str, len);
}

#endif

#endif