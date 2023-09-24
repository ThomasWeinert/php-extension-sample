#include "php_sample.h"

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO(ArgInfo_sample_getGreetings, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(sample_getGreetings)
{
	HashTable *names;
	zval *entry;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY_HT(names)
	ZEND_PARSE_PARAMETERS_END();

	/*
	 1. initialize the return value as an array
	*/
	array_init(return_value);

	ZEND_HASH_FOREACH_VAL(names, entry) {
		zend_string *name = zval_get_string(entry);
		zend_string *greeting = strpprintf(0, "Hello %s!", ZSTR_VAL(name));
		zend_string_release(name);

		/*
		 2. add greeting to list
		 */
		add_next_index_str(return_value, greeting);
	} ZEND_HASH_FOREACH_END();
}

const zend_function_entry php_sample_functions[] = {
	ZEND_NS_NAMED_FE(PHP_SAMPLE_EXT_NS, getGreetings, ZEND_FN(sample_getGreetings), ArgInfo_sample_getGreetings)
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
