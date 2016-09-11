#ifndef PHP_SAMPLE_H
#define PHP_SAMPLE_H

#define PHP_SAMPLE_EXTNAME  "sample"
#define PHP_SAMPLE_EXTVER   "1.0"

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
