#include "php_sample.h"

#define SAMPLE_NS "sample"

PHP_FUNCTION(sample_hello_names)
{
  /*
    1. define variables for the array
  */
  HashTable *names;

  /*
    2. parse parameters using FAST ZPP Api
    https://wiki.php.net/rfc/fast_zpp
   */
  ZEND_PARSE_PARAMETERS_START(1, 1)
  	Z_PARAM_ARRAY_HT(names)
  ZEND_PARSE_PARAMETERS_END();

  /*
    3. use zend_hash_* functions to iterate the array
   */
  for (
      zend_hash_internal_pointer_reset(names);
      zend_hash_has_more_elements(names) == SUCCESS;
      zend_hash_move_forward(names)
  ) {
    zval *entry, tmpcopy;

    /*
      4. fetch current element data
    */
    if ((entry = zend_hash_get_current_data(names)) != NULL) {

      /*
        5. copy the data variable to keep the original from being modified
      */
      ZVAL_COPY(&tmpcopy, entry);

      /*
        6. convert and output
       */
      convert_to_string(&tmpcopy);
      php_printf("Hello %s!\n", Z_STRVAL(tmpcopy));
    }
  }
}

const zend_function_entry php_sample_functions[] = {
  ZEND_NS_NAMED_FE(SAMPLE_NS, hello, ZEND_FN(sample_hello_names), NULL)
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
