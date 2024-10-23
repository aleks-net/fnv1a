# FNV1a

A simple single header solution to hashing with Fowler-Noll-Vo in C/C++.

Available with run-time and compile-time functions.

Supporting platforms such as Windows, macOS, and Linux.

## Usage

Just `#include "fnv1a32.h"` or `#include "fnv1a64.h"` in your code!

## 32-Bit usage

### fnv1a32

```c
uint32_t fnv1a32(const char *buf, uint32_t len);
```

- `buf` - a buffer to UTF-8 C string or data.
- `len` - the size to hash.

Returns a `uint32_t` fnv1a 32-Bit hash.

### fnv1a32_str

```c
uint32_t fnv1a32_str(const char* str);
```

- `str` - a UTF-8 C string.

Returns a `uint32_t` fnv1a 32-Bit hash.

### fnv1a32_str C++ only

```c
uint32_t fnv1a32_str(const std::string& str);
```

- `str` - a UTF-8 C++ string.

Returns a `uint32_t` fnv1a 32-Bit hash.

### FNV1A32 compile-time C++ only

```c
uint32_t FNV1A32(str);
```

- `str` - a UTF-8 C/C++ string.

Returns a `uint32_t` fnv1a 32-Bit hash.

## 64-Bit usage

### fnv1a64

```c
uint64_t fnv1a64(const char *buf, uint32_t len);
```

- `buf` - a buffer to UTF-8 C string or data.
- `len` - the size to hash.

Returns a `uint64_t` fnv1a 64-Bit hash.

### fnv1a64_str

```c
uint64_t fnv1a64_str(const char* str);
```

- `str` - a UTF-8 C string.

Returns a `uint64_t` fnv1a 64-Bit hash.

### fnv1a64_str C++ only

```c
uint64_t fnv1a64_str(const std::string& str);
```

- `str` - a UTF-8 C++ string.

Returns a `uint64_t` fnv1a 64-Bit hash.

### FNV1A64 compile-time C++ only

```c
uint64_t FNV1A64(str);
```

- `str` - a UTF-8 C/C++ string.

Returns a `uint64_t` fnv1a 64-Bit hash.

## Examples

# C

```c
#include <stdio.h>

#include "../fnv1a32.h"
#include "../fnv1a64.h"

int main(int argc, char* argv[]) {
	printf("C Example\n");

	printf("fnv1a32_str( \"aleks-net\" ) returns %08x\n", fnv1a32_str("aleks-net"));
	printf("fnv1a64_str( \"aleks-net\" ) returns %016llx\n", fnv1a64_str("aleks-net"));

	return 0;
}
```

# C++
```c++
#include <iostream>

#include "../fnv1a32.h"
#include "../fnv1a64.h"

int main(int argc, char* argv[]) {
	std::cout << "C++ Example" << std::endl;

	// run-time
	std::cout << "run-time" << std::endl;
	std::cout << "fnv1a32_str( \"aleks-net\" ) returns " << std::hex << fnv1a32_str("aleks-net") << std::endl;
	std::cout << "fnv1a64_str( \"aleks-net\" ) returns " << std::hex << fnv1a64_str("aleks-net") << std::endl;


	// compile-time
	std::cout << "compile-time" << std::endl;
	std::cout << "fnv1a32_str( \"aleks-net\" ) returns " << std::hex << FNV1A32("aleks-net") << std::endl;
	std::cout << "fnv1a64_str( \"aleks-net\" ) returns " << std::hex << FNV1A64("aleks-net") << std::endl;

	// example compile-time use case
	uint64_t hash = FNV1A64("D");
	switch (hash) {
		case FNV1A64( "A"):
			std::cout << "option A" << std::endl;
			break;

		case FNV1A64("B"):
			std::cout << "option B" << std::endl;
			break;

		case FNV1A64("C"):
			std::cout << "option C" << std::endl;
			break;

		case FNV1A64("D"):
			std::cout << "option D" << std::endl;
			break;

		case FNV1A64("E"):
			std::cout << "option E" << std::endl;
			break;
	}

	return 0;
}
```