#include "php_sample.h"
#include "ext/json/php_json.h"

#define SAMPLE_NS "sample"
#define PHP_SAMPLE_CLASS_NAME "HelloWorld"

static zend_class_entry *php_sample_class_entry;

/*
 2. Implement and register the method from the interface,
   otherwise the class will be abstract
*/
PHP_METHOD(sample_Class, jsonSerialize) {
    zval array;

    array_init(&array);

    add_assoc_str(&array, "greeting", zend_string_init(ZEND_STRL("Hello World!"), 0));
    add_assoc_long(&array, "answer", 42);

    RETURN_ARR(Z_ARRVAL(array));
    array_free(&array);
}

const zend_function_entry php_sample_class_functions[] = {
    PHP_ME(sample_Class, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_MINIT_FUNCTION(sample)
{
    zend_class_entry ce;
    INIT_NS_CLASS_ENTRY(
      ce, SAMPLE_NS, PHP_SAMPLE_CLASS_NAME, php_sample_class_functions
    );
    php_sample_class_entry = zend_register_internal_class(&ce TSRMLS_CC);
    /*
     1. define the interfaces implemented by the class the interfaces are a variadic argument
     */
    zend_class_implements(php_sample_class_entry, 1, php_json_serializable_ce);
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
