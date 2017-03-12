#include "php_sample.h"

PHP_FUNCTION(sample_answer)
{
	/*
	 1. Use a type specific template to return a value
		RETURN_BOOL(b)
		RETURN_NULL()
		RETURN_LONG(l)
		RETURN_DOUBLE(d)
		RETURN_STR(s)
		RETURN_INTERNED_STR(s)
		RETURN_NEW_STR(s)
		RETURN_STR_COPY(s)
		RETURN_STRING(s)
		RETURN_STRINGL(s, l)
		RETURN_EMPTY_STRING()
		RETURN_RES(r)
		RETURN_ARR(r)
		RETURN_OBJ(r)
		RETURN_ZVAL(zv, copy, dtor)
		RETURN_FALSE
		RETURN_TRUE
	 */
	RETURN_LONG(42);
}

const zend_function_entry php_sample_functions[] = {
	ZEND_NS_NAMED_FE(PHP_SAMPLE_EXT_NS, answer, ZEND_FN(sample_answer), NULL)
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
