#include "zend_interfaces.h"
#include "php_sample.h"
#include "sample_arginfo.h"

PHP_FUNCTION(sample_greet)
{
    zval * greeting;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(greeting)
	ZEND_PARSE_PARAMETERS_END();

    zend_call_method_with_0_params(Z_OBJ_P(greeting), NULL, NULL, "do", NULL);
}

const zend_function_entry php_sample_functions[] = {
	ZEND_NS_NAMED_FE(PHP_SAMPLE_EXT_NS, greet, ZEND_FN(sample_greet), arginfo_Sample_greet)
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
