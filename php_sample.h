#ifndef PHP_SAMPLE_H
#define PHP_SAMPLE_H

#define PHP_SAMPLE_EXT_NAME  "sample"
#define PHP_SAMPLE_EXT_VERSION   "1.0"

#define PHP_SAMPLE_EXT_NS "Sample"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif /* HAVE_CONFIG_H */

#include "php.h"

/*
 Define/register global module variables
 */
ZEND_BEGIN_MODULE_GLOBALS(sample)
	long sample_value;
ZEND_END_MODULE_GLOBALS(sample)

/*
 Define a template to access the global module variables, suggested
 name is {EXT_NAME}_G
 */
#define SAMPLE_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(sample, v)

#ifdef ZTS
#include "TSRM.h"
#endif

#if defined(ZTS) && defined(COMPILE_DL_SAMPLE)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif /* PHP_SAMPLE_H */
