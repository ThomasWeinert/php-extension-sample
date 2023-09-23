#include "php_sample.h"

/*
 1. Define namespace in php_sample.h
*/

/*
 * 2. Define argument information for the function
 */
ZEND_BEGIN_ARG_INFO_EX(arginfo_sample_hello_world, 0, 0, 0)
ZEND_END_ARG_INFO()

/*
 3. Implement the php function
*/
PHP_FUNCTION(sample_hello_world)
{
	php_printf("Hello World!\n");
}

/*
 4. Define a list for your extension functions
*/
const zend_function_entry php_sample_functions[] = {
	/*
	 4. register the function in the namespace
	 */
	ZEND_NS_NAMED_FE(PHP_SAMPLE_EXT_NS, helloWorld, ZEND_FN(sample_hello_world), arginfo_sample_hello_world)
	PHP_FE_END
};

zend_module_entry sample_module_entry = {
	STANDARD_MODULE_HEADER,
	PHP_SAMPLE_EXT_NAME,
	/*
	 5. add the functions to the module entry
	 */
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
