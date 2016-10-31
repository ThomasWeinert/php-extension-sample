#include "php_sample.h"

#define SAMPLE_NS "sample"
#define PHP_SAMPLE_CLASS_GREETING_NAME "Greeting"

static zend_class_entry *php_sample_greeting_class_entry;

/*
 1. Define a variable for the object handlers
 */
zend_object_handlers php_sample_greeting_handlers;

/*
 2. Define a struct that contains the original zend object and the additional data
*/
typedef struct _php_sample_greeting_t {
	 zval greeting;
	 zend_object std;
} php_sample_greeting_t;

/*
 3. Define templates to fetch the struct from a zend object or zval
 */
#define php_sample_greeting_from(o) ((php_sample_greeting_t*) ((char*) o - XtOffsetOf(php_sample_greeting_t, std)))
#define php_sample_greeting_fetch(z) php_sample_greeting_from(Z_OBJ_P(z))

/*
 4. A handler function to create the object
*/
zend_object* php_sample_greeting_create(zend_class_entry *ce) {
    php_sample_greeting_t *s = (php_sample_greeting_t*) emalloc(sizeof(php_sample_greeting_t) + zend_object_properties_size(ce));
    zend_object_std_init(&s->std, ce);
    object_properties_init(&s->std, ce);
    s->std.handlers = &php_sample_greeting_handlers;
    return &s->std;
}

/*
 5. A handler function to free the object
*/
void php_sample_greeting_free(zend_object *o) {
    php_sample_greeting_t *s = php_sample_greeting_from(o);
    zval_dtor(&s->greeting);
    zend_object_std_dtor(o);
}

PHP_METHOD(sample_Greeting, __construct) {
    char *name;
    size_t name_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
      Z_PARAM_STRING(name, name_len)
    ZEND_PARSE_PARAMETERS_END();

    /*
      8. Store constructor argument in the struct
    */
    php_sample_greeting_t *sample = php_sample_greeting_fetch(getThis());
    ZVAL_STRINGL(&sample->greeting, name, name_len);
}

PHP_METHOD(sample_Greeting, hello) {
    zval rv, *name, tmp;

    /*
      9. Read the stored name from the struct
    */
    php_sample_greeting_t *sample = php_sample_greeting_fetch(getThis());
    php_printf("Hello %s!", Z_STRVAL(sample->greeting));
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
      ce, SAMPLE_NS, PHP_SAMPLE_CLASS_GREETING_NAME, php_sample_greeting_class_functions
    );
    php_sample_greeting_class_entry = zend_register_internal_class(&ce TSRMLS_CC);
    /*
      6. Set the create handler
     */
    php_sample_greeting_class_entry->create_object = php_sample_greeting_create;

    /*
      7. Copy the default handlers and add the free handler
    */
    memcpy(&php_sample_greeting_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    php_sample_greeting_handlers.offset = XtOffsetOf(php_sample_greeting_t, std);
    php_sample_greeting_handlers.free_obj = php_sample_greeting_free;
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
