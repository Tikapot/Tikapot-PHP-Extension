#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "php.h"
#include "php_tikapot.h"
#include "tp_string.h"

static function_entry tikapot_functions[] = {
    PHP_FE(tp_str_begins, NULL)
    PHP_FE(tp_str_partition, NULL)
    PHP_FE(tp_str_ends, NULL)
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

PHP_FUNCTION(tp_str_begins)
{
	char *arg_haystack, *arg_needle;
	int haystack_len, needle_len;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &arg_haystack, &haystack_len, &arg_needle, &needle_len) == FAILURE) {
        RETURN_NULL();
	}
	RETURN_BOOL(strcmp(substr(arg_haystack, 0, needle_len), arg_needle) == 0);
}

PHP_FUNCTION(tp_str_partition)
{
	char *arg_haystack, *arg_needle;
	int haystack_len, needle_len;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &arg_haystack, &haystack_len, &arg_needle, &needle_len) == FAILURE) {
        RETURN_NULL();
	}
	
	if (needle_len > haystack_len || needle_len == 0 || haystack_len == 0) {
		array_init(return_value);
		add_next_index_stringl(return_value, arg_haystack, haystack_len, 1);
		add_next_index_stringl(return_value, arg_needle, needle_len, 1);
		add_next_index_stringl(return_value, "", 0, 1);
	}
		
	
	int pos = strpos(arg_haystack, arg_needle);
	if (pos > -1) {		
		char *first_arg = substr(arg_haystack, 0, pos);
		char *second_arg = substr(arg_haystack, pos + needle_len, haystack_len);
		
		array_init(return_value);
		add_next_index_stringl(return_value, first_arg, strlen(first_arg), 1);
		add_next_index_stringl(return_value, arg_needle, needle_len, 1);
		add_next_index_stringl(return_value, second_arg, strlen(second_arg), 1);
		
		return;
	}
	
	array_init(return_value);
	add_next_index_stringl(return_value, arg_haystack, haystack_len, 1);
	add_next_index_stringl(return_value, arg_needle, needle_len, 1);
	add_next_index_stringl(return_value, "", 0, 1);
}

PHP_FUNCTION(tp_str_ends)
{
	char *arg_haystack, *arg_needle;
	int haystack_len, needle_len;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &arg_haystack, &haystack_len, &arg_needle, &needle_len) == FAILURE) {
        RETURN_NULL();
	}
	if (haystack_len < needle_len) {
		RETURN_BOOL(0);
	}
	else if (haystack_len == needle_len) {
		RETURN_BOOL(1);
	}
	else if (haystack_len > needle_len) {
		RETURN_BOOL(strrpos(arg_haystack, arg_needle) == (haystack_len - needle_len));
	}
}

