#include "php_sample.h"

PHP_FUNCTION(sample_hello_name)
{
	/*
	 1. define variables for string value and length
	 */
	char *name;
	size_t name_len;

	/*
	 2. parse parameters using FAST ZPP Api
	 https://wiki.php.net/rfc/fast_zpp
	 */
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(name, name_len)
	ZEND_PARSE_PARAMETERS_END();

	php_printf("Hello ");
	PHPWRITE(name, name_len);
	php_printf("!\n");
}

const zend_function_entry php_sample_functions[] = {
	ZEND_NS_NAMED_FE(PHP_SAMPLE_EXT_NS, hello, ZEND_FN(sample_hello_name), NULL)
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
