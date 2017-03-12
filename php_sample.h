#ifndef PHP_SAMPLE_H
#define PHP_SAMPLE_H

#define PHP_SAMPLE_EXT_NAME  "sample"
#define PHP_SAMPLE_EXT_VERSION  "1.0"
#define PHP_SAMPLE_EXT_NS  "sample"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif /* HAVE_CONFIG_H */

#include "php.h"

#ifdef ZTS
#include "TSRM.h"
#endif

#if defined(ZTS) && defined(COMPILE_DL_SAMPLE)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif /* PHP_SAMPLE_H */
