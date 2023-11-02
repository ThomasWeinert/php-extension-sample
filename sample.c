#include "zend_interfaces.h"
#include "php_sample.h"
#include "sample_arginfo.h"

PHP_FUNCTION(sample_countdown)
{
	zval *target, step;
    zend_long start = 10;

	ZEND_PARSE_PARAMETERS_START(1, 2)
        Z_PARAM_OBJECT(target)
        Z_PARAM_OPTIONAL
        Z_PARAM_LONG(start)
	ZEND_PARSE_PARAMETERS_END();

    /*
     * Cache function reference for repeated calls
     */
    zend_function *zfc = NULL;

    for (int i = start; i > 0; --i) {
        ZVAL_LONG(&step, i);

        zend_call_method_with_1_params(
            Z_OBJ_P(target), NULL, &zfc, "do", NULL, &step
        );

        zval_dtor(&step);
    }

}

const zend_function_entry php_sample_functions[] = {
	ZEND_NS_NAMED_FE(PHP_SAMPLE_EXT_NS, countdown, ZEND_FN(sample_countdown), arginfo_Sample_countdown)
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
