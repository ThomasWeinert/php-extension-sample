#include "php_sample.h"
#include "sample_arginfo.h"

PHP_FUNCTION(sample_multiply)
{
	/*
	 1. define/initialize variables
	 */
	zend_long first;
	zend_long second = 1;

	/*
	 2. parse parameters using FAST ZPP Api
	 https://wiki.php.net/rfc/fast_zpp
	 */
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_LONG(first)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(second)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(first * second);
}

const zend_function_entry php_sample_functions[] = {
	ZEND_NS_NAMED_FE(PHP_SAMPLE_EXT_NS, multiply, ZEND_FN(sample_multiply), arginfo_Sample_multiply)
	PHP_FE_END
};

zend_module_entry sample_module_entry = {
	STANDARD_MODULE_HEADER,
	PHP_SAMPLE_EXT_NAME,
	php_sample_functions, /* Functions */
	NULL, /* MINIT */
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
