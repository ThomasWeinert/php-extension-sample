#include "php_sample.h"

#define PHP_SAMPLE_CLASS_NAME "SampleClass"

static zend_class_entry *php_sample_class_entry;

const zend_function_entry php_sample_class_functions[] = {
	PHP_FE_END
};

PHP_MINIT_FUNCTION(sample)
{
	zend_class_entry ce;
	INIT_NS_CLASS_ENTRY(
		ce, PHP_SAMPLE_EXT_NS, PHP_SAMPLE_CLASS_NAME, php_sample_class_functions
	);
	php_sample_class_entry = zend_register_internal_class(&ce TSRMLS_CC);

	/*
	 1. Declare class constant
	 */
	zend_declare_class_constant_long(php_sample_class_entry, ZEND_STRL("ANSWER"), 42);
}

zend_module_entry sample_module_entry = {
	STANDARD_MODULE_HEADER,
	PHP_SAMPLE_EXT_NAME,
	NULL, /* Functions */
	PHP_MINIT(sample), /* MINIT */
	NULL, /* MSHUTDOWN */
	NULL, /* RINIT */
	NULL, /* RSHUTDOWN */
	NULL, /* MINFO */
	PHP_SAMPLE_EXT_VERSION,
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_SAMPLE
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(sample)
#endif
