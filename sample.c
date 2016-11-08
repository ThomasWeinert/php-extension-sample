#include "php_sample.h"

#define SAMPLE_NS "sample"

PHP_FUNCTION(sample_getGreetings)
{
    HashTable *names;
    zval greetings, *name;

    ZEND_PARSE_PARAMETERS_START(1, 1)
    	Z_PARAM_ARRAY_HT(names)
    ZEND_PARSE_PARAMETERS_END();

    /*
      1. initialize an array for the result
    */
    array_init(&greetings);

    ZEND_HASH_FOREACH_VAL(names, name) {
        convert_to_string(name);
        zend_string *greeting = strpprintf(0, "Hello %s!", Z_STRVAL_P(name));

        /*
          2. add greeting to list
        */
        add_next_index_str(&greetings, greeting);
    } ZEND_HASH_FOREACH_END();

    /*
     3. return the hastable with the greetings
    */
    RETURN_ARR(Z_ARRVAL(greetings));

    /*
     4. cleanup the array
    */
    array_free(&greetings);
}

const zend_function_entry php_sample_functions[] = {
  ZEND_NS_NAMED_FE(SAMPLE_NS, getGreetings, ZEND_FN(sample_getGreetings), NULL)
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
