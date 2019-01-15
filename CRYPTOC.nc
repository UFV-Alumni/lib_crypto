configuration CRYPTO {
  provides interface CRYPTO;
}
implementation {
  components CRYPTOP;
  CRYPTO = CRYPTOP;
}