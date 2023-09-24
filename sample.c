#include "php_sample.h"

ZEND_BEGIN_ARG_INFO(ArgInfo_sample_answer, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(sample_answer)
{
	/*
	  1. initialize return_value variable as an stdClass using
		 the zend class entry
	 */
	object_init_ex(return_value, zend_standard_class_def);

	/*
	  2. update the property
	 */
	zend_update_property_stringl(
		zend_standard_class_def,
		Z_OBJ_P(return_value),
		ZEND_STRL("greeting"),
		ZEND_STRL("Hello World!")
	);
}

const zend_function_entry php_sample_functions[] = {
	ZEND_NS_NAMED_FE(PHP_SAMPLE_EXT_NS, answer, ZEND_FN(sample_answer), ArgInfo_sample_answer)
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
