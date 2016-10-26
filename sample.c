#include "php_sample.h"

#define SAMPLE_NS "sample"
#define PHP_SAMPLE_SC_NAME "Greeting"

zend_class_entry *php_sample_sc_entry;

/*
 1. Implement the method
*/
PHP_METHOD(sample_Greeting, hello) {
    php_printf("Hello World!");
}

/*
  2. register it in the function list for the class
*/
const zend_function_entry php_sample_sc_functions[] = {
    PHP_ME(sample_Greeting, hello, NULL, ZEND_ACC_PUBLIC)
    { NULL, NULL, NULL }
};

PHP_MINIT_FUNCTION(sample)
{
    zend_class_entry ce;
    INIT_NS_CLASS_ENTRY(
      ce, SAMPLE_NS, PHP_SAMPLE_SC_NAME, php_sample_sc_functions
    );
    php_sample_sc_entry = zend_register_internal_class(&ce TSRMLS_CC);

    return SUCCESS;
}

zend_module_entry sample_module_entry = {
  STANDARD_MODULE_HEADER,
  PHP_SAMPLE_EXTNAME,
  NULL, /* Functions */
  PHP_MINIT(sample), /* MINIT */
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
