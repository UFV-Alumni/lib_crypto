#ifndef CRYPTO_H
#define CRYPTO_H

typedef unsigned long long ulong64;
typedef unsigned ulong32;
typedef unsigned u16;
typedef unsigned char safer_key_t[36];
typedef unsigned char safer_block_t[8];

typedef struct symmetric_key_rc2 {
    unsigned xkey[64];
}rc2_key;

typedef struct symmetric_key_blowfish {
    ulong32 s[4][256];
    ulong32 k[18];
}blowfish_key;

typedef struct symmetric_key_xtea {
    unsigned AT[4];
}xtea_key;

typedef struct symmetric_key_des {
    ulong32 ek[32], dk[32];
}des_key;

typedef struct symmetric_key_rc5 {
    uint8_t rounds;
    uint32_t *s;
}rc5_key;

typedef struct symmetric_key_skipjack {
   unsigned char key[10];
}skipjack_key;

typedef struct symmetric_key_safer {
    safer_key_t key;
}safer_key;

typedef  struct symmetric_key_kasumi {
    ulong32 KLi1[8], KLi2[8],
            KOi1[8], KOi2[8], KOi3[8],
            KIi1[8], KIi2[8], KIi3[8];
}kasumi_key;


#define ROL16(x, y) ((((x)<<(y)) | ((x)>>(16-(y)))) & 0xFFFF)

#define Ac (((uint32_t*)pt)[0])
#define Bc (((uint32_t*)pt)[1])
#define Ad (((uint32_t*)ct)[0])
#define Bd (((uint32_t*)ct)[1])

#define ROTL32(v,n) (((v)<<(n))|((v)>>(32-(n))))
#define ROTR32(v,n) (((v)>>(n))|((v)<<(32-(n))))


#define CRYPT_OK 0
#define CRYPT_INVALID_KEYSIZE -1
#define CRYPT_INVALID_ROUNDS -2
#define XMEMCPY memcpy
#define STORE32H(x, y)                          \
do { ulong32 __t = __builtin_bswap32 ((x));     \
      XMEMCPY ((y), &__t, 4); } while(0)

#define LOAD32H(x, y)                           \
do { XMEMCPY (&(x), (y), 4);                    \
      (x) = __builtin_bswap32 ((x)); } while(0)
#define RULE_A                        \
   tmp = g_func(w1, &kp, skey->key);  \
   w1  = tmp ^ w4 ^ x;                \
   w4  = w3; w3 = w2;                 \
   w2  = tmp;

#define RULE_B              \
   tmp  = g_func(w1, &kp, skey->key); \
   tmp1 = w4; w4  = w3;               \
   w3   = w1 ^ w2 ^ x;                \
   w1   = tmp1; w2 = tmp;

#define RULE_A1             \
   tmp = w1 ^ w2 ^ x;                 \
   w1  = ig_func(w2, &kp, skey->key); \
   w2  = w3; w3 = w4; w4 = tmp;

#define RULE_B1             \
   tmp = ig_func(w2, &kp, skey->key); \
   w2  = tmp ^ w3 ^ x;                \
   w3  = w4; w4 = w1; w1 = tmp;

#define NORETURN
#define crypt_argchk(v, s, d) NORETURN
#define LTC_ARGCHK(x) do { if (!(x)) { crypt_argchk(#x, __FILE__, __LINE__); } }while(0)

// safer
#define ROL8(x, n)                    \
((unsigned char)((unsigned int)(x) << (n) | (unsigned int)((x) & 0xFF) >> (8 - (n))))

#define EXP(x)       safer_ebox[(x) & 0xFF]
#define LOG(x)       safer_lbox[(x) & 0xFF]
#define PHT(x, y)    { y += x; x += y; }
#define IPHT(x, y)   { x -= y; y -= x; }
#define LTC_SAFER_K64_DEFAULT_NOF_ROUNDS     6
#define LTC_SAFER_MAX_NOF_ROUNDS            13
#define LTC_SAFER_BLOCK_LEN                  8
#define LTC_SAFER_KEY_LEN     (1 + LTC_SAFER_BLOCK_LEN * (1 + 2 * LTC_SAFER_MAX_NOF_ROUNDS))

#define byte(x, n) (((x) >> (8 * (n))) & 255)
#define F(x) ((skey->s[0][byte(x,3)] + skey->s[1][byte(x,2)]) ^ skey->s[2][byte(x,1)]) + skey->s[3][byte(x,0)]

#endif