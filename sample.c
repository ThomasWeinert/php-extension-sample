#include "php_sample.h"

PHP_FUNCTION(sample_hello_names)
{
	/*
	1. define variables for the array
	*/
	zval *args;
	int argc, i;

	/*
	2. parse parameters using FAST ZPP Api
		https://wiki.php.net/rfc/fast_zpp
	*/
	ZEND_PARSE_PARAMETERS_START(1, -1)
		Z_PARAM_VARIADIC('+', args, argc)
	ZEND_PARSE_PARAMETERS_END();

	/*
	3. Iterate the arguments
	*/
	for (i = 0; i < argc; i++) {
		zval *arg = args + i;

		convert_to_string(arg);
		php_printf("Hello %s!\n", Z_STRVAL_P(arg));
	}
}

const zend_function_entry php_sample_functions[] = {
	ZEND_NS_NAMED_FE(PHP_SAMPLE_EXT_NS, hello, ZEND_FN(sample_hello_names), NULL)
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
