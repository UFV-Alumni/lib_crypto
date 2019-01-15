#include "CRYPTO.h"
interface CRYPTO {
	async command tea_decrypt( uint8_t v0, uint8_t v1);
  	async command tea_encrypt( uint8_t v0, uint8_t v1);

	async command xxtea_encrypt(uint8_t *data, uint8_t data_len);												// ok saida igual clion 				****OK
  	async command xxtea_decrypt(uint8_t *data, uint8_t data_len);

	async command rc4_encrypt(uint8_t *data, uint8_t data_len);													// ok saida igual clion 				****OK
	async command rc4_decrypt(uint8_t *data, uint8_t data_len);
 
  	async command xtea_encrypt(const void *pt, void *ct, uint32_t *skey);										// ok saida igual clion 				****OK
  	async command xtea_decrypt(const void *ct, void *pt, uint32_t *skey);

	async command skipjack_setup(const unsigned char *key, int keylen, int num_rounds, skipjack_key *skey);		// ok saida igual clion 				****OK
	async command skipjack_encrypt(const unsigned char *pt, unsigned char *ct, skipjack_key *skey);
	async command skipjack_decrypt(const unsigned char *ct, unsigned char *pt, skipjack_key *skey);
	async command skipjack_done(skipjack_key *skey);

	async command rc2_setup(const unsigned char *key, int keylen, int num_rounds, rc2_key *skey);				// ok saida igual clion 				****OK
	async command rc2_encrypt( const unsigned char *pt, unsigned char *ct, const rc2_key *skey);
	async command rc2_decrypt( const unsigned char *ct, unsigned char *pt, const rc2_key *skey);
	async command rc2_done(rc2_key *skey);

	async command safer_setup(const unsigned char *key, int keylen, int numrounds, safer_key *skey);			//ok saida diferente clion   			XXXXXXX
	async command safer_encrypt(const unsigned char *block_in, unsigned char *block_out, safer_key *skey);
	async command safer_decrypt(const unsigned char *block_in, unsigned char *block_out, safer_key *skey);
	async command safer_done(safer_key *skey);

	async command rc5_setup(void *key, uint16_t keysize_b, uint8_t rounds, rc5_key *ctx);						// ok saida diferente clion     	****Diferente
	async command rc5_encrypt(void *pt, void *ct, const rc5_key *ctx);
	async command rc5_decrypt(void *ct,void *pt, const rc5_key *ctx);
	async command rc5_done(rc5_key *ctx);

	async command kasumi_setup(const unsigned char *key, int keylen, int num_rounds, kasumi_key *skey);
	async command kasumi_encrypt(const unsigned char *pt, unsigned char *ct, kasumi_key *skey);
	async command kasumi_decrypt(const unsigned char *ct, unsigned char *pt, kasumi_key *skey);
	async command kasumi_done(kasumi_key *skey);

	async command blowfish_setup(const unsigned char *key, int keylen, int num_rounds, blowfish_key *skey);		// problema em criptografar a chave no setup
	async command blowfish_encrypt(const unsigned char *pt, unsigned char *ct, const blowfish_key *skey) ;
	async command blowfish_decrypt(const unsigned char *ct, unsigned char *pt, const blowfish_key *skey);
	async command blowfish_done(blowfish_key *skey);

	async command lsb( uint16_t data);
	async command msb( uint16_t data);
}