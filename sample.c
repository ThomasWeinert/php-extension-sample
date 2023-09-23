#include "php_sample.h"

#define PHP_SAMPLE_CLASS_GREETING_NAME "Greeting"

static zend_class_entry *php_sample_greeting_class_entry;

/*
 1. Implement the method
*/
ZEND_BEGIN_ARG_INFO_EX(ArgInfo_sample_Greeting_hello, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(sample_Greeting, hello) {
	php_printf("Hello World!");
}

/*
 2. register it in the function list for the class
*/
const zend_function_entry php_sample_greeting_class_functions[] = {
	PHP_ME(sample_Greeting, hello, ArgInfo_sample_Greeting_hello, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

PHP_MINIT_FUNCTION(sample)
{
	zend_class_entry ce;
	INIT_NS_CLASS_ENTRY(
		ce, PHP_SAMPLE_EXT_NS, PHP_SAMPLE_CLASS_GREETING_NAME, php_sample_greeting_class_functions
	);
	php_sample_greeting_class_entry = zend_register_internal_class(&ce);
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
