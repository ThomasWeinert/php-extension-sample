#include "php_sample.h"

#define SAMPLE_NS "sample"

/*
  1. a name for the class
*/
#define PHP_SAMPLE_CLASS_NAME "SampleClass"

/*
  2. a variable for the entry in the class list
*/
static zend_class_entry *php_sample_class_entry;

/*
  3. a function list for the methods
*/
const zend_function_entry php_sample_class_functions[] = {
  PHP_FE_END
};

PHP_MINIT_FUNCTION(sample)
{
    /*
      4. Initialize and register the class
    */
    zend_class_entry ce;
    INIT_NS_CLASS_ENTRY(
      ce, SAMPLE_NS, PHP_SAMPLE_CLASS_NAME, php_sample_class_functions
    );
    php_sample_class_entry = zend_register_internal_class(&ce TSRMLS_CC);
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
