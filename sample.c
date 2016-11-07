#include "php_sample.h"

#define SAMPLE_NS "sample"

PHP_FUNCTION(sample_answer)
{
  HashTable *ht;
  zval array, values[2];

  ZVAL_STRING(&values[0], "Hello %s!");
  ZVAL_STRING(&values[1], "World");

	array_init(&array);
  ht = Z_ARRVAL(array);

  zend_hash_str_add(ht, "greeting", sizeof("greeting")-1, &values[0]);
  zend_hash_str_add(ht, "who", sizeof("who")-1, &values[1]);

  RETURN_ARR(ht);
  array_free(&array);
}

const zend_function_entry php_sample_functions[] = {
  ZEND_NS_NAMED_FE(SAMPLE_NS, answer, ZEND_FN(sample_answer), NULL)
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
