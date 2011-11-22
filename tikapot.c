#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "php.h"
#include "php_tikapot.h"

static function_entry tikapot_functions[] = {
    PHP_FE(tp_str_partition, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry tikapot_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_TIKAPOT_EXTNAME,
    tikapot_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20010901
    PHP_TIKAPOT_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_TIKAPOT
ZEND_GET_MODULE(tikapot)
#endif

PHP_FUNCTION(tp_str_partition)
{
    RETURN_STRING("", 1);
}
