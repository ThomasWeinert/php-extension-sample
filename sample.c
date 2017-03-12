#include "php_sample.h"

/*
 1. define the arguments *_EX allows to define the number of required arguments in the third parameter

 ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO(name, type, class_name, allow_null)
 ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(name, return_reference, required_num_args, type, class_name, allow_null)
 */
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(ArgInfo_sample_multiply, 0, 1, IS_LONG, NULL, 0)
	ZEND_ARG_TYPE_INFO(0, first, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, second, IS_LONG, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(sample_multiply)
{
	zend_long first;
	zend_long second = 1;

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_LONG(first)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(second)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(first * second);
}

const zend_function_entry php_sample_functions[] = {
	/*
	 2. provide the argument info in the function registration
	 */
	ZEND_NS_NAMED_FE(PHP_SAMPLE_EXT_NS, multiply, ZEND_FN(sample_multiply), ArgInfo_sample_multiply)
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
