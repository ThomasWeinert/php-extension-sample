#include "php_sample.h"

/*
 1. & 2. see php_sample.h
*/

/*
 3. Declare global module variables
 */
ZEND_DECLARE_MODULE_GLOBALS(sample)


ZEND_BEGIN_ARG_INFO(ArgInfo_sample_get_value, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(sample_get_value)
{
    /*
     6. get the current value
     */
    long value;
    value = SAMPLE_G(sample_value);

	php_printf("Current value: %ld\n", value);

    /*
     7. set the value
     */
	SAMPLE_G(sample_value) = (value == 42) ? 21 : 42;
}

/*
 4. Add a request initialization function, you might need a
 request shutdown function for more complex variables.
 */
PHP_RINIT_FUNCTION(sample)
{
	SAMPLE_G(sample_value) = 21;
}

const zend_function_entry php_sample_functions[] = {
	ZEND_NS_NAMED_FE(PHP_SAMPLE_EXT_NS, getValue, ZEND_FN(sample_get_value), ArgInfo_sample_get_value)
	PHP_FE_END
};

zend_module_entry sample_module_entry = {
	STANDARD_MODULE_HEADER,
	PHP_SAMPLE_EXT_NAME,
	php_sample_functions, /* Functions */
	NULL, /* MINIT */
	NULL, /* MSHUTDOWN */
	/*
	 5. add request initialization function to the module entry
	 */
	PHP_RINIT(sample), /* RINIT */
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
