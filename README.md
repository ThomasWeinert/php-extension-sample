# PHP Extension Feature Samples

See the `main` branch for general information about this repository.

This branch shows a single function without arguments or return value.

## Argument Information

PHP needs argument information for the function. Since PHP 8 you can define 
the stubs in PHP and generate the argument information from them.

The `sample.stub.php` is the stub for this example. To generate/update the
argument information call `gen_stubs.php` from the main php repository.

```shell
$ ../php-src/build/gen_stubs.php
```

If all goes well this will result in a `sample_arginfo.h` file that will be included
in `sample.c`.