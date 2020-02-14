//#include <../../../../external/boringssl/include/openssl/ssl.h>

#define LOG_TAG "SSL_ctrl_stub"
#include <log/log.h>

extern "C" long SSL_ctrl(int *ssl, int cmd, long larg, void *parg) {
    ALOGD("SSL_ctrl: ssl=%p cmd=%d larg=%ld parg=%p", ssl, cmd, larg, parg);
    return -1;
}

extern "C" long SSL_CTX_ctrl(int *ctx, int cmd, long larg, void *parg) {
    ALOGD("SSL_CTX_ctrl: ctx=%p cmd=%d larg=%ld parg=%p", ctx, cmd, larg, parg);
    return -1;
}

extern "C" void CRYPTO_free(void *str) { }

extern "C" void *CRYPTO_malloc(int num, const char *file, int line) {
    ALOGD("CRYPTO_malloc: num=%d file=%s line=%d", num, file, line);
    return 0;
}

extern "C" void CRYPTO_lock(int mode, int type, const char *file, int line) {
    ALOGD("CRYPTO_lock: mode=%d type=%d file=%s line=%d", mode, type, file, line);
}
