#include "php_sample.h"

#define SAMPLE_NS "sample"

/*
  1. a name for the interface
*/
#define PHP_SAMPLE_INTERFACE_NAME "SampleInterface"

/*
  2. a variable for the entry in the class list
  (Yes, interfaces are stored in the same list.)
*/
static zend_class_entry *php_sample_interface_entry;

/*
  3. a function list for the methods
*/
const zend_function_entry php_sample_interface_functions[] = {
  PHP_ABSTRACT_ME(sample_Interface, sampleMethod, NULL)
  PHP_FE_END
};

PHP_MINIT_FUNCTION(sample)
{
    /*
      4. Initialize and register the interface
    */
    zend_class_entry ce;
    INIT_NS_CLASS_ENTRY(
      ce, SAMPLE_NS, PHP_SAMPLE_INTERFACE_NAME, php_sample_interface_functions
    );
    php_sample_interface_entry = zend_register_internal_interface(&ce TSRMLS_CC);
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
