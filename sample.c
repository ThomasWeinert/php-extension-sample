#include "php_sample.h"

/*
	1. Implement MINFO function
 */
PHP_MINFO_FUNCTION(sample)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "sample support", "enabled");
	php_info_print_table_row(2, "1.", "Basic extension");
	php_info_print_table_end();
}

zend_module_entry sample_module_entry = {
	STANDARD_MODULE_HEADER,
	PHP_SAMPLE_EXT_NAME,
	NULL, /* Functions */
	NULL, /* MINIT */
	NULL, /* MSHUTDOWN */
	NULL, /* RINIT */
	NULL, /* RSHUTDOWN */
	/*
	 2. provide MINFO function
	 */
	PHP_MINFO(sample), /* MINFO */
	PHP_SAMPLE_EXT_VERSION,
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_SAMPLE
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(sample)
#endif
