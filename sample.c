#include "php_sample.h"

/*
 1. define the resource struct in php_sample.h
 */

/*
 2. define a name for the resource name and a variable for the list entry
 */
#define SAMPLE_RESOURCE_NAME "sample_resource"
int le_sample_resource;

/*
 3. implement a destructor for the resource
*/
static void sample_resource_dtor(zend_resource *rsrc)
{
	sample_resource *r = (sample_resource*)rsrc->ptr;

	if (r) {
		efree(r);
	}
}

/*
 4. implement a php function that creates the resource
 */
PHP_FUNCTION(sample_create_resource)
{
	sample_resource *r;
	r = emalloc(sizeof(sample_resource));
	r->number = 42;
	RETURN_RES(zend_register_resource(r, le_sample_resource));
}

/*
 6. Make use of the resource
 */
PHP_FUNCTION(sample_use_resource)
{
	sample_resource *r;
	zval *zr;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_RESOURCE(zr)
	ZEND_PARSE_PARAMETERS_END();

	r = (sample_resource *)zend_fetch_resource(Z_RES_P(zr), SAMPLE_RESOURCE_NAME, le_sample_resource);

	php_printf("Number: %ld", r->number);
}

PHP_MINIT_FUNCTION(sample)
{
	/*
	 5. register the resource
	 */
	le_sample_resource = zend_register_list_destructors_ex(sample_resource_dtor, NULL, SAMPLE_RESOURCE_NAME, module_number);
}

const zend_function_entry php_sample_functions[] = {
	ZEND_NS_NAMED_FE(PHP_SAMPLE_EXT_NS, createResource, ZEND_FN(sample_create_resource), NULL)
	ZEND_NS_NAMED_FE(PHP_SAMPLE_EXT_NS, useResource, ZEND_FN(sample_use_resource), NULL)
	PHP_FE_END
};

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
