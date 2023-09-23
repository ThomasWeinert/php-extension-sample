#include "php_sample.h"


ZEND_BEGIN_ARG_INFO(ArgInfo_sample_greet, 0)
    ZEND_ARG_TYPE_INFO(0, name, IS_OBJECT, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(sample_greet)
{
	zval fname, params[1], *greeting;
	ZVAL_STRING(&fname, "do");
	ZVAL_STRING(&params[0], "World");

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(greeting)
	ZEND_PARSE_PARAMETERS_END();

	call_user_function(
        NULL, greeting, &fname, return_value, 1, params
    );

	zval_dtor(&fname);
	zval_dtor(&params[0]);
}

const zend_function_entry php_sample_functions[] = {
	ZEND_NS_NAMED_FE(PHP_SAMPLE_EXT_NS, greet, ZEND_FN(sample_greet), ArgInfo_sample_greet)
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
