/* Sample program */
sizeof(char) == 1
sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)

// FROM @KTC. The C++ standard also has:
sizeof(signed char)   == 1
sizeof(unsigned char) == 1

// NOTE: These size are not specified explicitly in the standard.
//       They are implied by the minimum/maximum values that MUST be supported
//       for the type. These limits are defined in limits.h
sizeof(short)     * CHAR_BIT >= 16
sizeof(int)       * CHAR_BIT >= 16
sizeof(long)      * CHAR_BIT >= 32
sizeof(long long) * CHAR_BIT >= 64
CHAR_BIT         >= 8   // Number of bits in a byte
