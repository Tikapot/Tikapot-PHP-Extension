#ifndef PHP_TIKAPOT_H
#define PHP_TIKAPOT_H 1
#define PHP_TIKAPOT_VERSION "1.0_Beta2"
#define PHP_TIKAPOT_EXTNAME "tikapot"

PHP_FUNCTION(tp_str_begins);
PHP_FUNCTION(tp_str_partition);
PHP_FUNCTION(tp_str_ends);

extern zend_module_entry tikapot_module_entry;
#define phpext_tikapot_ptr &tikapot_module_entry

#endif
