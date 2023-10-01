#include "php_sample.h"
#include "sample_arginfo.h"


PHP_FUNCTION(sample_hello_callback)
{
	/*
	 1. define variables for function call info and cache
	 */
	zend_fcall_info fci;
	zend_fcall_info_cache fci_cache;

	zval retval;

	ZEND_PARSE_PARAMETERS_START(1, -1)
		/*
		 2. read the callback parameters
		 */
		Z_PARAM_FUNC(fci, fci_cache)
		/*
		 2a. pass additional parameters to the callback
		 */
		Z_PARAM_VARIADIC('*', fci.params, fci.param_count)
	ZEND_PARSE_PARAMETERS_END();

	fci.retval = &retval;

	/*
	 3. Execute the callback
	 */
	if (zend_call_function(&fci, &fci_cache) == SUCCESS && Z_TYPE(retval) != IS_UNDEF) {
		if (Z_ISREF(retval)) {
			zend_unwrap_reference(&retval);
		}

		convert_to_string(&retval);
		php_printf("Hello %s!\n", Z_STRVAL(retval));
	}
}

const zend_function_entry php_sample_functions[] = {
	ZEND_NS_NAMED_FE(PHP_SAMPLE_EXT_NS, hello, ZEND_FN(sample_hello_callback), arginfo_Sample_hello)
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
