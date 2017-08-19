#include "php_sample.h"

PHP_FUNCTION(sample_answer)
{
	HashTable *properties;

	zend_string *key = zend_string_init("Greeting", strlen("Greeting"), 0);
	zval *element;

	properties = emalloc(sizeof(HashTable));
    zend_hash_init(properties, 0, NULL, ZVAL_PTR_DTOR, 0);

    ZVAL_NEW_STR(&element, zend_string_init("Hello World!", strlen("Hello World!"), 0));
	zend_hash_add_new(properties, key, element);

	object_and_properties_init(return_value, zend_standard_class_def, properties);

	zend_string_release(key);
	zend_hash_destroy(properties);
	efree(properties);
}

const zend_function_entry php_sample_functions[] = {
	ZEND_NS_NAMED_FE(PHP_SAMPLE_EXT_NS, answer, ZEND_FN(sample_answer), NULL)
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
