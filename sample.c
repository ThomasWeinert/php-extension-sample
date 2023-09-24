#include "php_sample.h"

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO(ArgInfo_sample_getGreetingParts, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(sample_getGreetingParts)
{
	/*
	 1. initialize return_value as array
	*/
	array_init(return_value);

	/*
	 2. add elements with named key
	*/
	add_assoc_str(return_value, "greeting", zend_string_init("Hello %s!", strlen("Hello %s!"), 0));
	add_assoc_str(return_value, "who", zend_string_init("World", strlen("World"), 0));
}

const zend_function_entry php_sample_functions[] = {
	ZEND_NS_NAMED_FE(PHP_SAMPLE_EXT_NS, getGreetingParts, ZEND_FN(sample_getGreetingParts), ArgInfo_sample_getGreetingParts)
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
