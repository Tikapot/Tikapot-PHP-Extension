PHP_ARG_ENABLE(tikapot, whether to enable advanced Tikapot support, [ --enable-tikapot   Enable Advanced Tikapot support ])

if test "$PHP_TIKAPOT" = "yes"; then
	AC_DEFINE(HAVE_TIKAPOT, 1, [Whether you have advanced Tikapot support])
	PHP_NEW_EXTENSION(tikapot, tikapot.c, $ext_shared)
fi
