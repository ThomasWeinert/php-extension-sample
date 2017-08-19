#include "php_sample.h"
/*
   1. include helper function to call functions
 */
#include "Zend/zend_interfaces.h"

#define SAMPLE_NS "sample"
#define PHP_SAMPLE_CLASS_GREETING_NAME "Greeting"

static zend_class_entry *php_sample_greeting_class_entry;

PHP_FUNCTION(sample_getGreeting)
{
	zval name;
	/*
	  2. initialize return_value variable as an object using
		 the zend class entry
	 */
	object_init_ex(return_value, php_sample_greeting_class_entry);

	ZVAL_STRINGL(&name, "Universe", strlen("Universe"));

	/*
	  3. call constructor on that object, providing the argument
	*/
    zend_call_method_with_1_params(
		return_value,
		php_sample_greeting_class_entry,
		&php_sample_greeting_class_entry->constructor,
		"__construct",
		NULL,
		&name
	);

	zval_ptr_dtor(&name);
}

const zend_function_entry php_sample_functions[] = {
	ZEND_NS_NAMED_FE(PHP_SAMPLE_EXT_NS, getGreeting, ZEND_FN(sample_getGreeting), NULL)
	PHP_FE_END
};

PHP_METHOD(sample_Greeting, __construct) {
	zval *object;
	char *name;
	size_t name_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(name, name_len)
	ZEND_PARSE_PARAMETERS_END();

	object = getThis();
	zend_update_property_stringl(
		php_sample_greeting_class_entry,
		object,
		ZEND_STRL("name"),
		name,
		name_len
	);
}

PHP_METHOD(sample_Greeting, hello) {
	zval rv, *name, tmp;

	name = zend_read_property(php_sample_greeting_class_entry, getThis(), ZEND_STRL("name"), 0, &rv);

	ZVAL_COPY(&tmp, name);
	convert_to_string(&tmp);

	php_printf("Hello %s!", Z_STRVAL(tmp));
}

const zend_function_entry php_sample_greeting_class_functions[] = {
	PHP_ME(sample_Greeting, __construct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
	PHP_ME(sample_Greeting, hello, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

PHP_MINIT_FUNCTION(sample)
{
	zend_class_entry ce;
	INIT_NS_CLASS_ENTRY(
		ce, PHP_SAMPLE_EXT_NS, PHP_SAMPLE_CLASS_GREETING_NAME, php_sample_greeting_class_functions
	);
	php_sample_greeting_class_entry = zend_register_internal_class(&ce TSRMLS_CC);
	zend_declare_property_stringl(
		php_sample_greeting_class_entry, ZEND_STRL("name"), ZEND_STRL("World"), ZEND_ACC_PUBLIC
	);
}

zend_module_entry sample_module_entry = {
	STANDARD_MODULE_HEADER,
	PHP_SAMPLE_EXT_NAME,
	php_sample_functions, /* Functions */
	PHP_MINIT(sample), /* MINIT */
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
