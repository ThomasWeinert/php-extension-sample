#include "php_sample.h"
/*
 1. include exception API
 */
#include <zend_exceptions.h>

/*
 2. define a variable for the exception class
 */
zend_class_entry *sample_exception;

/*
 3. implement a function to initialize the exception class
*/
void sample_init_exception() {
	zend_class_entry e;

	INIT_NS_CLASS_ENTRY(e, PHP_SAMPLE_EXT_NS, "ExceptionName", NULL);
	sample_exception = zend_register_internal_class_ex(&e, (zend_class_entry*)zend_exception_get_default());
}

/*
 4. In the module initialization, call the exception class init
 */
PHP_MINIT_FUNCTION(sample)
{
	sample_init_exception();
}

/*
 5. throw the exception
 */
ZEND_BEGIN_ARG_INFO(ArgInfo_sample_trigger_exception, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(sample_trigger_exception)
{
	zend_throw_exception_ex(
		sample_exception, 42, "Sample Exception Message"
	);
}

const zend_function_entry php_sample_functions[] = {
	ZEND_NS_NAMED_FE(PHP_SAMPLE_EXT_NS, triggerException, ZEND_FN(sample_trigger_exception), ArgInfo_sample_trigger_exception)
	PHP_FE_END
};

zend_module_entry sample_module_entry = {
	STANDARD_MODULE_HEADER,
	PHP_SAMPLE_EXT_NAME,
	/*
	 6. add the functions to the module entry
	 */
	php_sample_functions, /* Functions */
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
