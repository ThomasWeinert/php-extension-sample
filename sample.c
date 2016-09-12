#include "php_sample.h"

/*
  1. define the namespace for your extension
 */
#define SAMPLE_NS "sample"

/*
  2. define it as a template to use in the extension implementation
 */
#define SAMPLE_INT 42

/*
  3. implement a MINIT function
*/
PHP_MINIT_FUNCTION(sample)
{
    /*
       4. register the constant in the namespace
     */
    REGISTER_NS_LONG_CONSTANT(SAMPLE_NS, "SAMPLE_INT", SAMPLE_INT, CONST_CS | CONST_PERSISTENT);
}

zend_module_entry sample_module_entry = {
  STANDARD_MODULE_HEADER,
  PHP_SAMPLE_EXTNAME,
  NULL, /* Functions */
  /*
    5. register the MINIT function for the module
  */
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
