PHP_ARG_ENABLE(sample,
  [Whether to enable the "sample" extension],
  [  --enable-sample        Enable "sample" extension support])

if test $PHP_SAMPLE != "no"; then
  PHP_SUBST(SAMPLE_SHARED_LIBADD)
  PHP_NEW_EXTENSION(sample, sample.c, $ext_shared)
fi