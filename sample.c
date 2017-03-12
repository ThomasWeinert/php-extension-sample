#include "php_sample.h"

PHP_FUNCTION(sample_output)
{
	zval *value;

	/*
	 1. fetch the parameter as ZVAL (pointer)
	 */
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();

	/*
	 2. Z_TYPE_P allows you to get the type
	 */
	switch (Z_TYPE_P(value)) {
	/*
	 3. compare it with the IS_* macros
	 */
	case IS_NULL :
		php_printf("NULL");
		break;
	case IS_TRUE :
		php_printf("Boolean: TRUE");
		break;
	case IS_FALSE :
		php_printf("Boolean: FALSE");
		break;
	case IS_LONG :
		convert_to_string(value);
		php_printf("Integer: %s", Z_STRVAL_P(value));
		break;
	case IS_DOUBLE :
		/*
		 4b. Z_*VAL_P() allows you to read the value from the zval
		 */
		php_printf("Float: %f", Z_DVAL_P(value));
		break;
	case IS_STRING :
		php_printf("String: %s", Z_STRVAL_P(value));
		break;
	case IS_RESOURCE :
		php_printf("Resource: #%ld", Z_RESVAL_P(value));
		break;
	case IS_ARRAY :
		php_printf("Array");
		break;
	case IS_OBJECT :
		php_printf("Object");
		break;
	default :
		php_printf("UNKNOWN");
		break;
	}
}

const zend_function_entry php_sample_functions[] = {
	ZEND_NS_NAMED_FE(PHP_SAMPLE_EXT_NS, output, ZEND_FN(sample_output), NULL)
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
