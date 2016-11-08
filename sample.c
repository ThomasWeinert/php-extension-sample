#include "php_sample.h"

#define SAMPLE_NS "sample"

PHP_FUNCTION(sample_getGreetingParts)
{
    array_init(return_value);

    /*
     2. add elements with named key
    */
    add_assoc_str(return_value, "greeting", zend_string_init("Hello %s!", strlen("Hello %s!"), 0));
    add_assoc_str(return_value, "who", zend_string_init("World", strlen("World"), 0));
}

const zend_function_entry php_sample_functions[] = {
    ZEND_NS_NAMED_FE(SAMPLE_NS, getGreetingParts, ZEND_FN(sample_getGreetingParts), NULL)
    PHP_FE_END
};

zend_module_entry sample_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_SAMPLE_EXTNAME,
    php_sample_functions, /* Functions */
    NULL, /* MINIT */
    NULL, /* MSHUTDOWN */
    NULL, /* RINIT */
    NULL, /* RSHUTDOWN */
    NULL, /* MINFO */
    PHP_SAMPLE_EXTVER,
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_SAMPLE
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(sample)
#endif
